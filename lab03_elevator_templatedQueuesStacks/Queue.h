/*
 * @project: elevator - templated stacks and queues
 * @file: Queue.h
 * @author: Jack Gould
 * @brief: Header file for templated Queue class. Lists member methods. Templated, Node based implementation. Queues are used in this lab to store input commands in a list and simulate a line for an elevator.
 * @date: 02-19-2020
 */
#ifndef QUEUE_H
#define QUEUE_H

#include "Node.h" //Gone over in class
#include "PreconditionViolationException.h"



template <typename T>
class QueueInterface
{
  public:
    virtual ~QueueInterface() {}
    virtual bool isEmpty() const = 0;
    //returns true if the stack is empty, false otherwise
    virtual void enqueue(const T value) = 0;
    //Entry added to back of queue
    virtual void dequeue() = 0;
    //assumes the queue is not empty
    //front of the front is removed
    //throws PreconditionViolationException ifattempted on an empty queue. Does not return a value in this case.
    virtual T peekFront() const = 0;
    //assumes the queue is not empty
    //returns the value at the front of the stack
    //throws a PreconditionViolationException if attempted on an empty queue. Does not return a value in this case.
};
template <typename T>
class Queue: public QueueInterface<T>
{

  private:
      //pointer to front of queue
     Node<T>* m_front;
     //length of queue
     int m_length;
     //pointer to back of queue
     Node<T>* m_back;
     
  public:
     
     //constructor
     /** 
     * @pre
     * @post a new, empty Queue is created
     **/     
     Queue();

     //Queue(const Queue& original);

     //destructor
     /** 
     * @pre
     * @post calls the clear() method, which destroys the Queue
     **/     
     ~Queue();

     /** 
     * @pre Assumes the queue is not empty
     * @return returns the value at the front of the queue
     * @throws a PreconditionViolationException if a peek is attempted on an empty queue. Does not return a value in this case
     **/     
     T peekFront() const;

     /** 
     * @pre Assumes the queue is not empty
     * @return returns the value at the back of the queue
     * @throws a PreconditionViolationException if a peek is attempted on an empty queue. Does not return a value in this case
     **/     
     T peekBack() const;

     /** 
     * @pre
     * @post Entry is added to the back of the queue
     * @param const T value: value to be added to the back of the queue
     **/     
     virtual void enqueue(const T value);
     
     
     /** 
     * @pre Assumes the queue is not empty
     * @post Front of the queue is removed
     * @throws a PreconditionViolationException if the Queue is already empty
     **/     
     virtual void dequeue();
   
     /** Assignment operator overloading - never used
     * @pre
     * @return Queue& - The calling object is made to be an identical copy to the passed in Queue
     **/     
    Queue& operator=(const Queue<T>& original);
     
     /** 
     * @pre 
     * @post Returns true if queue is empty, false otherwise
     * @param
     **/     
     bool isEmpty() const;
    
     /** 
     * @pre 
     * @post Returns length of queue
     **/
     int getLength() const;

     
     /**
     * @pre 
     * @post List Cleared of all values
     **/
     void clear();
};
#include "Queue.cpp"
#endif

