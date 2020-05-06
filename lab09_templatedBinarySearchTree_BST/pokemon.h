/*
 * @project: Binary Search Tree filled with custom objects.
 * @file: pokemon.h
 * @author: Jack Gould
 * @brief: Header file for pokemon class. Defines member methods. These objects will fill a binary search tree. Overloaded operator functions necessary for node comparison in a tree.
 * @date: 04-17-2020
 */

#ifndef POKEMON_H
#define POKEMON_H

#include <string>


class pokemon
{
     private:
     int m_pokedex; //int storing the pokedex number of this pokemon. (i.e. pokemons SSN)
     std::string m_american; //string storing this pokemons American name
     std::string m_japanese; //string storing this pokemons Japanese name

     
     public:
     /** 
     * @pre 
     * @param std::string american: american name of pokemon object
     * @param int pokedex: pokedex number of pokemon object
     * @param std::string japanes: japanese name of pokemon object
     * @post Constructor for pokemon object which assigns member variables to the passed in parameters.
     **/     
     pokemon(std::string american, int pokedex, std::string japanese);

     /** Constructor without parameters
     * @pre 
     * @post Empty constructor for pokemon object which creates a new pokemon; Initializes member variables to base states.
     **/     
     pokemon();
//     ~pokemon();
     
     /** Assignment Operator Overloading
     * @pre 
     * @param const pokemon& rhs - A pokemon object to be copied
     * @return pokemon& - The calling object is made to be an identical copy to the passed in Pokemon
     **/     
     pokemon& operator=(const pokemon& rhs);

     /** Comparison Operator == Overloading
     * @pre 
     * @param const pokemon& rhs - A pokemon object to compare to 
     * @return bool - Returns true if either the american names or the pokedex's of the two pokemon are the same, false otherwise.
     * NOTE - this function is used to scan for duplicates, initially it checked if any of the three member variables were the same(american name, japanese name, pokedex)
     *        -I discovered that in the sample file, there are two pokemon with the same japanese name but different american names
     *        -Thus, I commented out the section for the japanese name and now only make sure that the american name and pokedex are unique
     **/     
     bool operator==(const pokemon& rhs);

     /** Comparison Operator > Overloading
     * @pre 
     * @param const pokemon& rhs - A pokemon object to compare to 
     * @return bool - Returns true if the calling pokemon has an American name which is alphanumerically 'greater' than the rhs American name. False Otherwise
     * NOTE - this function is used to add entries to a tree in the correct order.
     **/     
     bool operator>(const pokemon& rhs);

     /** Comparison Operator == Overloading
     * @pre 
     * @param const std::string& americanName - the American Name to check against
     * @return bool - Returns true if either the american names or the pokedex's of the two pokemon are the same, false otherwise.
     * NOTE - this function is used to search against a key of KeyType std::string
     **/     
     bool operator==(const std::string& americanName);

     /** Comparison Operator > Overloading
     * @pre 
     * @param const std::string& americanName - the American Name to check against
     * @return bool - Returns true if the calling pokemon has an American name which is alphanumerically 'greater' than the passed in americanName
     * NOTE - this function is used to search against a key of KeyType std::string
     **/     
     bool operator>(const std::string& americanName);

     /** 
     * @pre 
     * @return Returns integer of pokedex
     * @param
     **/     
     int getIndex() const;
    
     /** 
     * @pre 
     * @return Returns American Name of pokemon object
     * @param posit
     **/
     std::string getAmerican() const;
     /** 
     * @pre 
     * @return Returns Japanese Name of pokemon object
     * @param posit
     **/
     std::string getJapanese() const;
};
#endif
