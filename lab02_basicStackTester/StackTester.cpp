/*
 * @project: basicStackTester
 * @file: StackTester.cpp
 * @author: Jack Gould
 * @brief: Implementation file for StackTester class. Defines member methods. Runs a battery of tests on the StackOfChars class to ensure proper function, attempting to focus on corner cases. 
 * @date: 02-05-2020
 */

#include "StackTester.h"
#include "StackOfChars.h"
#include <iostream>

StackTester::StackTester()
{
	allPassed = true;
}

void StackTester::runTests()
{
	allPassed = true;
	test01();
	test02();
	test03();
	test04();
	test05();
	test06();
	test07();
	test08();
	if(allPassed == true)
	{
		std::cout << "\nAll Tests Passed!\n";
	}
	else
	{
		std::cout << "\nOne or more tests failed!\n";
	}
}

void StackTester::test01()
{
	std::cout << "\nTest #1 - creates empty stack and verifies isEmpty() returns true - ";
	StackOfChars tempStack;
	if(tempStack.isEmpty() == true)
	{
		std::cout << "PASSED\n";
	}
	else
	{
		std::cout << "FAILED\n";
		allPassed = false;
	}
}

void StackTester::test02()
{
	std::cout << "\nTest #2 - creates an empty stack pushes 1 value, verifies isEmpty() returns false - ";
	StackOfChars tempStack;
	tempStack.push('a');
	if(tempStack.isEmpty() == false)
	{
		std::cout << "PASSED\n";
	}
	else
	{
		std::cout << "FAILED\n";
		allPassed = false;
	}
}

void StackTester::test03()
{
	std::cout << "\nTest #3 - creates an empty stack, pushes once, pops once, and verifies isEmpty() returns true - ";
	StackOfChars tempStack;
	tempStack.push('a');
	tempStack.pop();
	if(tempStack.isEmpty() == true)
	{
		std::cout << "PASSED\n";
	}
	else
	{
		std::cout << "FAILED\n";
		allPassed = false;
	}
}

void StackTester::test04()
{
  bool fail = false;
	std::cout << "\nTest #4 - creates an empty stack, pushes 3 times, and verifies peek() returns the correct values all three times - ";
	StackOfChars tempStack;
	tempStack.push('c');
	tempStack.push('b');
	tempStack.push('a');
	if(tempStack.peek() == 'a')
	{
    tempStack.pop();
    if(tempStack.peek() == 'b')
    {
      tempStack.pop();
      if(tempStack.peek() == 'c')
      {
        std::cout << "PASSED\n";
      }else fail = true;
    }else fail = true;
	}else fail = true;
  if (fail == true)
	{
		std::cout << "FAILED\n";
		allPassed = false;
	}
}

void StackTester::test05()
{
  bool fail = false;
	std::cout << "\nTest #5 - creates an empty stack, attempts to pop() empty stack. Verifies isEmpty returns true, then pushes a value and verifies isEmpty returns false - ";
	StackOfChars tempStack;
	tempStack.pop();
	if(tempStack.isEmpty() == true)
	{
    tempStack.push('a');
    if(tempStack.isEmpty() == false)
    {
      std::cout << "PASSED\n";
    }else fail = true;
	}else fail = true;
  if (fail == true)
	{
		std::cout << "FAILED\n";
		allPassed = false;
	}
}



void StackTester::test06()
{
	std::cout << "\nTest #6 - creates stack, adds several values, verfies popping on all elements results in empty stack - ";
	StackOfChars tempStack;
  tempStack.push('a');
  tempStack.push('a');
  tempStack.push('a');
  tempStack.push('a');
  tempStack.push('a');
  tempStack.push('a');
	tempStack.pop();
	tempStack.pop();
	tempStack.pop();
	tempStack.pop();
	tempStack.pop();
	tempStack.pop();
	if(tempStack.isEmpty() == true)
	{
      std::cout << "PASSED\n";
	}
  else
	{
		std::cout << "FAILED\n";
		allPassed = false;
	}
}

void StackTester::test07()
{
  bool fail = false;
	std::cout << "\nTest #7 - creates stack, adds several values, verfies copy constructor adds all values in correct order - ";
	StackOfChars tempStack;
  tempStack.push('7');
  tempStack.push('6');
  tempStack.push('5');
  tempStack.push('4');
  tempStack.push('3');
  tempStack.push('2');
  tempStack.push('1');
  tempStack.push('0');
  StackOfChars secondStack(tempStack);
  while(tempStack.isEmpty() == false)
  {
    if(tempStack.peek() != secondStack.peek())
    {
      fail = true;
    }
    tempStack.pop();
    secondStack.pop();
  }
  if(fail == true)
  {
    std::cout << "FAILED\n";
    allPassed = false;
  }
  else std::cout << "PASSED\n";
}



void StackTester::test08()
{
  bool fail = false;
	std::cout << "\nTest #8 - creates two stacks of different sizes and contents, verifies assignment operator results in two identical stacks - ";
	StackOfChars tempStack;
  tempStack.push('7');
  tempStack.push('6');
  tempStack.push('5');
  tempStack.push('4');
  tempStack.push('3');
  tempStack.push('2');
  tempStack.push('1');
  tempStack.push('0');
  StackOfChars secondStack;
  secondStack.push('f');
  secondStack.push('e');
  secondStack.push('d');
  secondStack.push('c');
  secondStack.push('b');
  secondStack.push('a');
  secondStack=(tempStack);
  while(tempStack.isEmpty() == false)
  {
    if(tempStack.peek() != secondStack.peek())
    {
      fail = true;
    }
    tempStack.pop();
    secondStack.pop();
  }
  if(fail == true)
  {
    std::cout << "FAILED\n";
    allPassed = false;
  }
  else std::cout << "PASSED\n";
}





