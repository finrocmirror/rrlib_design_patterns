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
/*!\file    rrlib/design_patterns/singleton/policies/lifetime/Longevity.h
 *
 * \author  Tobias Foehst
 *
 * \date    2012-01-23
 *
 * \brief   Contains Longevity
 *
 * \b Longevity
 *
 */
//----------------------------------------------------------------------
#ifndef __rrlib__design_patterns__singleton__policies__lifetime__Longevity_h__
#define __rrlib__design_patterns__singleton__policies__lifetime__Longevity_h__

//----------------------------------------------------------------------
// External includes (system with <>, local with "")
//----------------------------------------------------------------------
#include <stdexcept>

#include "rrlib/util/tTraceableException.h"

//----------------------------------------------------------------------
// Internal includes with ""
//----------------------------------------------------------------------
#include "rrlib/design_patterns/singleton/tLifetimeTracker.h"

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
namespace singleton
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
template <typename T>
struct Longevity
{
  static void ScheduleDestruction(T *object, void (*function)())
  {
    SetLongevity(GetLongevity(object), function);
  }
  static void OnDeadReference()
  {
    throw util::tTraceableException<std::logic_error>("Dead reference detected!");
  }
};

//----------------------------------------------------------------------
// End of namespace declaration
//----------------------------------------------------------------------
}
}
}

#endif
