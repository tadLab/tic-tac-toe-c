
Tic-Tac-Toe Game in C

This is a simple implementation of the Tic-Tac-Toe game in C language. The game is played on a 3x3 grid where two players take turns marking their symbol (X or O) in an empty cell. The first player to get three of their symbols in a row, column, or diagonal wins the game.

How to Compile and Run

To compile the game, use the following command:

bash
Copy code
gcc -o tic_tac_toe tic_tac_toe.c
To run the compiled program, use:

bash
Copy code
./tic_tac_toe
Game Rules

The game is played on a 3x3 grid.
Player 1 uses 'X' and Player 2 uses 'O'.
Players take turns to place their symbol in an empty cell.
The first player to get three of their symbols in a row, column, or diagonal wins.
If all cells are filled and no player has won, the game is a draw.
How to Play

The game starts with an empty grid.
Players are prompted to enter the row and column where they want to place their symbol.
Input format is row number (1-3) followed by a space and then column number (1-3).
Players alternate turns until the game is won or it's a draw.
After each move, the current state of the board is displayed.
The game ends when a player wins or there are no more empty cells.
Sample Gameplay

markdown
Copy code
Welcome to Tic-Tac-Toe!

Player 1 (X) - Player 2 (O)

-------------
|   |   |   |
-------------
|   |   |   |
-------------
|   |   |   |
-------------
Player 1's turn (Enter row and column): 1 1

-------------
| X |   |   |
-------------
|   |   |   |
-------------
|   |   |   |
-------------
Player 2's turn (Enter row and column): 2 2

-------------
| X |   |   |
-------------
|   | O |   |
-------------
|   |   |   |
-------------
...

Enjoy playing Tic-Tac-Toe!
