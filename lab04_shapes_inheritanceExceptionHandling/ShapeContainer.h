/*
 * @project: shapes - inheritance and exception handling
 * @file: ShapeContainer.h
 * @author: Jack Gould
 * @brief: Header file for ShapeContainer class. Lists member methods. ShapeContainers hold an array of shapes and have member functions controlling operations on the container.
 * @date: 02-26-2020
 */

#ifndef SHAPE_CONTAINER_H
#define SHAPE_CONTAINER_H

#include "Shape.h"
#include <stdexcept>

class ShapeContainer
{
   public:
   /* Constructor
    * @pre
    * @param int size. The pre set size capacity of this shape container to be created
    * @post - A new shape container is created
    */
  	 ShapeContainer(int size); //initialize pointers in m_arrayOfShapes to nullptr
   /* Destructor
    * @pre
    * @post - This shape container is destroyed
    */
  	 ~ShapeContainer();
   /*
    * @pre
    * @param int index - index inside container
    * @post - the area of the shape stored at index is returned
    * @throws a std::runtime_error if index is invalid, meaning out of range OR index has nullptr 
    */
  	 double area(int index) const;
     
    /*
     * @pre 
     * @param int index - index inside container
     * @return - std::string - returns shape name at given index
     * @throws std::runtime_error if index is invalid, meaning out of range OR index has nullptr
     */
     std::string shapeName(int index); //throws a std::runtime_error if index is invalid, meaning out of range OR index has nullptr

   /*
    * @pre
    * @param Shape* shapePtr - the shape to be added to the container.
    * @param int index - the index to insert the shape into
    * @post - the shape is added to the container at the provided index
    * @throws a std::runtime_error if index is invalid, OR  shapePtr has nullptr 
    */
  	 void add(Shape* shapePtr, int index); //throws a std::runtime_error if index is invalid OR if shapePtr is nullptr
   /*
    * @pre
    * @param int index - the index to delete the shape at
    * @post - the shape at the provided index is removed from the container
    * @throws a std::runtime_error if index is invalid, OR there is no object to delete
    */
  	 void remove(int index); //throws a std::runtime_error if the index is invalid OR there is no object to delete
   private:
  
    //private array storing shape pointers.  
  	 Shape** m_arrayOfShapes;

     //private variable that stores the size of the container. Set at construction.
  	 int m_size;
};
#endif


