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
/*!\file    rrlib/design_patterns/singleton/tSingletonHolder.h
 *
 * \author  Tobias Foehst
 *
 * \date    2010-10-26
 *
 * \brief   Contains tSingletonHolder
 *
 * \b tSingletonHolder
 *
 */
//----------------------------------------------------------------------
#ifndef __rrlib__design_patterns__singleton__tSingletonHolder_h__
#define __rrlib__design_patterns__singleton__tSingletonHolder_h__

//----------------------------------------------------------------------
// External includes (system with <>, local with "")
//----------------------------------------------------------------------
#include "rrlib/util/tNoncopyable.h"
#include <mutex>

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
typename T,
         template <typename> class TLifetimePolicy = singleton::DefaultLifetime,
         template <typename> class TCreationPolicy = singleton::CreateUsingNew
         >
class tSingletonHolder : private rrlib::util::tNoncopyable
{

//----------------------------------------------------------------------
// Public methods and typedefs
//----------------------------------------------------------------------
public:

  static T &Instance()
  {
    if (!tSingletonHolder::InstancePointer())
    {
      tSingletonHolder::CreateInstance();
    }
    return *tSingletonHolder::InstancePointer();
  }

//----------------------------------------------------------------------
// Private fields and methods
//----------------------------------------------------------------------
private:

  tSingletonHolder();

  static void CreateInstance()
  {
    static std::mutex mutex;
    std::unique_lock<std::mutex> lock(mutex);

    if (!tSingletonHolder::InstancePointer())
    {
      if (tSingletonHolder::Destroyed())
      {
        TLifetimePolicy<T>::OnDeadReference();
        tSingletonHolder::Destroyed() = false;
      }
      tSingletonHolder::InstancePointer() = TCreationPolicy<T>::Create();
      TLifetimePolicy<T>::ScheduleDestruction(tSingletonHolder::InstancePointer(), &tSingletonHolder::DestroyInstance);
    }
  }

  static void DestroyInstance()
  {
    assert(!tSingletonHolder::Destroyed());
    TCreationPolicy<T>::Destroy(tSingletonHolder::InstancePointer());
    tSingletonHolder::InstancePointer() = 0;
    tSingletonHolder::Destroyed() = true;
  }

  static T *&InstancePointer()
  {
    static T *instance = 0;
    return instance;
  }

  static bool &Destroyed()
  {
    static bool destroyed = false;
    return destroyed;
  }

};

//----------------------------------------------------------------------
// End of namespace declaration
//----------------------------------------------------------------------
}
}

#endif
