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
/*!\file    rrlib/design_patterns/command/tFirstParameterBinder.h
 *
 * \author  Tobias Foehst
 *
 * \date    2010-10-24
 *
 * \brief   Contains tFirstParameterBinder
 *
 * \b tFirstParameterBinder
 *
 */
//----------------------------------------------------------------------
#ifndef __rrlib__design_patterns__command__tFirstParameterBinder_h__
#define __rrlib__design_patterns__command__tFirstParameterBinder_h__

#include "rrlib/design_patterns/command/tFunctorHandlerBase.h"
//----------------------------------------------------------------------
// External includes (system with <>, local with "")
//----------------------------------------------------------------------

//----------------------------------------------------------------------
// Internal includes with ""
//----------------------------------------------------------------------

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
template <typename TReturn, typename TFirstParameter, typename ... TParameterRest>
class tFirstParameterBinder : public tFunctorHandlerBase<TReturn, TParameterRest...>
{

//----------------------------------------------------------------------
// Public methods and typedefs
//----------------------------------------------------------------------
public:

  tFirstParameterBinder(const tFunctor<TReturn, TFirstParameter, TParameterRest...> &functor, TFirstParameter bound_parameter)
    : functor(functor),
      bound_parameter(bound_parameter)
  {}

  TReturn operator()(TParameterRest... parameters)
  {
    return this->functor(bound_parameter, parameters...);
  }

//----------------------------------------------------------------------
// Private fields and methods
//----------------------------------------------------------------------
private:

  tFunctor<TReturn, TFirstParameter, TParameterRest...> functor;
  TFirstParameter bound_parameter;
};

//----------------------------------------------------------------------
// End of namespace declaration
//----------------------------------------------------------------------
}
}

#endif
