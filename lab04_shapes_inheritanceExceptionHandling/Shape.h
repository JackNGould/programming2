/*
 * @project: shapes - inheritance and exception handling
 * @file: Shape.h
 * @author: Jack Gould
 * @brief: Header file for Shapeclass. Lists member methods. Shape class is actually an interface, and lists out the methods that must be defined by inheriting shapes. It will be inherited from by subclasses Circle, Rectangle, and Triangle in this lab.
 * @date: 02-26-2020
 */
#ifndef SHAPE_H
#define SHAPE_H

#include <string>
class Shape
{
   public:

     //returns shape area
  	 virtual double area() const = 0;

     //returns shape name
  	 virtual std::string shapeName() const = 0;

     //destructor
  	 virtual ~Shape() {}
};
#endif
