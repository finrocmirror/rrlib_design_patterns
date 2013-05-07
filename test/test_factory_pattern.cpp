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
/*!\file    rrlib/design_patterns/test/test_factory_pattern.cpp
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
#include <cstdlib>
#include <string>
#include <iostream>

//----------------------------------------------------------------------
// Internal includes with ""
//----------------------------------------------------------------------
#include "rrlib/design_patterns/factory.h"
#include "rrlib/design_patterns/singleton.h"

//----------------------------------------------------------------------
// Debugging
//----------------------------------------------------------------------

//----------------------------------------------------------------------
// Namespace usage
//----------------------------------------------------------------------
using namespace rrlib::design_patterns;

//----------------------------------------------------------------------
// Forward declarations / typedefs / enums
//----------------------------------------------------------------------

//----------------------------------------------------------------------
// Const values
//----------------------------------------------------------------------

//----------------------------------------------------------------------
// Implementation
//----------------------------------------------------------------------


struct tShape
{
  tShape() {}
  virtual ~tShape() {}
};

struct tLine : public tShape
{
  tLine()
  {
    std::cout << "Creating tLine" << std::endl;
  }
};

struct tRectangle : public tShape
{
  tRectangle()
  {
    std::cout << "Creating tRectangle" << std::endl;
  }
};

struct tCircle : public tShape
{
  tCircle()
  {
    std::cout << "Creating tCircle" << std::endl;
  }
};

struct tEllipse : public tShape
{
  tEllipse()
  {
    std::cout << "Creating tEllipse" << std::endl;
  }
};


tLine *CloneLine(const tShape &)
{
  std::cout << "Cloning a line" << std::endl;
  return 0;
}
tRectangle *CloneRectangle(const tShape &)
{
  std::cout << "Cloning a rectangle" << std::endl;
  return 0;
}
tCircle *CloneCircle(const tShape &)
{
  std::cout << "Cloning a circle" << std::endl;
  return 0;
}

typedef tSingletonHolder<tFactory<tShape, std::string>> tShapeFactory;
typedef tSingletonHolder<tCloneFactory<tShape>> tShapeCloneFactory;

int main(int argc, char **argv)
{
  std::cout << "Testing factory" << std::endl;

  tShapeFactory::Instance().Register<tLine>("line");
  tShapeFactory::Instance().Register<tRectangle>("line");
  tShapeFactory::Instance().Register<tRectangle>("rectangle");
  tShapeFactory::Instance().Register<tCircle>("circle");
  tShapeFactory::Instance().Register<tEllipse>("ellipse");

  tShape *line = tShapeFactory::Instance().Create("line");
  tShape *rectangle = tShapeFactory::Instance().Create("rectangle");
  tShape *circle = tShapeFactory::Instance().Create("circle");
  tShape *ellipse = tShapeFactory::Instance().Create("ellipse");

  std::cout << "Testing clone factory" << std::endl;

  tShapeCloneFactory::Instance().Register(*line, &CloneLine);
  tShapeCloneFactory::Instance().Register(rectangle, &CloneRectangle);
  tShapeCloneFactory::Instance().Register(*circle, &CloneCircle);

  tShapeCloneFactory::Instance().Create(*line);
  tShapeCloneFactory::Instance().Create(*rectangle);
  tShapeCloneFactory::Instance().Create(*circle);
//  tShapeCloneFactory::Instance().Create(*ellipse);

  tShapeCloneFactory::Instance().Create(line);
  tShapeCloneFactory::Instance().Create(rectangle);
  tShapeCloneFactory::Instance().Create(circle);




//  tShape *foo = tShapeFactory::GetInstance().Create("foo");


  delete line;
  delete rectangle;
  delete circle;
  delete ellipse;

  return EXIT_SUCCESS;
}
