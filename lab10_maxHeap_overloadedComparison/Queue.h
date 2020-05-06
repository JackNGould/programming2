/*
 * @project: MaxHeap - Hospital queue simulation
 * @file: Queue.h
 * @author: Jack Gould
 * @brief: Header file for templated Queue class. Lists member methods. Templated, Node based implementation. A single Queue<std::string> is used in this programs executive class to store the input file by lines.
 * @date: 04-17-2020
 */
#ifndef QUEUE_H
#define QUEUE_H

#include "Node.h" //Gone over in class
#include <stdexcept>

template <typename T>
class Queue 
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
     * @throws a jackException if a peek is attempted on an empty queue. Does not return a value in this case
     **/     
     T peekFront() const;
     /** 
     * @pre
     * @post Entry is added to the back of the queue
     * @param const T value: value to be added to the back of the queue
     **/     
     virtual void enqueue(const T value);
     
     
     /** 
     * @pre Assumes the queue is not empty
     * @post Front of the queue is removed
     * @throws a jackException if the Queue is already empty
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

