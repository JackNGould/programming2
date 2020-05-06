/*
 * @project: shapes - inheritance and exception handling
 * @file: Circle.cpp
 * @author: Jack Gould
 * @brief: Implementation file for Circle class. Defines member methods. Inherits from Shape class.
 * @date: 02-26-2020
 */
#include "Circle.h"

Circle::Circle(double r)
{
	m_radius = r;
}

Circle::~Circle()
{
	m_radius = 0;
}

double Circle::area() const
{
	double rSquared = m_radius*m_radius;
	return (rSquared*piTo18);	
}

std::string Circle::shapeName() const
{
	return ("Circle");
}

