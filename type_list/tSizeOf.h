//
// You received this file as part of RRLib
// Robotics Research Library
//
// Copyright (C) AG Robotersysteme TU Kaiserslautern
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
/*!\file    tSizeOf.h
 *
 * \author  Tobias Foehst
 *
 * \date    2011-03-25
 *
 * \brief Contains tSizeOf
 *
 * \b tSizeOf
 *
 */
//----------------------------------------------------------------------
#ifndef __rrlib__util__type_list__include_guard__
#error Invalid include directive. Try #include "rrlib/util/tTypeList.h" instead.
#endif

#ifndef __rrlib__util__type_lists__tSizeOf_h__
#define __rrlib__util__type_lists__tSizeOf_h__

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
namespace util
{
namespace type_list
{

//----------------------------------------------------------------------
// Forward declarations / typedefs / enums
//----------------------------------------------------------------------
template <typename TList> class tSizeOf;

//----------------------------------------------------------------------
// Class declaration
//----------------------------------------------------------------------
//!
/*!
 *
 */
template <>
struct tSizeOf<tEmptyList>
{
  enum { cVALUE = 0 };
};

template <typename THead, typename ... TTail>
struct tSizeOf<tTypeList<THead, TTail...>>
{
  enum { cVALUE = tSizeOf<typename tTypeList<THead, TTail...>::tTail>::cVALUE + 1 };
};


//----------------------------------------------------------------------
// End of namespace declaration
//----------------------------------------------------------------------
}
}
}

#endif
