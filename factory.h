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
/*!\file    factory.h
 *
 * \author  Tobias Foehst
 *
 * \date    2011-01-07
 *
 * \brief Contains factory
 *
 * \b factory
 *
 */
//----------------------------------------------------------------------
#ifndef __rrlib__design_patterns__factory_h__
#define __rrlib__design_patterns__factory_h__

//----------------------------------------------------------------------
// External includes (system with <>, local with "")
//----------------------------------------------------------------------

//----------------------------------------------------------------------
// Internal includes with ""
//----------------------------------------------------------------------
#include "rrlib/design_patterns/factory/policies/error/ThrowException.h"
#include "rrlib/design_patterns/factory/policies/error/ReturnNullptr.h"

#include "rrlib/design_patterns/factory/functions.h"
#include "rrlib/design_patterns/factory/tFactory.h"
#include "rrlib/design_patterns/factory/tCloneFactory.h"

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
// Function declaration
//----------------------------------------------------------------------

//----------------------------------------------------------------------
// End of namespace declaration
//----------------------------------------------------------------------
}
}

#endif
