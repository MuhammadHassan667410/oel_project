# [VAULT ESCAPE]

## [INTRODUCTION OF THE GAME]
This program is a console game based on codes and puzzles. The player is locked inside a secret vault and has to clear 6 levels to escape. Every level has a different puzzle, like unscrambling a word, decoding a secret message, finding a number pattern or catching a murderer. The levels start easy and get harder as the player moves ahead. We built a points system, so the player earns more points for solving a level in fewer tries, and at the end the total score decides if the player escapes the vault or not.

## CODE and LOGIC EXPLANATION
The code is divided into different files so that it is easy to understand and change. Every level is written in its own `.cpp` file, and the main file just runs them one by one.

* `main.cpp` : the main file of the game. It shows the instructions, runs all 6 levels, adds up the points and decides the result.
* `games.h` : the header file that has the prototypes of all 6 game functions, so `main.cpp` can call every level.
* `word_swap.cpp` : Level 1
* `swap_game.cpp` : Level 2
* `number_pattern.cpp` : Level 3
* `ASCII_game.cpp` : Level 4
* `reverse_shift.cpp` : Level 5
* `murder.cpp` : Level 6

The program starts by defining the values that are used again and again, like the total number of levels, the passing score and the maximum score. After that, the instructions are printed to tell the player the story, the levels, how the points work and the rules of the game. Then the game starts and the levels are played one by one. If the player fails any level, the player dies and the game is over. If the player passes all 6 levels, the total score is checked.

### Working of the levels: The logic of every level is described below.
* **Level 1 - Word Swap (Easy):** The letters of a word are mixed up and the player has to put them back in the right order. The player gets a hint and 3 tries. Capital or small letters both work.
* **Level 2 - Symmetric Mirroring (Easy):** Every letter of the word is swapped with its mirror letter in the alphabet (A for Z, B for Y and vice versa). The player has to find the original word in 3 tries.
* **Level 3 - Number Pattern (Medium):** A pattern of fractions is shown and the player has to find the next fraction. The player enters the top number and the bottom number separately, with 3 tries. In this pattern, every number is the sum of the two numbers before it.
* **Level 4 - ASCII Decoding (Medium):** A list of ASCII numbers is shown and the player has to turn them back into a word. A hint of the ASCII values of the letters is given. Capital and small letters matter in this level, so the word has to be typed exactly. The player has 3 tries.
* **Level 5 - 3-Step Reflection (Hard):** A harder code that mixes mirroring and shifting of letters. The player has 3 tries but only 120 seconds in total. The time left is shown on the screen, and if the time is over the level is failed.
* **Level 6 - Detective (Hard):** A businessman has been murdered and there are two suspects, Ali and Saad. The player has only 60 seconds. First the player can look at 3 clues (footprint, watch and CCTV), then question one of the suspects, and in the end the player has to accuse one of them. There is only ONE accusation and no extra tries. If the player catches the right person in time, the level is cleared.

### Working of points: The points depend on in which try the player solved the level.
* **Easy levels (Level 1 and 2):** 5 points on the 1st try, 3 on the 2nd try and 1 on the 3rd try.
* **Medium levels (Level 3 and 4):** 10 points on the 1st try, 7 on the 2nd try and 4 on the 3rd try.
* **Hard level (Level 5):** 15 points on the 1st try, 11 on the 2nd try and 7 on the 3rd try.
* **Hard level (Level 6):** 15 points if the case is solved. This level has no tries, so the points are always 15.

If the player fails a level, no points are given for that level.  
The maximum points possible are 60.

### Winning and losing: The rules of the game are explained below.
* If the player fails any level, the player dies and the game is over.
* If the player passes all 6 levels and has 45 or more points, the vault door opens and the player escapes.
* If the player passes all 6 levels but has less than 45 points, the vault resets and the player has to start again from Level 1 with the score back at 0.

To keep the code simple, one function called `getPoints` is used to give the points of every level, and one function called `playLevel` is used to run a level and add its points to the score. The score is passed by reference so the points are added to the real score in main. Every level function returns true if the level was passed and false if it was not, and it also tells main how many tries were used, so the points can be given correctly.

## GROUP MEMBERS AND CONTRIBUTIONS:
We made a group of 3: Fatima Nasir (598914), Azka Qasim (587467) and Muhammad Hassan (587571). We divided the whole project among each other. The initial logic of the game was collectively made by all of us including the level difficulties, the scoring system and the puzzles for each level after that the code of 6 levels was evenly divided among all three of us. The final main file was designed by Muhammad Hassan, the brief report was curated by Fatima Nasir and the README file was made by Azka Qasim.

GitHub repo link: https://github.com/MuhammadHassan667410/oel_project

## USE OF AI:
The entire game logic and code were developed collectively by our group without any use of AI. However, for the hard levels, we used AI assistance specifically to incorporate countdown timers of 120 seconds and 60 seconds to make the game more interactive and challenging, as well as to distinguish the hard levels from the easy ones. After implementing the timers, we made sure to understand and learn the code and logic behind the countdown mechanism ourselves.
