/*
 * @project: Binary Search Tree filled with custom objects.
 * @file: executive.cpp
 * @author: Jack Gould
 * @brief: Implementation File for executive class. Defines member methods. Class governs the program's 'executive' actions of filling a BST from the inputFile data, and generating a menu of options for the user. Controls program flow.
 * @date: 04-17-2020
 */

#include "executive.h"
#include "jackException.h"
#include <sstream>
#include <iostream>
#include <limits>

executive::executive(std::string fName)
{
  std::ifstream inFile(fName);
  if (inFile.is_open())
  {
    std::string line;
    while (getline(inFile, line))
    {
        inputLineList.enqueue(line);
    }
    inFile.close();
  }
  else
  {
    throw(jackException("\ninFile not found/opened.\n"));
  }

}


void executive::writeToFile(pokemon entry)
{
  outFile.open(outFileName, std::fstream::app); //must be opened in append mode so that every new line doesn't override old line(s)
  if (outFile.is_open())
  {
    outFile << entry.getAmerican() << '\t' << entry.getIndex() << '\t' << entry.getJapanese() << '\n';
    outFile.close();
  }
  else
  {
    throw(jackException("\noutFile not found/opened.\n"));
  }
}

executive::~executive()
{

}

void executive::run()
{
  fillTree();
  bool runMenu = true;
  do
  {
    std::cout << "\n--------\n--Menu--\n--------\n";
    std::cout << "1)Search the pokedex\n";
    std::cout << "2)Add an entry to the pokedex\n";
    std::cout << "3)Copy Pokedex(one-time only)\n";
    std::cout << "4)Remove from Pokedex Copy\n";
    std::cout << "5)Save a Pokedex\n";
    std::cout << "6)Run a Test\n";
    std::cout << "7)Exit the Program\n";
    int userInput = 0;
    std::cout << "Please make a selection(1-7): ";
    try
    {
      std::cin >> userInput;
      if(std::cin.fail())
      {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw(jackException("\nBad Input Provided, please make sure input is an integer.\n"));
      }
      switch(userInput)
      {
        case 1:
          {
            int pokedexChoice = 0;
            if(copyCreated == true)
            {
              std::cout << "Search selected, please select a pokedex, 1 for the original, 2 for the copy.\n";
              std::cin >> pokedexChoice;
              if(std::cin.fail() || pokedexChoice <=0 || pokedexChoice > 2)
              {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                throw(jackException("\nError, pokedex choice must be either 1 or 2.\n"));
              }
            }
            std::cout << "Please input the american name of a pokemon to search the pokedex for:\n";
            std::string searchTerm;
            std::cin >> searchTerm;
            if(std::cin.fail())
            {
              std::cin.clear();
              std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
              throw(jackException("\nError, couldn't interpret cin input.\n"));
            }
            pokemon temp;
            if(pokedexChoice == 2)
            {
              temp = (copyBST.search(searchTerm));
            }
            else
            {
              temp = (myBST.search(searchTerm));
            }
            std::cout << "\nPokemon Found!\n\tAmerican Name: " << temp.getAmerican() << "\n\tPokedex Number: " << temp.getIndex() << "\n\tJapanese Name: " << temp.getJapanese() << '\n';
            break;
          }
        case 2:
          {
            std::string americanName, japaneseName;
            int pokedex;
InputLoop:  std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            
            std::cout << "Add Entry selected: Please first input an American name for the new pokemon:\n";
            std::cin >> americanName;
            if(std::cin.fail())
            {
              goto InputLoop;
            }
            std::cout << "\nNow input a Japanese name for the new pokemon:\n";
            std::cin >> japaneseName;
            if(std::cin.fail())
            {
              goto InputLoop;
            }
            std::cout << "\nNow input a pokedex number for the new pokemon:\n";
            std::cin >> pokedex;
            if(std::cin.fail())
            {
              goto InputLoop;
            }
           //end InputLoop
            pokemon newPokemon(americanName, pokedex, japaneseName);
            if(copyCreated == true)
            {
              copyBST.add(newPokemon);
              std::cout << '\n' << americanName << " was added to the pokedex COPY\n";
            }
            else
            {
              myBST.add(newPokemon);
              std::cout << '\n' << americanName << " was added to the original pokedex\n";
            }
            break;
          }
        case 3:
          {
            if(copyCreated == false)
            {
              std::cout << "\nCreating a deep copy of the Pokedex...\nREMINDER:Once a copy has been created, edits can only be made to the copy\n";
              copyBST = myBST;
              copyCreated = true;
              std::cout << "\nCopy Created\n";
            }
            else
            {
              throw(jackException("\nA Deep copy was already made, please work with the copy you have already created.\n"));
            }
            break;
          }
 
        case 4:
          {
            if(copyCreated == true)
            {
              std::cout << "\nRemove selected, please input the american name of a pokemon to remove from the copied Pokedex\n";
              std::string keyTerm;
              std::cin >> keyTerm;
              if(std::cin.fail())
              {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                throw(jackException("\nError, couldn't interpret cin input.\n"));
              }
              copyBST.remove(keyTerm);
              std::cout << keyTerm << " was removed from the copied pokedex\n.";
            }
            else
            {
              std::cout << "\nNo copy has been been created, the original pokedex is protected from Node removal.\n";
            }
            break;
          }
 
        case 5:
          {
            int pokedexChoice = 0;
            int traversalChoice = 0;
            savePokedexPrompts(pokedexChoice, traversalChoice, outFileName);
            switch(traversalChoice)
            {
              case 1:
                {
                  if(pokedexChoice == 2)
                  {
                    copyBST.visitPreOrder(std::bind(&executive::writeToFile, this, std::placeholders::_1));
                  }
                  else 
                  {
                    myBST.visitPreOrder(std::bind(&executive::writeToFile, this, std::placeholders::_1));
                  }
                  break;
                }
              case 2:
                {
                  if(pokedexChoice == 2)
                  {
                    copyBST.visitInOrder(std::bind(&executive::writeToFile, this, std::placeholders::_1));
                  }
                  else 
                  {
                    myBST.visitInOrder(std::bind(&executive::writeToFile, this, std::placeholders::_1));
                  }
                  break;
                }
              case 3:
                {
                  if(pokedexChoice == 2)
                  {
                    copyBST.visitPostOrder(std::bind(&executive::writeToFile, this, std::placeholders::_1));
                  }
                  else 
                  {
                    myBST.visitPostOrder(std::bind(&executive::writeToFile, this, std::placeholders::_1));
                  }
                  break;
                }
              default:
                {
                  throw(jackException("\nSomething really had to break for this error to print\n"));
                }
            }
            break;
          }

        case 6:
          {
            int testChoice = 0;
            std::cout << "\nTests on constructors/destructor selected, please choose a test:\n1)Test ADD\n2)Test Remove\n3)Test Write\n";
            std::cin >> testChoice;
            if(std::cin.fail() || testChoice <=0 || testChoice > 3)
            {
              std::cin.clear();
              std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
              throw(jackException("\nError, pokedex choice must be either 1 or 2.\n"));
            }
            switch(testChoice)
            {
              case 1:
                {
                  tester.testAdds(myBST);
                  break;
                }
              case 2:
                {
                  tester.testRemoves(myBST);
                  break;
                }
              case 3:
                {
                  tester.testWriteToFile(myBST);
                  break;
                }
              default:
                {
                  throw(jackException("\nSomething broke here.\n"));
                }
            }
            break;
          }
        case 7:
          {
            std::cout << "\nExiting Program...\n";
            runMenu = false;
            break;
          }

        default:
          {
            throw(jackException("\nError, invalid menu option entered, please input 1, 2, or 3\n"));
            break;
          }
      }
    }
    catch(jackException& rte)
    {
      std::cout << rte.what();
    }
  }while(runMenu != false);
}


