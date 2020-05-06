/*
 * @project: Binary Search Tree filled with custom objects.
 * @file: treeTest.cpp
 * @author: Jack Gould
 * @brief: Implementation file for treeTest class. Defines member methods. Class runs tests on the Binary Search Tree(BST) to ensure proper functioning of constructors, destructors, etc.
 * @date: 04-17-2020
 */

#include "treeTest.h"
#include <limits>

treeTest::treeTest()
{

}

treeTest::~treeTest()
{

}

void treeTest::testAdds(BST<pokemon, std::string> bst)
{
  std::string americanName, japaneseName;
  int pokedex;
MenuLoop: std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Add Entry selected: Please first input an American name for the new pokemon:\n";
    std::cin >> americanName;
    if(std::cin.fail())
    {
      goto MenuLoop;
    }
    std::cout << "\nNow input a Japanese name for the new pokemon:\n";
    std::cin >> japaneseName;
    if(std::cin.fail())
    {
      goto MenuLoop;
    }
    std::cout << "\nNow input a pokedex number for the new pokemon:\n";
    std::cin >> pokedex;
    if(std::cin.fail())
    {
      goto MenuLoop;
    }
  
  pokemon newPokemon(americanName, pokedex, japaneseName);
  bst.add(newPokemon);
  std::cout << americanName << " was added to the original pokedex by the testTree class\n";
  bst.visitInOrder(std::bind(&treeTest::printNode, this, std::placeholders::_1));
}


void treeTest::testRemoves(BST<pokemon, std::string> bst)
{
  std::string keyterm;
  std::cout << "\nTest remove selected: please input the american name of a pokemon to remove from the original pokedex:\n";
  std::cin >> keyterm;
  while(std::cin.fail())
  {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "\nBad input, try again: \n";
    std::cin >> keyterm;
  }
  bst.remove(keyterm);
  std::cout << keyterm << " was removed from the original pokedex.\n";
  bst.visitInOrder(std::bind(&treeTest::printNode, this, std::placeholders::_1));
}


void treeTest::testWriteToFile(BST<pokemon, std::string> bst)
{
  std::cout << "\nTest write selected: please input a filename to write the output to: \n";
  std::cin >> file;
  while(std::cin.fail())
  {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "\nBad input, try again: \n";
    std::cin >> file;
  }
  bst.visitInOrder(std::bind(&treeTest::testWriteEntry, this, std::placeholders::_1));

}

void treeTest::testWriteEntry(pokemon entry)
{
  outFile.open(file, std::fstream::app);
  std::string american = entry.getAmerican();
  std::string japanese = entry.getJapanese();
  int pokedex = entry.getIndex();
  outFile << american << '\t' << pokedex << '\t' << japanese << '\n';
}

void treeTest::printNode(pokemon entry)
{
  std::string american = entry.getAmerican();
  std::string japanese = entry.getJapanese();
  int pokedex = entry.getIndex();
  std::cout << '\n' << american << '\t' << pokedex << '\t' << japanese << '\n';
}
