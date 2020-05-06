/*
 * @project: gameDataParser
 * @file: dataManager.cpp
 * @author: Jack Gould
 * @brief: Implementation File for Executive class. Defines member methods. Initialized by main(). Class governs the programs 'executive' actions of reading the input file, filling an array with game objects, and running the menu.
 * @date: 01-01-2020
 */
#include "dataManager.h"
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <limits>

dataManager::dataManager(std::string fName)
{
    int year, minPlayers, minPlaytime = 0; //temp storage for integer game data
    std::string name= ""; //temp storage for a string of a game's name
    double individualRanking, pubRating = 0.0; //temp storage for public rating data for a game given by a double
  std::ifstream inFile(fName);
  if (inFile.is_open())
  {
    inFile >> gameCount;
    gameList = new game[gameCount];
    for(int i=0;i<gameCount;++i)
    {
      inFile >> name >> individualRanking >> pubRating >> year >> minPlayers >> minPlaytime;
      gameList[i].fillData(name, individualRanking, pubRating, year, minPlayers, minPlaytime);
    }
    inFile.close();
  }
  else
  {
    throw(std::runtime_error("\nFile not found/opened.\n"));
  }
}

dataManager::~dataManager()
{
  delete[] gameList; 
}

void dataManager::printAll()
{
  std::cout << "\n\nALL GAMES BELOW\n\n";
  for(int i=0;i<gameCount;++i)
  {
    std::string name = gameList[i].getName();
    double individualRanking = gameList[i].getIRating();
    double pubRating = gameList[i].getPubRating();
    int year = gameList[i].getYear();
    int minPlayers = gameList[i].getMinPlayers();
    int minPlaytime = gameList[i].getMinPlaytime();
    std::cout << name << " (" << year << ") [IR=" << individualRanking << ", PR=" << pubRating << ", MP=" << minPlayers << ", MT=" << minPlaytime << "]\n"; 
//    std::cout << (i+1) <<": " << gameList[i].getLast() << ", " << gameList[i].getFirst() << " " << gameList[i].getTeam << " " << gameList[i].getBye << " (" << gameList[i].getMyTier() << ")\n";
  }
  std::cout << '\n';
}

void dataManager::printFromYear(int year)
{
  bool gameFound = false;
  std::cout << "\nALL GAMES PUBLISHED IN " << year << " BELOW\n\n";
  for(int i=0;i<gameCount;++i)
  {
    int tempYear = gameList[i].getYear();
    if(tempYear == year)
    {
      gameFound = true;
      std::string name = gameList[i].getName();
      double individualRanking = gameList[i].getIRating();
      double pubRating = gameList[i].getPubRating();
      int year = gameList[i].getYear();
      int minPlayers = gameList[i].getMinPlayers();
      int minPlaytime = gameList[i].getMinPlaytime();
      std::cout << name << " (" << year << ") [IR=" << individualRanking << ", PR=" << pubRating << ", MP=" << minPlayers << ", MT=" << minPlaytime << "]\n"; 
    }
  }
  if(gameFound == false)
  {
    std::cout << "\nNo games found for the provided year!\n";
  }
  std::cout << '\n';
}

void dataManager::printByRange(double highest, double lowest)
{
  //if((lowest >= 0) && (highest>=lowest) && (highest <= 10))
  //{
    std::cout << "\nALL GAMES IN RANGE: [" << highest << " >= Individual Rank(IR) >= " << lowest << "] BELOW\n\n";
    for(int i=0;i<gameCount;++i)
    {
      if((gameList[i].getIRating() >= lowest) && (gameList[i].getIRating() <= highest))
      {
        std::string name = gameList[i].getName();
        double individualRanking = gameList[i].getIRating();
        double pubRating = gameList[i].getPubRating();
        int year = gameList[i].getYear();
        int minPlayers = gameList[i].getMinPlayers();
        int minPlaytime = gameList[i].getMinPlaytime();
        std::cout << name << " (" << year << ") [IR=" << individualRanking << ", PR=" << pubRating << ", MP=" << minPlayers << ", MT=" << minPlaytime << "]\n"; 
      }
    }
    std::cout << '\n';
  //}
  //else
  //{
    //throw(std::runtime_error("\nInvalid ranking range specified. Rankings are between 0 and 10\n"));
  //}

}

void dataManager::printByDelta(double delta)
{
  std::cout << "\nALL GAMES W/ DIFFERENCE |PR-IR| >= " << delta << " BELOW\n\n";
  for(int i=0;i<gameCount;++i)
  {
    double tempDelta = (gameList[i].getIRating() - gameList[i].getPubRating());
    if(tempDelta < 0.0)
    {
      tempDelta = tempDelta * (-1);
    }
    if(tempDelta >= delta)
    {
      std::string name = gameList[i].getName();
      double individualRanking = gameList[i].getIRating();
      double pubRating = gameList[i].getPubRating();
      int year = gameList[i].getYear();
      int minPlayers = gameList[i].getMinPlayers();
      int minPlaytime = gameList[i].getMinPlaytime();
      std::cout << name << " (" << year << ") [IR=" << individualRanking << ", PR=" << pubRating << ", MP=" << minPlayers << ", MT=" << minPlaytime << "]\n"; 
    }
  } 
  std::cout << '\n';
}

