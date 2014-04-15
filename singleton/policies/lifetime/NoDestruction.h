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
/*!\file    rrlib/design_patterns/singleton/policies/lifetime/NoDestruction.h
 *
 * \author  Tobias Foehst
 *
 * \date    2010-10-26
 *
 * \brief   Contains NoDestruction
 *
 * \b NoDestruction
 *
 */
//----------------------------------------------------------------------
#ifndef __rrlib__design_patterns__singleton__policies__lifetime__NoDestruction_h__
#define __rrlib__design_patterns__singleton__policies__lifetime__NoDestruction_h__

//----------------------------------------------------------------------
// External includes (system with <>, local with "")
//----------------------------------------------------------------------
#include <stdexcept>

#include "rrlib/util/tTraceableException.h"

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
struct NoDestruction
{
  static void ScheduleDestruction(T *, void (*function)())
  {}
  static void OnDeadReference()
  {
    throw util::tTraceableException<std::logic_error>("Dead reference to a NoDestruction singleton detected!");
  }
};

//----------------------------------------------------------------------
// End of namespace declaration
//----------------------------------------------------------------------
}
}
}

#endif
