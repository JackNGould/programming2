# Lab01
  Simply a test of basic programming skills in c++(From programming I class).

## Topics
* File Reading
* iostream
* Array manipulation
* Object oriented design.

## Input
* A filename of a well-formatted input file in the same directory is required.
* A large sample input file with data from Board Game Geek site is provided.
### Input File Format:
* Top of each file is number of games in list
* 1 game per line with the below format
```
<name> <individual ranking> <public ranking> <year published> <min players> <min playtime>
```
Small example: (full sample file provided)
```
5
10_minute_heist:_the_wizard's_tower	6	5.87996	2017	2	10
1st_&_goal	7.5	6.05092	2011	2	120
7_wonders_duel	8	7.97935	2015	2	30
adventure_time_love_letter	6.5	6.34634	2015	2	20
arkham_horror:_the_card_game	9.5	7.91684	2016	1	60
```
NOTE: names do not need to be formatted *exactly* as in the example, but spaces must be removed or replaced from game titles

## User Menu:
* 1 - Print All Games: prints all games passed in
* 2 - Print All Games From Year: prints all games published in a user-provided year
* 3 - Print a ranking range: prints all games with an individual rank that falls in a range provided by the user
* 4 - The People vs Individual: Obtain a delta from the user. Prints all games where the difference between the individual rank and the people's rank meets or exceeds this delta.
* 5 - Find Game: Obtain a min player count and min playTime from the user. Prints all games that require at least that amount of players and require at least that much time to play. 
* 6 - Exit Program: quits program

## Example runs

Example #1
╰─./lab01 sampleBoardGameGeekData.txt
```
Select an Option:
	1)Print all games (ordered as provided)
	2)Print all games from a specific year
	3)Print all games in a ranking range(Individual)
	4)The People VS Individual
	5)Find a game to play
	6)Exit the Program
Enter Selection: 2


Please enter a year to look for: 100

ALL GAMES PUBLISHED IN 100 BELOW


No games found for the provided year!



Select an Option:
	1)Print all games (ordered as provided)
	2)Print all games from a specific year
	3)Print all games in a ranking range(Individual)
	4)The People VS Individual
	5)Find a game to play
	6)Exit the Program
Enter Selection: 2


Please enter a year to look for: 1997

ALL GAMES PUBLISHED IN 1997 BELOW

for_sale (1997) [IR=9, PR=7.10778, MP=3, MT=30]



Select an Option:
	1)Print all games (ordered as provided)
	2)Print all games from a specific year
	3)Print all games in a ranking range(Individual)
	4)The People VS Individual
	5)Find a game to play
	6)Exit the Program
Enter Selection: 3


Please enter the lower/upper bounds for the range.
Acceptable values range from 0.0 - 10.0, decimals allowed.

Input lower bound: 0.2


Input upper bound:  3.6

ALL GAMES IN RANGE: [3.6 >= Individual Rank(IR) >= 0.2] BELOW

arkham_horror:_the_card_game_–_return_to_the_night_of_the_zealot (2018) [IR=3, PR=5.96254, MP=1, MT=60]
carcassonne:_the_dice_game (2011) [IR=1, PR=5.29272, MP=2, MT=10]
hanabi (2010) [IR=1.5, PR=7.02297, MP=2, MT=25]
quiddler (1998) [IR=1.5, PR=5.83363, MP=1, MT=30]
sentinels_of_the_multiverse (2011) [IR=3, PR=7.02899, MP=2, MT=30]
shark_island (2017) [IR=3.5, PR=5.47753, MP=2, MT=30]
t.i.m.e_stories:_estrella_drive (2017) [IR=1, PR=6.37211, MP=2, MT=90]
t.i.m.e_stories:_under_the_mask (2016) [IR=2, PR=6.81238, MP=2, MT=90]



Select an Option:
	1)Print all games (ordered as provided)
	2)Print all games from a specific year
	3)Print all games in a ranking range(Individual)
	4)The People VS Individual
	5)Find a game to play
	6)Exit the Program
Enter Selection: 5


Please enter a minimum player count: 4


Please enter a minimum playtime: 30

ALL GAMES W/ minPlayers >= 4 AND minimumPlaytime >= 30 BELOW

blood_rage:_5th_player_expansion (2015) [IR=7.5, PR=6.99356, MP=5, MT=60]
concept (2013) [IR=8, PR=6.70674, MP=4, MT=40]
the_resistance (2009) [IR=5, PR=7.1901, MP=5, MT=30]
the_resistance:_avalon (2012) [IR=6, PR=7.43533, MP=5, MT=30]
secret_hitler (2016) [IR=4, PR=7.28529, MP=5, MT=45]
telestrations (2009) [IR=5.5, PR=7.18024, MP=4, MT=30]



Select an Option:
	1)Print all games (ordered as provided)
	2)Print all games from a specific year
	3)Print all games in a ranking range(Individual)
	4)The People VS Individual
	5)Find a game to play
	6)Exit the Program
Enter Selection: 6

Exiting Program...
```