void dataManager::findGame(int minimumPlayers, int minimumPlaytime)
{
  bool gameFound = false;
  std::cout << "\nALL GAMES W/ minPlayers >= " << minimumPlayers << " AND minimumPlaytime >= " << minimumPlaytime << " BELOW\n\n";
  for(int i=0;i<gameCount;++i)
  {
    if((gameList[i].getMinPlayers() >= minimumPlayers) && (gameList[i].getMinPlaytime() >= minimumPlaytime))
    {
      gameFound = true;
      std::string name = gameList[i].getName();
      double individualRanking = gameList[i].getIRating();
      double pubRating = gameList[i].getPubRating();
      int year = gameList[i].getYear();
      int minPlayers = gameList[i].getMinPlayers();
      int minPlaytime = gameList[i].getMinPlaytime();
      std::cout << name << " (" << year << ") [IR=" << individualRanking << ", PR=" << pubRating << ", MP=" << minPlayers << ", MT=" << minPlaytime << "]\n"; 
    }
  }
  if(gameFound == false)
  {
    std::cout << "\nNo game found matching those specifications.\n";
  }
  std::cout << '\n';
}

void dataManager::clearCin()
{
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void dataManager::run()
{
  int userInput = 0;
  do
  {
    std::cout << "\n\nSelect an Option:\n";
    std::cout << "\t1)Print all games (ordered as provided)\n";
    std::cout << "\t2)Print all games from a specific year\n";
    std::cout << "\t3)Print all games in a ranking range(Individual)\n";
    std::cout << "\t4)The People VS Individual\n";
    std::cout << "\t5)Find a game to play\n";
    std::cout << "\t6)Exit the Program\n";
    std::cout << "Enter Selection: ";
    std::cin >> userInput;
    while (std::cin.fail())
    {
      clearCin();
      std::cout << "Invalid input, try again: ";
      std::cin >> userInput;
      std::cout << "\n\n";
    }
    switch(userInput)
    {
      case 1:
        printAll();
        break;
      case 2:
        {
          int input;
          std::cout << "\n\nPlease enter a year to look for: ";
          std::cin >> input;
          while (std::cin.fail())
          {
            clearCin();
            std::cout << "Invalid input, try again: ";
            std::cin >> input;
            std::cout << "\n\n";
          }
          clearCin();
          printFromYear(input);
          break;
        }
      case 3:
        {
case3Label: double highest, lowest = 0.0;
          std::cout << "\n\nPlease enter the lower/upper bounds for the range.\nAcceptable values range from 0.0 - 10.0, decimals allowed.\n\nInput lower bound: ";
          std::cin >> lowest;
          if(std::cin.fail())
          {
            clearCin();
            std::cout << "\nMust be a double (decimals allowed).\n";
            goto case3Label;
          }
          this->clearCin();
          std::cout << "\n\nInput upper bound:  ";
          std::cin >> highest;
          if(std::cin.fail())
          {
            clearCin();
            std::cout << "\n\nMust be a double (decimals allowed).\n";
            goto case3Label;
          }
          if(0<=lowest && highest>=lowest && highest <=10.0)
          {
            clearCin();
            printByRange(highest, lowest);
          }
          else
          {
            clearCin();
            std::cout << "\n\nBad Input. Need 0-10 w/ upperBound>lowerBound\n\n";
            goto case3Label;
          }
          break;
        }
      case 4:
        {
          double delta;
          std::cout << "\n\nPlease enter a threshold value (0-10, decimals allowed) to use as delta.\n\nAll games with a delta between Individual's/Public's rankings that meets or exceeds the provided delta will be shown.\n\nInput Threshold: ";
          std::cin >> delta;
          while(std::cin.fail() || delta<0 || delta>10)
          {
            clearCin();
            std::cout << "\nInvalid input, must be between 0-10 with decimals allowed.\n\nTry again: ";
            std::cin >> delta;
          }
          clearCin();
          printByDelta(delta);
          break;
        }
      case 5:
        {
case5Label: int minimumPlayers, minimumPlaytime = 0;
          std::cout << "\n\nPlease enter a minimum player count: ";
          std::cin >> minimumPlayers;
          if(std::cin.fail())
          {
            clearCin();
            std::cout << "\n\nError, please input an integer.";
            goto case5Label;
          }
          clearCin();
          std::cout << "\n\nPlease enter a minimum playtime: ";
          std::cin >> minimumPlaytime;
          if(std::cin.fail())
          {
            clearCin();
            std::cout << "\n\nError, please input an integer.";
            goto case5Label;
          }
          clearCin();
          findGame(minimumPlayers, minimumPlaytime);
          break;
        }
      case 6:
        {
          std::cout << "\n\nExiting Program...\n";
          runMenu = false;
          break;
        }
    }
  }while(runMenu == true);
}
