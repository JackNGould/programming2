/*
 * @project: shapes - inheritance and exception handling
 * @file: Rectangle.h
 * @author: Jack Gould
 * @brief: Header file for Rectangle class. Lists member methods. Inherits from Shape class.
 * @date: 02-26-2020
 */
#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape
{
	public:
   /* Constructor
    * @pre
    * @param double l - length of rectangle to be created
    * @param double w - width of rectangle to be created
    * @post - A new rectangle is created
    */
		Rectangle(double l, double w );
   /*
    * @pre
    * @param
    * @post - the area of this rectangle object is returned
    */
		double area() const;

   /*
    * @pre
    * @param
    * @post - the name of this Rectangle object is returned. "Rectangle"
    */
		std::string shapeName() const;

   /* Destructor
    * @pre
    * @post - This rectangle object is destroyed
    */
		~Rectangle();

	private:
    //private member variable storing rectangle length
		double m_length;
    //private member variable storing rectangle width
		double m_width;


};
#endif


