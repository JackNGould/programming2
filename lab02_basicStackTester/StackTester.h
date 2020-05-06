/*
 * @project: basicStackTester
 * @file: StackTester.h
 * @author: Jack Gould
 * @brief: Header file for StackTester class. Lists member methods. Runs a battery of tests on the StackOfChars class to ensure proper function, attempting to focus on corner cases. 
 * @date: 02-05-2020
 */

#ifndef STACK_TESTER_H
#define STACK_TESTER_H

class StackTester
{
    public:

    StackTester();

    //This will call all your test methods
    void runTests();

    private:

    bool allPassed;

    /**
    * @brief Creates an empty stack and verifies isEmpty() returns true
    **/
    void test01();

    /**
    * @brief Creates an empty stack pushes 1 value, verifies isEmpty() returns false
    **/
    void test02();

    /**
    * @brief Creates an empty stack, then pushes once, pops once, and verifies isEmpty returns true
    **/
    void test03();

    /**
    * @brief Creates an empty stack, then pushes 3 values, and verifies peek() returns the correct value for all 3 after popping
    **/
    void test04();

    /**
    * @brief Creates an empty stack, then attempts pop() on empty stack. Verifies isEmpty returns true, then pushes a value and verifies isEmpty returns false;
    **/
    void test05();

    /**
     *
    * @brief Creates an empty stack, pushes several values, verifies popping on all elements results in an empty stack
    **/
    void test06();


    /**
     *
    * @brief Creates an empty stack, pushes several values, verifies copy constructor copies all values in correct order
    **/
    void test07();

    /**
     *
    * @brief Creates 2 stacks of different sizes and contents, verifies assignment operator overloading results in two identical stacks
    **/
    void test08();
    //more test methods as needed
};
#endif

