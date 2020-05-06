/*
 * @project: gameDataParser
 * @file: game.cpp
 * @author: Jack Gould
 * @brief: Implementation File for game class. Defines member methods. Game objects will fill an array at runtime, with data for each game provided from an input file.
 * @date: 01-01-2020
 */

#include "game.h"

game::game()
{

  m_name= "";
  m_iRating = 0.0;
  m_pubRating = 0.0;
  m_year = 0;
  m_minPlayers = 0;
  m_minPlaytime = 0;

}

game::game(std::string name, double iRating, double pubRating, int year, int minPlayers, int minPlaytime)
{
  m_name = name;
  m_iRating = iRating;
  m_pubRating = pubRating;
  m_year = year;
  m_minPlayers = minPlayers;
  m_minPlaytime = minPlaytime;
}

void game::fillData(std::string name, double iRating, double pubRating, int year, int minPlayers, int minPlaytime)
{
  m_name = name;
  m_iRating = iRating;
  m_pubRating = pubRating;
  m_year = year;
  m_minPlayers = minPlayers;
  m_minPlaytime = minPlaytime;
}
/*
game::~game()
{
  
}
*/


void game::setName(std::string name)
{
  m_name = name;
}

void game::setYear(int year)
{
  m_year = year;
}

void game::setPubRating(double pubRating)
{
  m_pubRating = pubRating;
}

void game::setGibbRating(double iRating)
{
  m_iRating = iRating;
}

void game::setMinPlayers(int minPlayers)
{
  m_minPlayers = minPlayers;
}

void game::setMinPlaytime(int minPlaytime)
{
  m_minPlaytime = minPlaytime;
}

std::string game::getName() const
{
  return m_name;
}

int game::getMinPlayers() const
{
  return m_minPlayers;
}

double game::getPubRating() const
{
  return m_pubRating;
}

double game::getIRating() const
{
  return m_iRating;
}

int game::getYear() const
{
  return m_year;
}

int game::getMinPlaytime() const
{
  return m_minPlaytime;
}

