# LAB 09
 In this program I created a templated Binary Search tree.
 * A BST is used in this lab to form a tree of pokemon objects.
 * Pokemon objects store American/Japanese names, and an associated unique number for the pokedex.

## New Topics:
  * Binary Search Tree

## Input:
File name passed in at execution time.
### File Format:
  * one pokemon per line. Any length
  * Pokemon data includes american/japanese names, and an associated unique pokedex number
  * each line has format: <american name> <pokedex number> <japanese pokemon name>
Example:
```
Ekans	23	Arbo
Arbok	24	Arbok
Seaking	119	Azumao
Mr. Mime	122	Barrierd
Weedle	13	Beedle
Lickitung	108	Beroringa
Grimer	88	Betbeter
Muk	89	Betbeton
Voltorb	100	Biriridama
Magmar	126	Boober
Flareon	136	Booster
Butterfree	12	Butterfree
Abra	63	Casey
Caterpie	10	Caterpie
Kakuna	14	Cocoon
Magnemite	81	Coil
Bulbasaur	1	Fushigidane
Ivysaur	2	Fushigisou
Venusaur	3	Fushigibana
Charmander	4	Hitokage
Charmeleon	5	Lizardo
```
NOTE:Entries do NOT need to be provided in any specific order

## User Menu:
  * Search: User provides pokedex number
    * Prints all pokemon info to screen(american name, japanese name, pokedex #)
  * Add: Prompts user for pokemon info to add
    * Adds the provided pokemon info to the tree.
    * If it would be a duplicate, exception is thrown.
  * Copy: Creates a deep copy of BST for editing.
    * Once a copy is made by the user, only the copy is editable
    * Option only selectable once per program run.
    * *Separate from test functions, which take BST by value, and copy on the call*
  * Remove: Remove a pokemon from the BST. Can only be done to copy
    * Obtains american name from user.
    * Informs user if pokemon not found by american name
  * Save: Prompts user for the following:
    * Output file name
    * Which pokedex to save: Original or copy
    * Traversal order: In, pre, post orders
  * Test: Several Tree test options to ensure proper copy constructor/destructor function
    * test add: Original pokedex passed in, prompt for addition
      * prints tree in in-order
    * test remove: Original pokedex passed in, prompt for removal
      * prints tree in in-order
    * test write to file: Original pokedex passed in, prompt for ouput file name
      * writes tree to file in in-order
  * Quit: Exits the program
