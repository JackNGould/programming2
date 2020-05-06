/*
 * @project: gameDataParser
 * @file: game.h
 * @author: Jack Gould
 * @brief: Header File for game class. Lists member methods. Game objects will fill an array at runtime, with data for each game provided from an input file.
 * @date: 01-01-2020
 */

#ifndef GAME_H
#define GAME_H

#include <string>


class game
{
     private:
     std::string m_name; //string storing this game's name
     double m_iRating; //double storing this game's Gibbons rating
     double m_pubRating; //double storing this game's Public Rating
     int m_year; //int storing the year this game released. 
     int m_minPlayers; //int storing the minimum Player count of this game
     int m_minPlaytime; //int storing the minimum Playtime of this game

     
     public:

     /** 
     * @pre 
     * @param std::string name: name of game
     * @param double iRating: Gibbons Rating of game 
     * @param double pubRating: Public Rating of game
     * @param int year: year this game was made
     * @param int minPlayers: minimum players for this game
     * @param int minPlaytime: minimum playtime for this game
     * @post Constructor for game object which assigns member variables to the passed in parameters.
     **/     
     game(std::string name, double iRating, double pubRating, int year, int minPlayers, int minPlaytime);

     /** Constructor without parameters
     * @pre 
     * @post Empty constructor for game object which creates a new game; Initializes member variables to base states.
     **/     
     game();
//     ~game();
     
     /** 
     * @pre 
     * @param std::string name: name of game
     * @param double iRating: Gibbons Rating of game 
     * @param double pubRating: Public Rating of game
     * @param int year: year this game was made
     * @param int minPlayers: minimum players for this game
     * @param int minPlaytime: minimum playtime for this game
     * @post game object's member variables are assigned to the passed in values.
     **/     
     void fillData(std::string name, double iRating, double pubRating, int year, int minPlayers, int minPlaytime);


     /** 
     * @pre 
     * @return int - returns the year this game was made
     **/     
     int getYear() const;

     /** 
     * @pre 
     * @return int - returns the minimum player count for this game
     **/     
     int getMinPlayers() const;

     /** 
     * @pre 
     * @return int - returns the minimum playtime for this game
     **/     
     int getMinPlaytime() const;



     /** 
     * @pre 
     * @return double - returns Dr. Gibbons' rating for this game
     **/     
     double getIRating() const;
    

     /** 
     * @pre 
     * @return double - returns the public's rating for this game
     **/     
     double getPubRating() const;

     /** 
     * @pre 
     * @return Returns the name of this game
     **/
     std::string getName() const;



     /** 
     * @pre 
     * @param std::string name - a string to set the name of this game object to
     * @post this game object's name is set to the passed in string
     **/
     void setName(std::string name);

     /** 
     * @pre 
     * @param int year - an integer to set this game object's release year to
     * @post this game object's release year is set to the passed in integer
     **/
     void setYear(int year);

     /** 
     * @pre 
     * @param double iRating - a double to set this game object's Gibbon's rating to
     * @post this game object's Gibbons Rating is set to the passed in double
     **/
     void setGibbRating(double iRating);

     /** 
     * @pre 
     * @param int minPlayers - an integer to set this game object's minimum player count to 
     * @post this game object's minimum player count is set to the passed in integer
     **/
     void setMinPlayers(int minPlayers);

     /** 
     * @pre 
     * @param int minPlaytime - an integer to set this game object's minimum playtime to
     * @post this game object's minimum playing time is set to the passed in integer
     **/
     void setMinPlaytime(int minPlaytime);

     /** 
     * @pre 
     * @param double pubRating - a double to set this game object's public rating to
     * @post this game object's public Rating is set to the passed in double
     **/
     void setPubRating(double pubRating);
};
#endif
