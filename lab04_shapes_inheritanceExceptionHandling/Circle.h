/*
 * @project: shapes - inheritance and exception handling
 * @file: Circle.h
 * @author: Jack Gould
 * @brief: Header file for Circle class. Lists member methods. Inherits from Shape class.
 * @date: 02-26-2020
 */
#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h" 

class Circle : public Shape
{
	public:
   /* Constructor
    * @pre
    * @param double r - radius of the circle to be created
    * @post - A new circle is created
    */
		Circle(double r);

   /*
    * @pre
    * @param
    * @post - the area of this circle object is returned
    */
		double area() const;

   /*
    * @pre
    * @param
    * @post - the name of this circle object is returned. "Circle"
    */
		std::string shapeName() const;

   /* Destructor
    * @pre
    * @post - This circle object is destroyed
    */
		~Circle();

	private:
    //private const double to use as a value for pi
		const double piTo18 = 3.141592653589793238;

    //private member variable to store radius
		double m_radius;

};
#endif