void executive::savePokedexPrompts(int& pokedex, int& traversal, std::string& outFile)
{
  if(copyCreated == true)
  {
    std::cout << "Save selected, please select a pokedex, 1 for the original, 2 for the copy.\n";
    std::cin >> pokedex;
    if(std::cin.fail() || pokedex <=0 || pokedex > 2)
    {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      throw(jackException("\nError, pokedex choice must be either 1 or 2.\n"));
    }
  }
  else
  {
    pokedex = 1;
  }
  std::cout << "Save selected, please enter a file name to write the output to\n";
  std::cin >> outFile;
  if(std::cin.fail())
  {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    throw(jackException("\nError, cin input could not be read.\n"));
  }
  std::cout << "Please select an order to traverse the tree in:\n1)PreOrder\n2)InOrder\n3)PostOrder\n";
  std::cin >> traversal;
  if(std::cin.fail() || traversal <= 0 || traversal > 3)
  {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    throw(jackException("\nError, traversal choice must be 1, 2, or 3.\n"));
  }
}

void executive::fillTree()
{
  int objectCount = inputLineList.getLength();
  std::string line = "";
  std::string american, pokedex, japanese;
  int pokedexNum = 0;
  for(int i=0;i<objectCount;++i)
  {
    try
    {
      line = inputLineList.peekFront();
      std::istringstream iss (line);
      iss >> american;
      iss >> pokedex;
      iss >> japanese;      
      pokedexNum = stoi(pokedex);
      pokemon myPokemon(american, pokedexNum, japanese);
      myBST.add(myPokemon);
      inputLineList.dequeue();
    }
    catch(jackException& rte)
    {
      std::cout << rte.what();
    }
  }
}
