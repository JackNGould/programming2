/*
 * @assignment EECS 268 Lab05 
 * @file: Browser.cpp
 * @author: Jack Gould
 * @brief: Implementation File for Browser class. Defines member methods. Class is a basic framework designed to mimic the functions of a browser's history function via LinkedList. Inherits from BrowserHistoryInterface
 * @date: 04-01-2020
 */
#include "Browser.h"
#include <stdexcept>

Browser::Browser()
{
  currentHistoryIndex = 0;
  currentURL = "";
}

Browser::~Browser()
{
}

void Browser::navigateTo(std::string url)
{
  if(currentHistoryIndex < theHistory.getLength())
  {
    int countToDelete = theHistory.getLength() - currentHistoryIndex;
    for(int i=0;i<countToDelete;++i)
    {
      theHistory.remove(currentHistoryIndex+1);
    }
  }
  theHistory.insert((currentHistoryIndex+1), url);
  currentHistoryIndex++;
  currentURL = theHistory.getEntry(currentHistoryIndex);
}

void Browser::back()
{
  if(currentHistoryIndex > 1)
  {
    currentHistoryIndex--;
    currentURL = theHistory.getEntry(currentHistoryIndex);
  }
  else
  {
    throw(std::runtime_error("No URL further back in history, staying in place."));
  }
}

void Browser::forward()
{
  if(currentHistoryIndex < theHistory.getLength())
  {
    currentHistoryIndex++;
    currentURL = theHistory.getEntry(currentHistoryIndex);
  }
  else
  {
    throw(std::runtime_error("No URL further forward in history, staying in place."));
  }
}

void Browser::copyCurrentHistory(ListInterface<std::string>& destination)
{
  for(int i=1;i<=theHistory.getLength();++i)
  {
    destination.insert(i, theHistory.getEntry(i));
  }
}

std::string Browser::current() const
{
  return currentURL;
}
