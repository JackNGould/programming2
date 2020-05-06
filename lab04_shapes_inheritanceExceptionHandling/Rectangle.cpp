/*
 * @project: shapes - inheritance and exception handling
 * @file: Rectangle.cpp
 * @author: Jack Gould
 * @brief: Implementation file for Rectangle class. Defines member methods. Inherits from Shape class.
 * @date: 02-26-2020
 */

#include "Rectangle.h"

Rectangle::Rectangle(double l, double w)
{
	m_length = l;
	m_width = w;
}

Rectangle::~Rectangle()
{
	m_length = 0;
	m_width = 0;
}

double Rectangle::area() const
{
	return (m_length*m_width);	
}

std::string Rectangle::shapeName() const
{
	return ("Rectangle");
}
