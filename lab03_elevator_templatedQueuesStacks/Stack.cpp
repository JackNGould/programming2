/*
 * @project: elevator - templated stacks and queues
 * @file: Stack.cpp
 * @author: Jack Gould
 * @brief: Implementation file for templated Stack class. Defines member methods. Templated, Node based implementation. A stack is used in this lab to store the elevator's contents. Last in, first out structure.
 * @date: 02-19-2020
 */


template <typename T>
Stack<T>::Stack()
{
  m_top = nullptr;
  m_length = 0;
}

template <typename T>
int Stack<T>::getLength() const
{
  return m_length;
}
  
template <typename T>
bool Stack<T>::isEmpty() const
{
  if(m_top == nullptr)
  {
    return true;
  }
  return false;
}
//returns true if the stack is empty, false otherwise

template <typename T>
void Stack<T>::push(const T value)
{
  if(m_length <= 0)
  {
    m_top = new Node<T>(value);
    m_top->nodeSetNext(NULL);
    m_length = 1;
  }
  else if(m_length > 0 && m_length < stackCapacity)
  {
    Node<T>* temp = m_top;
	  m_top = new Node<T>(value);
	  m_top->nodeSetNext(temp);
	  ++m_length;
  }
  else
  {
    throw(PreconditionViolationException("A push was attempted on a full stack. Elevator is full"));
  }

}
/*Entry added to top of stack
thrown PreconditionViolationException if push cannot occur (e.g. stack full)
*/

template <typename T>
void Stack<T>::pop()
{
  if(m_length > 0)
  {
    Node<T>* temp = m_top;
		m_top = m_top->nodeGetNext();
		delete (temp);
    --m_length;
  }
  else
  {
    throw(PreconditionViolationException("A pop was attempted on an empty stack. Nobody on the elevator."));
  }
}
/*assumes the stack is not empty
top of the stack is removed
throws PreconditionViolationException when a pop is attempted on an empty stack. Does not return a value in this case.
*/

template <typename T>
T Stack<T>::peek() const
{
  if(m_top != nullptr)
  {
    return(m_top->nodeGetEntry());
  }
  else
  {
    throw(PreconditionViolationException("A peek was attempted on an empty stack. Nobody on the elevator."));
  }
}
/*assumes the stack is not empty
returns the value at the top of the stack
throws a PreconditionViolationException is attempted on an empty stack. Does not return a value in this case.
*/