Example #2
╰─./lab01 sampleBoardGameGeekData.txt
```
Select an Option:
	1)Print all games (ordered as provided)
	2)Print all games from a specific year
	3)Print all games in a ranking range(Individual)
	4)The People VS Individual
	5)Find a game to play
	6)Exit the Program
Enter Selection: 4


Please enter a threshold value (0-10, decimals allowed) to use as delta.

All games with a delta between Individual's/Public's rankings that meets or exceeds the provided delta will be shown.

Input Threshold: 8.2

ALL GAMES W/ DIFFERENCE |PR-IR| >= 8.2 BELOW




Select an Option:
	1)Print all games (ordered as provided)
	2)Print all games from a specific year
	3)Print all games in a ranking range(Individual)
	4)The People VS Individual
	5)Find a game to play
	6)Exit the Program
Enter Selection: 4


Please enter a threshold value (0-10, decimals allowed) to use as delta.

All games with a delta between Individual's/Public's rankings that meets or exceeds the provided delta will be shown.

Input Threshold: 6

ALL GAMES W/ DIFFERENCE |PR-IR| >= 6 BELOW

betrayal_at_baldur's_gate (2017) [IR=0, PR=6.45056, MP=3, MT=60]
unlock!_the_island_of_doctor_goorse (2017) [IR=0, PR=6.17002, MP=2, MT=60]
unlock!_the_tonipal's_treasure (2017) [IR=0, PR=6.29087, MP=1, MT=60]



Select an Option:
	1)Print all games (ordered as provided)
	2)Print all games from a specific year
	3)Print all games in a ranking range(Individual)
	4)The People VS Individual
	5)Find a game to play
	6)Exit the Program
Enter Selection: 5


Please enter a minimum player count: 3


Please enter a minimum playtime: 60

ALL GAMES W/ minPlayers >= 3 AND minimumPlaytime >= 60 BELOW

betrayal_at_baldur's_gate (2017) [IR=0, PR=6.45056, MP=3, MT=60]
betrayal_at_house_on_the_hill (2004) [IR=7.5, PR=6.87405, MP=3, MT=60]
blood_rage:_5th_player_expansion (2015) [IR=7.5, PR=6.99356, MP=5, MT=60]
kingsport_festival (2014) [IR=8, PR=6.21358, MP=3, MT=90]
shadows_over_camelot (2005) [IR=7.5, PR=6.9916, MP=3, MT=60]
sheriff_of_nottingham (2014) [IR=7, PR=7.05597, MP=3, MT=60]



Select an Option:
	1)Print all games (ordered as provided)
	2)Print all games from a specific year
	3)Print all games in a ranking range(Individual)
	4)The People VS Individual
	5)Find a game to play
	6)Exit the Program
Enter Selection: 3


Please enter the lower/upper bounds for the range.
Acceptable values range from 0.0 - 10.0, decimals allowed.

Input lower bound: 9


Input upper bound:  8


Bad Input. Need 0-10 w/ upperBound>lowerBound



Please enter the lower/upper bounds for the range.
Acceptable values range from 0.0 - 10.0, decimals allowed.

Input lower bound: 1


Input upper bound:  2

ALL GAMES IN RANGE: [2 >= Individual Rank(IR) >= 1] BELOW

carcassonne:_the_dice_game (2011) [IR=1, PR=5.29272, MP=2, MT=10]
hanabi (2010) [IR=1.5, PR=7.02297, MP=2, MT=25]
quiddler (1998) [IR=1.5, PR=5.83363, MP=1, MT=30]
t.i.m.e_stories:_estrella_drive (2017) [IR=1, PR=6.37211, MP=2, MT=90]
t.i.m.e_stories:_under_the_mask (2016) [IR=2, PR=6.81238, MP=2, MT=90]



Select an Option:
	1)Print all games (ordered as provided)
	2)Print all games from a specific year
	3)Print all games in a ranking range(Individual)
	4)The People VS Individual
	5)Find a game to play
	6)Exit the Program
Enter Selection: 6


Exiting Program...

```
