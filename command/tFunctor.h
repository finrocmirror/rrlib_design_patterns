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
/*!\file    rrlib/design_patterns/command/tFunctor.h
 *
 * \author  Tobias Foehst
 *
 * \date    2010-10-24
 *
 * \brief   Contains tFunctor
 *
 * \b tFunctor
 *
 */
//----------------------------------------------------------------------
#ifndef __rrlib__design_patterns__command__tFunctor_h__
#define __rrlib__design_patterns__command__tFunctor_h__

//----------------------------------------------------------------------
// External includes (system with <>, local with "")
//----------------------------------------------------------------------
#include <memory>

//----------------------------------------------------------------------
// Internal includes with ""
//----------------------------------------------------------------------
#include "rrlib/design_patterns/command/tFunctorHandlerBase.h"
#include "rrlib/design_patterns/command/tFunctorHandler.h"
#include "rrlib/design_patterns/command/tMemberFunctionHandler.h"

//----------------------------------------------------------------------
// Debugging
//----------------------------------------------------------------------

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
template <typename TReturn, typename ... TParameters>
class tFunctor
{

//----------------------------------------------------------------------
// Public methods and typedefs
//----------------------------------------------------------------------
public:

  tFunctor(const tFunctor &other)
    : handler(other.handler)
  {}

  explicit tFunctor(std::shared_ptr<tFunctorHandlerBase<TReturn, TParameters...>> handler)
    : handler(handler)
  {}

  template <typename TFunctor>
  tFunctor(const TFunctor &functor)
    : handler(new tFunctorHandler<TFunctor, TReturn, TParameters...>(functor))
  {}

  template <typename TObject, typename TFunction>
  tFunctor(TObject &object, const TFunction &function)
    : handler(new tMemberFunctionHandler<TObject, TFunction, TReturn, TParameters...>(object, function))
  {}

  TReturn operator()(TParameters... parameters) const
  {
    return (*this->handler)(parameters...);
  }

//----------------------------------------------------------------------
// Private fields and methods
//----------------------------------------------------------------------
private:

  std::shared_ptr<tFunctorHandlerBase<TReturn, TParameters...>> handler;

//  tFunctor();

};

//----------------------------------------------------------------------
// End of namespace declaration
//----------------------------------------------------------------------
}
}

#endif
