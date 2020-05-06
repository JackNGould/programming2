/*
 * @project: shapes - inheritance and exception handling
 * @file: Triangle.h
 * @author: Jack Gould
 * @brief: Header file for Triangle class. Lists member methods. Inherits from Shape class.
 * @date: 02-26-2020
 */
#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"

class Triangle : public Shape
{
	public:

   /* Constructor
    * @pre
    * @param double b - base of triangle to be created
    * @param double h - height of triangle to be created
    * @post - A new triangle is created
    */
		Triangle(double b, double h);
		double area() const;
		std::string shapeName() const;
		~Triangle();

	private:
		double m_base;
		double m_height;


};
#endif

