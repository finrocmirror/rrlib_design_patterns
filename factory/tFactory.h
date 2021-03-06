//
// You received this file as part of RRLib
// Robotics Research Library
//
// Copyright (C) Finroc GbR (finroc.org)
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this program; if not, write to the Free Software Foundation, Inc.,
// 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
//
//----------------------------------------------------------------------
/*!\file    rrlib/design_patterns/factory/tFactory.h
 *
 * \author  Tobias Foehst
 *
 * \date    2011-01-07
 *
 * \brief   Contains tFactory
 *
 * \b tFactory
 *
 */
//----------------------------------------------------------------------
#ifndef __rrlib__design_patterns__factory__tFactory_h__
#define __rrlib__design_patterns__factory__tFactory_h__

//----------------------------------------------------------------------
// External includes (system with <>, local with "")
//----------------------------------------------------------------------
#include <map>
#include <functional>

//----------------------------------------------------------------------
// Internal includes with ""
//----------------------------------------------------------------------

//----------------------------------------------------------------------
// Debugging
//----------------------------------------------------------------------
#include <cassert>

//----------------------------------------------------------------------
// Namespace declaration
//----------------------------------------------------------------------
namespace rrlib
{
namespace design_patterns
{

//----------------------------------------------------------------------
// Forward declarations / typedefs / enums
//----------------------------------------------------------------------

//----------------------------------------------------------------------
// Class declaration
//----------------------------------------------------------------------
//!
/*!
 *
 */
template <
typename TAbstractProduct,
         typename TIdentifier,
         typename TProductCreator = std::function<TAbstractProduct *()>,
         template <typename, typename> class TUnknownKeyPolicy = factory::ThrowException
         >
class tFactory
{

//----------------------------------------------------------------------
// Public methods and typedefs
//----------------------------------------------------------------------
public:

  virtual ~tFactory()
  {};

  const bool Register(const TIdentifier &id, const TProductCreator &product_creator)
  {
    return this->id_to_creator_map.insert(std::make_pair(id, product_creator)).second;
  }

  template <typename TProduct>
  const bool Register(const TIdentifier &id)
  {
    return this->Register(id, factory::DefaultNewCreator<TProduct>());
  }

  const bool Unregister(const TIdentifier &id)
  {
    return this->id_to_creator_map.erase(id) == 1;
  }

  template <typename ... TArguments>
  TAbstractProduct *Create(const TIdentifier &id, const TArguments &... arguments) const
  {
    typename std::map<TIdentifier, TProductCreator>::const_iterator it = this->id_to_creator_map.find(id);
    if (it != this->id_to_creator_map.end())
    {
      return (it->second)(arguments...);
    }
    return TUnknownKeyPolicy<TAbstractProduct, TIdentifier>::OnUnknownType(id);
  }

//----------------------------------------------------------------------
// Private fields and methods
//----------------------------------------------------------------------
private:

  std::map<TIdentifier, TProductCreator> id_to_creator_map;

};

//----------------------------------------------------------------------
// End of namespace declaration
//----------------------------------------------------------------------
}
}

#endif
