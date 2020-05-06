/*
 * @project: shapes - inheritance and exception handling.
 * @file: Queue.cpp
 * @author: Jack Gould
 * @brief: Implementation file for templated Queue class. Defines member methods. Templated, Node based implementation. A single Queue<std::string> is used in this programs executive class to store the input file by lines.
 * @date: 02-26-2020
 */
#include <stdexcept>

template <typename T>
T Queue<T>::peek() const
{
	if(m_front != nullptr && m_length>0)
	{
		return(m_front->getEntry());
	}
	else
	{
		throw(std::runtime_error("Peek attempted on an empty queue, nobody in line!\n"));
	}
}

template <typename T>
Queue<T>::Queue()
{
  m_back = nullptr;
	m_front = nullptr;
	m_length = 0;
}

template <typename T>
Queue<T>::~Queue()
{
	this->clear();
}

template <typename T>
void Queue<T>::operator=(const Queue<T>& rhs)
{
      while(this->m_front != nullptr)
      {
	this->pop();
      }
      Node<T>* traverseNew = nullptr;
      Node<T>* traverseRHS = rhs.m_front;
	while(traverseRHS != nullptr)
	{
		Node<T>* temp = new Node<T>(traverseRHS->getEntry());
		if(m_front == nullptr)
		{
			m_front = temp;
			traverseNew = temp;
		}
		else
		{
			traverseNew->setNext(temp);
			traverseNew = temp;
		}
		traverseRHS = traverseRHS->getNext();
	}
				
}

template <typename T>
Queue<T>::Queue(const Queue<T>& original)
{
      Node<T>* traverseNew = nullptr;
      Node<T>* traverseOrig = original.m_front;
	while(traverseOrig != nullptr)
	{
		Node<T>* temp = new Node<T>(traverseOrig->getEntry());
		if(m_front == nullptr)
		{
			m_front = temp;
			traverseNew = temp;
		}
		else
		{
			traverseNew->setNext(temp);
			traverseNew = temp;
		}
		traverseOrig = traverseOrig->getNext();
	}
}


template <typename T>
bool Queue<T>::isEmpty() const
{
	if(m_length == 0)
	{
		return (true);
	}
	else
	{
		return (false);
	}
}

template <typename T>
void Queue<T>::enqueue(T newEntry)
{
  if(m_length <= 0)
  {
    m_front = new Node<T>(newEntry);
    m_back = m_front;
    m_length=1;
  }
  else
  {
    Node<T>* temp = m_back;
    m_back = new Node<T>(newEntry);
    temp->setNext(m_back);
	  ++m_length;
  }
}

template <typename T>
int Queue<T>::getLength() const
{
	return (m_length);
}

template <typename T>
void Queue<T>::dequeue()
{
	if(m_length>=1)
	{
      Node<T>* temp = m_front;
		  m_front = m_front->getNext();
		  delete (temp);
      --m_length;
	}
	else
	{
		throw(std::runtime_error("Dequeue attempted on an empty queue\n"));
	}
}

template <typename T>
void Queue<T>::clear()
{
  while (m_front != nullptr)
		{
			Node<T>* temp = m_front;
			m_front = m_front->getNext();
			delete (temp);
		}
		delete(m_front);
    m_length = 0;  
}

