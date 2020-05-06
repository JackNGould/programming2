/*
 * @project: Binary Search Tree filled with custom objects.
 * @file: pokemon.cpp
 * @author: Jack Gould
 * @brief: Implementation file for pokemon class. Defines member methods. These objects will fill a binary search tree. Overloaded operator functions necessary for node comparison in a tree.
 * @date: 04-17-2020
 */

#include "pokemon.h"
#include "jackException.h"

pokemon::pokemon()
{
  m_american = "";
  m_pokedex = 0;
  m_japanese = "";
}

pokemon::pokemon(std::string american, int pokedex, std::string japanese)
{
  m_american = american;
  m_pokedex = pokedex; 
  m_japanese = japanese;
}

/*
pokemon::~pokemon()
{
  
}
*/

pokemon& pokemon::operator=(const pokemon& rhs)
{
  m_american = rhs.m_american;
  m_pokedex = rhs.m_pokedex;
  m_japanese = rhs.m_japanese;
  return *this;
}

bool pokemon::operator==(const std::string& americanName)
{
  
  unsigned int size = americanName.size();
  std::string lhs = m_american;
  std::string rhs = americanName;
  if(lhs.size() != size)
  {
    return false;
  }
  for(unsigned int i=0;i<size;++i)
  {
    char right = std::tolower(rhs[i]);
    char left = std::tolower(lhs[i]);
    if(left != right)
    {
      return false;
    }
  }
  return true;
}


bool pokemon::operator==(const pokemon& rhs) //must check japaneseName and pokedex number as well
{
  bool sameAmerican = true;
//  bool sameJapanese = true;
  std::string rightAmerican = rhs.getAmerican();
//  std::string rightJapanese = rhs.getJapanese();
  if(m_american.size() == rightAmerican.size())
  {
    unsigned int sizeA = rightAmerican.size();
    for(unsigned int i=0;i<sizeA;++i)
    {
      char left = std::tolower(m_american[i]);
      char right = std::tolower(rightAmerican[i]);
      if(left != right)
      {
        sameAmerican = false;
      }
    }
    if (sameAmerican == true)
    {
      return true;
    }
  }
/*
  if(m_japanese.size() == rightJapanese.size())
  {
    unsigned int sizeJ = rightJapanese.size();
    for(unsigned int i=0;i<sizeJ;++i)
    {
      char left = std::tolower(m_japanese[i]);
      char right = std::tolower(rightJapanese[i]);
      if(left != right)
      {
        sameJapanese = false;
      }
    }
    if (sameJapanese == true)
    {
      return true;
    }
  }
  */
  if(m_pokedex == rhs.m_pokedex)
  {
    return true;
  }
  return false;
}

bool pokemon::operator>(const pokemon& rhs)
{
  unsigned int size = 0;
  std::string americanName = rhs.m_american; //american name determines place in alphanumeric BST
  bool leftSideNotShorter = false;
  std::string lhs = m_american;
  if(americanName.size() > lhs.size())
  {
    size = lhs.size();
  }
  else
  {
    size = americanName.size();
    leftSideNotShorter = true;
  }
  for(unsigned int i=0;i<size;++i)
  {
    char left = std::tolower(lhs[i]);
    char right = std::tolower(americanName[i]);
    if(left > right)
    {
      return true;
    }
    else if(left < right)
    {
      return false;
    }
  }
  if(leftSideNotShorter != true || size == lhs.size())
  {
    return false;
  }
  else
  {
    return true;
  }
}

bool pokemon::operator>(const std::string& americanName)
{
  unsigned int size = 0;
  bool leftSideNotShorter = false;
  std::string lhs = m_american;
  std::string rhs = americanName;
  if(americanName.size() > lhs.size())
  {
    size = lhs.size();
  }
  else
  {
    size = americanName.size();
    leftSideNotShorter = true;
  }
  for(unsigned int i=0;i<size;++i)
  {
    char left = std::tolower(lhs[i]);
    char right = std::tolower(rhs[i]);
    if (left > right)
    {
      return true;
    }
    else if (left < right)
    {
      return false;
    }
  }
  if(leftSideNotShorter != true || size == lhs.size())
  {
    return false;
  }
  else
  {
    return true;
  }
}

/*
bool pokemon::operator>(const int& pokedex) //would define this method and one other if searching by other keytypes were necessary
{

}
*/

int pokemon::getIndex() const
{
  return m_pokedex;
}
std::string pokemon::getAmerican() const
{
  return m_american;
}
std::string pokemon::getJapanese() const
{
  return m_japanese;
}

