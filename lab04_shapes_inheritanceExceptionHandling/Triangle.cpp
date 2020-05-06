/*
 * @project: shapes - inheritance and exception handling
 * @file: Triangle.cpp
 * @author: Jack Gould
 * @brief: Implementation file for Triangle class. Defines member methods. Inherits from Shape class.
 * @date: 02-26-2020
 */
#include "Triangle.h"

Triangle::Triangle(double b, double h)
{
	m_base = b;
	m_height = h;
}

Triangle::~Triangle()
{
	m_base = 0;
	m_height = 0;
}

double Triangle::area() const
{
	return ((m_base*m_height)/2);	
}

std::string Triangle::shapeName() const
{
	return ("Triangle");
}
