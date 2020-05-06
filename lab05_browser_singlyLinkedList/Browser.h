/*
 * @assignment EECS 268 Lab05 
 * @file: Browser.h
 * @author: Jack Gould
 * @brief: Header File for Browser class. Lists member methods. Class is a basic framework designed to mimic the functions of a browser's history function via LinkedList. Inherits from BrowserHistoryInterface
 * @date: 04-01-2020
 */
#ifndef BROWSER_H
#define BROWSER_H

#include "BrowserHistoryInterface.h"


class Browser: public BrowserHistoryInterface
{
  public:
       /** CONSTRUCTOR
    * @pre - none
    * @post Browser object is created, member variables initialized.
    */
    Browser();

       /** DESTRUCTOR
    * @pre - 
    * @post Browser object is destroyed
    */
    ~Browser();

       /**
    * @pre none
    * @post the browser navigate to the given url
    * @param url, a string representing a URL
    */
    void navigateTo(std::string url);

    /**
    * @pre none
    * @post if possible, the browser navigates forward in the history otherwise it keeps focus
    *         on the current URL
    */
    void forward();

    /**
    * @pre none
    * @post if possible, the browser navigates backwards in the history otherwise it keeps focus
    *         on the current URL
    */
    void back();

    /**
    * @return the current URL
    */
    std::string current() const;

    /**
    * @pre The list being passed in is empty
    * @post The current browser history is copied into the given list
    * @param destination, an empty list of strings
    */
    void copyCurrentHistory(ListInterface<std::string>& destination);

  private:

    //Private member variable
    //Stores history of this browser
    LinkedList<std::string> theHistory;

    //Private member variable
    //Stores index in History List that is current
    int currentHistoryIndex;

    //Private member variable
    //Stores the current URL of the Browser
    std::string currentURL;

};
#endif
