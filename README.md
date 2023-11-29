# Customizable Minesweeper - ENGG1340_G49
  * Welcome to the Customizable Minesweeper! This game is a text-based Minesweeper on terminal.
  * You'll get the best experience when you play it in full screen!
  *  3 Minute Demo Video:
https://drive.google.com/file/d/1R31jnlWmTR8BvFU3qrMjXsqNovDcqUIV/view?usp=sharing 

  
## Team Members:
  * Park Chanhyuk (3036086804)
  * Sohn Ye Ryung (3036050312)
  * Kim Minju (3035978531)
  * Jung SeYeon (3036050518)

<br/>

### How to Compile and Run
1. Change directory to the downloaded game folder on terminal.
2. Type "make game"
3. Type "./game" to launch the game
4. Type "make clean" if you want to delete saved scores of the players.


### How to Play
1.	Compile and run the program.
2.	Enter '1' to start the game, and enter '2' to view the leaderboard of the highest scores recorded.
3.	If you input '1', you need to input the number of rows and columns to set the board size.
4.	Enjoy!


### The rules of the game
1. Choose a cell by pressing 'WASD' keys and 'Enter' to move the cursor, and press 'o' to uncover your first cell and start the game.
2. The number on each cell represents the number of mines around the cell.
3. Uncover a cell if you think it does not have a mine by pressing 'o' and then 'Enter'.
4. Flag a cell if you think it has a mine by pressing 'p' and then 'Enter'.
5. If you uncover a mine, you will lose 200 points.
6. To end the game, uncover or flag all the cells, or press 'm' and 'Enter' to quit mid-game.

<br/>

### **Game Components**
1.	main.cpp: The `main.cpp` file contains the main game loop and logic.

2.	mechanics.cpp: The `mechanics.cpp` file contains the main logic of the game.

4.	display.cpp: The `display.cpp` file contains the display of the game.

5.	score.cpp: The `score.cpp` file 

<br/>

### **Dependencies**
* C++ Standard Library
* `<iostream>`
* `<string>`
* `<vector>`
* `<fstream>`
* `<cstdlib>`
* `<ctime>`
* `<algorithm>`

<br/>

***
## Components

### Main.cpp
> Running the game and supporting file input and output

|Name|Type|Purpose|
|:-:|:-:|:-:|
|runGame|void|runs the main game|


### mechanics.cpp
> various functions we created to run the game

|Name|Type|Purpose|
|:-:|:-:|:-:|
|column|int|the number of columns of the customized board|
|row|int|the number of rows of the customized board|
|numberOfFlags|int|the number of flags left to use|
|numberOfMines|int|the number of mines on the board|
|currentScore|int|counts the current score of the player|
|xLocation|int|expresses the xLocation of the player on the board|
|yLocation|int|expresses the yLocation of the player on the board|
|**mineBoard|char|Dynamically created 2-d array which represents a board filled with randomly scattered mines|
|**playerBoard|char|Dynamically created 2-d array which presents a board which reflects the player's input|
|setBoardSize|void|takes player input for row and column|
|setBoard|void|generates a board with from the player input|
|placeMines|void|randomly places the mines on the board, except for the 3x3 grid surrounding the player's first reveal.|
|delDynamic|void|destroys the dynamically created 2-d array objects|
|printBoard|void|prints the board for the player|
|getPlayerInput|char|gets the player input and processes the command|
|uncover|void|uncovers the mine underneath, or generates the number of surrounding mines|
|flagging|void|flags where the player's cursor is located|
|endGame|void|at the end of the game, get the player's name to save the final score to the leaderboard|
|leaderboard|void|displays the leaderboard|
|checkEndGame|bool|checks if all the cells are revealed, ends the game if all the cells are revealed|


### display.cpp
> various functions that we created to display the game

|Name|Type|Purpose|
|:-:|:-:|:-:|
|displayBanner|void|displays the banner minesweeper|
|mainMenu|void|displays the main menu of the game|
|displayControls|void|displays the directions to play the game|
|displayFlags|void|displays the current score and number of flags left|
|displayEnding|void|displays the ending message|


### score.cpp
> various functions that set the scoreboard and print it

|Name|Type|Purpose|
|:-:|:-:|:-:|
|printScoreboard|void|Prints scoreboard with recorded player's name and points|
|compareScores|void|Compares two Score objects based on their record member variable|
|sortScores|void|Sorts the scores from highest to lowest|
|saveScoreboard|void|Saves the contents of the scoreboard vector to a file named "scoreboard.txt"|
|updateScoreboard|void|Updates the scoreboard by adding a new Score entry with the given playerName and points|
|loadScoreboard|void|Loads the contents of a scoreboard file named "scoreboard.txt" into a vector scoreboard|


<br/>


### The Coding Requirements
>Coding requirement demonstration

|Requirenment name|Explanation|
|:-:|:-:|
|Generation of random game sets or events|The placeMines() function simulates a random distribution of mines at the rows and columns by generating a random integer.|
|Data structures for storing game status|By using the custom data structure 'Board', the program stores many variables to store the game status such as the state of the player board, the current score, the current location of the player's cursor, etc.|
|Dynamic memory management| To make the customizable board, our group has dynamically allocated memory for the 2D arrays named **mineBoard and **playerBoard|
|File input/output (e.g., for loading/saving game status)|To save the name and points of players, the data was appended to the textile "scoreboard.txt" and loaded/updated the file each game.|
|Program codes in multiple files| Our group divided our code to multiple files in terms of their purposes.|
|Proper indentation and naming styles| We have done proper indentation, and named the functions so the names represent their function in the code.|
|In-code documentation| we have put explanations for codes to help the reader's understanding.|
