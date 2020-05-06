/*
 * @project: MaxHeap - Hospital queue simulation
 * @file: patient.cpp
 * @author: Jack Gould
 * @brief: Implementation file for patient class. Defines member methods. These objects will fill the maxHeap, so that the heap can compare them for feeding into a hospital queue. Comparison operators overloaded for compatibility with maxHeap.
 * @date: 04-17-2020
 */

#include "patient.h"

patient::patient()
{

  m_fName = "";
  m_lName = "";
  m_age = 0;
  m_condition = "";
  m_severity = 0;
  m_arrivalOrder = 0;

}

patient::patient(std::string fName, std::string lName, int age, std::string condition, int severity, int arrivalOrder)
{
  m_fName = fName;
  m_lName = lName;
  m_age = age;
  m_condition = condition;
  m_severity = severity;
  m_arrivalOrder = arrivalOrder;
}

/*
patient::~patient()
{
  
}
*/

patient& patient::operator=(const patient& rhs)
{
  m_fName = rhs.m_fName;
  m_lName = rhs.m_lName;
  m_age = rhs.m_age;
  m_condition = rhs.m_condition;
  m_severity = rhs.m_severity;
  m_arrivalOrder = rhs.m_arrivalOrder;
  return *this;
}


bool patient::operator>(const patient& rhs)
{
  if(m_severity > rhs.m_severity)
  {
    return true;
  }
  else if(m_severity == rhs.m_severity)
  {
    if(m_age > rhs.m_age)
    {
      return true;
    }
    else if(m_age == rhs.m_age)
    {
      if(m_arrivalOrder < rhs.m_arrivalOrder)
      {
        return true;
      }
      else
      {
        return false;
      }
    }
    else
    {
      return false;
    }
  }
  else
  {
    return false;
  }
}

std::string patient::getLast() const
{
  return m_lName;
}

std::string patient::getFirst() const
{
  return m_fName;
}
std::string patient::getCondition() const
{
  return m_condition;
}
int patient::getSeverity() const
{
  return m_severity;
}

int patient::getAge() const
{
  return m_age;
}

