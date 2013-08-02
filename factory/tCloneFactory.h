//
// You received this file as part of RRLib
// Robotics Research Library
//
// Copyright (C) Finroc GbR (finroc.org)
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
//
//----------------------------------------------------------------------
/*!\file    rrlib/design_patterns/factory/tCloneFactory.h
 *
 * \author  Tobias Foehst
 *
 * \date    2011-01-07
 *
 * \brief   Contains tCloneFactory
 *
 * \b tCloneFactory
 *
 */
//----------------------------------------------------------------------
#ifndef __rrlib__design_patterns__factory__tCloneFactory_h__
#define __rrlib__design_patterns__factory__tCloneFactory_h__

#include "rrlib/design_patterns/factory/tFactory.h"

//----------------------------------------------------------------------
// External includes (system with <>, local with "")
//----------------------------------------------------------------------
#include <typeinfo>

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

namespace
{

//!
/*!
 *
 */
template <typename TAbstractProduct>
class tTypeInfoWrapper
{
  const std::type_info &type;
public:
  tTypeInfoWrapper(const TAbstractProduct &type) : type(typeid(type)) {}
  tTypeInfoWrapper(const TAbstractProduct *type) : type(typeid(*type)) {}
  const bool operator < (const tTypeInfoWrapper &other) const
  {
    return other.type.before(this->type);
  }
};

}


//!
/*!
 *
 */
template <
typename TAbstractProduct,
         template <typename TAbstractProduct, typename TIdentifier> class TUnknownKeyPolicy = factory::ThrowException
         >
class tCloneFactory : public tFactory<TAbstractProduct, tTypeInfoWrapper<TAbstractProduct>, std::function<TAbstractProduct *(const TAbstractProduct &)>, TUnknownKeyPolicy>
{

  typedef design_patterns::tFactory<TAbstractProduct, tTypeInfoWrapper<TAbstractProduct>, std::function<TAbstractProduct *(const TAbstractProduct &)>, TUnknownKeyPolicy> tFactory;
  typedef tTypeInfoWrapper<TAbstractProduct> tIdentifier;

//----------------------------------------------------------------------
// Public methods and typedefs
//----------------------------------------------------------------------
public:

  using tFactory::Register;

  template <typename TProduct>
  const bool Register(const tIdentifier &id)
  {
    return this->Register(id, &factory::DefaultCopyCloner<TProduct>);
  }

  TAbstractProduct *Create(const TAbstractProduct &model) const
  {
    return tFactory::Create(tIdentifier(model), model);
  }

};

//----------------------------------------------------------------------
// End of namespace declaration
//----------------------------------------------------------------------
}
}

#endif
