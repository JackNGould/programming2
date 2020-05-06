/*
 * @project: shapes - inheritance and exception handling
 * @file: ShapeContainer.cpp
 * @author: Jack Gould
 * @brief: Implementation file for ShapeContainer class. Defines member methods. ShapeContainers hold an array of shapes and have member functions controlling operations on the container.
 * @date: 02-26-2020
 */

#include "ShapeContainer.h"

ShapeContainer::ShapeContainer(int size)
{
	m_size = size;
	m_arrayOfShapes = new Shape*[size];
	for(int i=0;i<size;++i)
	{
		m_arrayOfShapes[i] = nullptr;
	}

}

ShapeContainer::~ShapeContainer()
{
	for(int i=0;i<m_size;++i)
	{
	  if(m_arrayOfShapes[i] != nullptr)
	  {
		  delete m_arrayOfShapes[i];
	  }
	}
	delete[] m_arrayOfShapes;
}

double ShapeContainer::area(int index) const
{
	if(index>=0 && index<m_size)
	{
		if(m_arrayOfShapes[index] != nullptr)
		{
			double a = m_arrayOfShapes[index]->area();
			return a;
		}
		else
		{
			throw(std::runtime_error("Cannot return shape area, shape index has nullptr"));
		}
	}
	else throw(std::runtime_error("Cannot return shape area, index is out of range"));
	

}

std::string ShapeContainer::shapeName(int index) 
{
	if(index>=0 && index<m_size)
	{
		if(m_arrayOfShapes[index] != nullptr)
		{
			std::string name = m_arrayOfShapes[index]->shapeName();
			return name;
		}
		else
		{
			throw(std::runtime_error("Cannot return shape Name, shape index has nullptr"));
		}
	}
	else throw(std::runtime_error("Cannot return shape name, index is out of range"));
}

void ShapeContainer::add(Shape* shapePtr, int index)
{
	if(index>=0 && index<m_size)
	{
		if(shapePtr != nullptr)
		{
			m_arrayOfShapes[index] = shapePtr;
		}
		else
		{
			throw(std::runtime_error("Cannot add shape to container, provided shapePtr has nullptr"));
		}
	}
	else throw(std::runtime_error("Cannot add shape to container, index is out of range"));
}

void ShapeContainer::remove(int index)
{
	if(index>=0 && index<m_size)
	{
		if(m_arrayOfShapes[index] != nullptr)
		{
			delete m_arrayOfShapes[index];
      m_arrayOfShapes[index] = nullptr;
		}
		else
		{
			throw(std::runtime_error("Cannot remove from container. Index already has nullptr"));
		}
	}
	else throw(std::runtime_error("Cannot remove from container. Index is out of range"));

}


