/*
 * @project: Binary Search Tree filled with custom objects.
 * @file: Queue.cpp
 * @author: Jack Gould
 * @brief: Implementation file for templated Queue class. Defines member methods. Templated, Node based implementation. A single Queue<std::string> is used in this programs executive class to store the input file by lines.
 * @date: 04-17-2020
 */

template <typename T>
T Queue<T>::peekFront() const
{
	if(m_front != nullptr && m_length>0)
	{
		return(m_front->nodeGetEntry());
	}
	else
	{
		throw(jackException("Peek attempted on an empty queue, no input in line!\n"));
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
Queue<T>& Queue<T>::operator=(const Queue<T>& original)
{  
  if (original.m_length == 0)
  {
        m_length = 0;
  }
  else
  {
        m_front = new Node<T>(original.getEntry(1));
        Node<T>* current = m_front;
        Node<T>* originalFront = original.m_front;
        Node<T>* currentObj = originalFront;
        while (currentObj->nodeGetNext() != NULL)
        {
            current->nodeGetNext() = new Node<T>(currentObj->nodeGetNext()->nodeGetEntry());
            currentObj = currentObj->nodeGetNext();
            current = current->nodeGetNext();
        }
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
    m_front->nodeSetNext(NULL);
    m_length=1;
  }
  else
  {
    Node<T>* temp = m_back;
    m_back = new Node<T>(newEntry);
    temp->nodeSetNext(m_back);
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
		  m_front = m_front->nodeGetNext();
		  delete (temp);
      --m_length;
	}
	else
	{
		throw(jackException("Dequeue attempted on an empty queue\n"));
	}
}

template <typename T>
void Queue<T>::clear()
{
  while (m_front != nullptr)
		{
			Node<T>* temp = m_front;
			m_front = m_front->nodeGetNext();
			delete (temp);
		}
		delete(m_front);
    m_length = 0;  
}

