/*
 * @assignment: EECS 268 Lab 06
 * @file: fibonacci.cpp
 * @author: Jack Gould
 * @brief: Implementation fill for the fibonacci class. Contains only two functions, one for each possible mode. runI will return the fibonacci number at the provided index, while runV will check the fibonacci sequence for the provided value.
 * @date: 04-10-2020
 */
#include "fibonacci.h"
#include <iostream>

int fibonacci::runI(int n)
{
  if (n < 0)
  {
    return -1;
  }
  if (n <= 1)
  {
    return n;
  }
  else
  {
    return (runI(n-1) + runI(n-2)); // recursion
  }  
}
void fibonacci::runV(int n)
{
  int index = 0;
  int fibNumber = 0;
  while(fibNumber < n)
  {
    fibNumber = this->runI(index); // recursion occurs here
    ++index;
  }
  
  if(n == 0)
  {
    std::cout << "0 is in the Fibonacci sequence. Its index is 0\n";
  }
  else if (n==1)
  {
    std::cout << "1 is in the Fibonacci sequence. It occurs at both index 1 and index 2. It is the only number which occurs twice\n";
  }
  else
  {
    if(fibNumber == n)
    {
      std::cout << n << " is in the Fibonacci sequence. Its index is " << (index-1) << '\n';
    }
    else
    {
      std::cout << n << " is NOT in the Fibonacci sequence.\n";
    }
  }
}

