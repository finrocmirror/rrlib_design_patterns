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
/*!\file    rrlib/design_patterns/tests/factory_pattern.cpp
 *
 * \author  Tobias Foehst
 *
 * \date    2010-10-26
 *
 */
//----------------------------------------------------------------------

//----------------------------------------------------------------------
// External includes (system with <>, local with "")
//----------------------------------------------------------------------
#include "rrlib/util/tUnitTestSuite.h"

#include <string>

#include "rrlib/design_patterns/factory.h"

//----------------------------------------------------------------------
// Internal includes with ""
//----------------------------------------------------------------------

//----------------------------------------------------------------------
// Debugging
//----------------------------------------------------------------------
#include <cassert>

//----------------------------------------------------------------------
// Namespace usage
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
// Const values
//----------------------------------------------------------------------

//----------------------------------------------------------------------
// Implementation
//----------------------------------------------------------------------
class FactoryPattern : public util::tUnitTestSuite
{
  RRLIB_UNIT_TESTS_BEGIN_SUITE(FactoryPattern);
  RRLIB_UNIT_TESTS_ADD_TEST(Factory);
  RRLIB_UNIT_TESTS_END_SUITE;

private:

  struct Base
  {
    virtual std::string Name() = 0;
  };

  struct A : public Base
  {
    virtual std::string Name()
    {
      return "A";
    }
  };

  struct B : public Base
  {
    virtual std::string Name()
    {
      return "B";
    }
  };

  void Factory()
  {
    tFactory<Base, std::string> factory;

    RRLIB_UNIT_TESTS_ASSERT(factory.Register<A>("A"));
    RRLIB_UNIT_TESTS_ASSERT(!factory.Register<A>("A"));
    RRLIB_UNIT_TESTS_ASSERT(!factory.Register<B>("A"));
    RRLIB_UNIT_TESTS_ASSERT(factory.Register<B>("B"));

    Base *a1 = factory.Create("A");
    Base *a2 = factory.Create("A");
    Base *b = factory.Create("B");

    RRLIB_UNIT_TESTS_EQUALITY(std::string("A"), a1->Name());
    RRLIB_UNIT_TESTS_EQUALITY(std::string("A"), a2->Name());
    RRLIB_UNIT_TESTS_EQUALITY(std::string("B"), b->Name());

    RRLIB_UNIT_TESTS_ASSERT(&a1 != &a2);

    RRLIB_UNIT_TESTS_EXCEPTION(factory.Create("C"), std::runtime_error);

    factory.Unregister("B");
    RRLIB_UNIT_TESTS_EXCEPTION(factory.Create("B"), std::runtime_error);
  }
};

RRLIB_UNIT_TESTS_REGISTER_SUITE(FactoryPattern);

//----------------------------------------------------------------------
// End of namespace declaration
//----------------------------------------------------------------------
}
}
