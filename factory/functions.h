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
/*!\file    rrlib/design_patterns/factory/functions.h
 *
 * \author  Tobias Foehst
 *
 * \date    2011-08-18
 *
 * \brief
 *
 * \b
 *
 */
//----------------------------------------------------------------------
#ifndef __rrlib__design_patterns__factory__functions_h__
#define __rrlib__design_patterns__factory__functions_h__

//----------------------------------------------------------------------
// External includes (system with <>, local with "")
//----------------------------------------------------------------------

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
namespace factory
{

//----------------------------------------------------------------------
// Forward declarations / typedefs / enums
//----------------------------------------------------------------------

//----------------------------------------------------------------------
// Function declaration
//----------------------------------------------------------------------
template <typename TProduct>
struct DefaultNewCreator
{
  template <typename ... TArguments>
  TProduct *operator()(const TArguments &... arguments) const
  {
    return new TProduct(arguments...);
  }
};

template <typename TProduct>
TProduct *DefaultCopyCloner(const TProduct &source)
{
  return new TProduct(source);
}

//----------------------------------------------------------------------
// End of namespace declaration
//----------------------------------------------------------------------
}
}
}

#endif
