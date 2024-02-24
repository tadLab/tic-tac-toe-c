#include <stdio.h>
#include <stdbool.h>

// Check if the move is valid and can be placed
bool isValidMove(char positions[3][3], char move) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (positions[i][j] == move) {
                return true;
            }
        }
    }
    return false;
}

// Check if there is a winner in rows
bool checkRows(char positions[3][3], char symbol){
    for(int rows = 0; rows < 3; rows++){
        int count = 0;
        for(int coloumns = 0; coloumns < 3; coloumns++){
            if(positions[rows][coloumns] == symbol){
                count++;
            }
        }
        if(count == 3){
            return true;
        }
    }
    return false;
}

// Check if there is a winner in columns
bool checkColumns(char positions[3][3], char symbol){
    for(int columns = 0; columns < 3; columns++){
        int count = 0;
        for(int rows = 0; rows < 3; rows++){
            if(positions[rows][columns] == symbol){
                count++;
            }
        }
        if(count == 3){
            return true;
        }
    }
    return false;
}

// Check if there is a winner in diagonals
bool checkDiagonals(char positions[3][3], char symbol){
    int countMain = 0;
    int countSecondary = 0;
    for(int i = 0; i < 3; i++){
        if(positions[i][i] == symbol){
            countMain++;
        }
        if(positions[i][2 - i] == symbol){
            countSecondary++;
        }
    }
    return (countMain == 3 || countSecondary == 3);
}

// Check if there is a winner 
bool isWinner(char positions[3][3], char symbol){
    return (checkRows(positions, symbol) || checkColumns(positions, symbol) || checkDiagonals(positions, symbol));
}

// Check if it's a draw
bool isDraw(char positions[3][3]){
    for(int rows = 0; rows < 3; rows++){
        for(int columns = 0; columns < 3; columns++){
            if(positions[rows][columns] != 'X' && positions[rows][columns] != 'O'){
                return false; 
            }
        }
    }
    return true; 
}

// Create a board for Tic Tac Toe
void board(char positions[3][3]){
    printf("\nTIC TAC TOE \n");
    printf("Player 1 (X) - Player 2 (O)\n");
    printf("\n %c | %c | %c \n", positions[0][0], positions[0][1], positions[0][2]);
    printf("-----------\n");
    printf(" %c | %c | %c \n", positions[1][0], positions[1][1], positions[1][2]);
    printf("-----------\n");
    printf(" %c | %c | %c \n\n", positions[2][0], positions[2][1], positions[2][2]);
}

int main(int argc, char const *argv[]){
    char positions[3][3] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'},
    };

    char currentPlayer = 'X';
    int playerNumber = 1;

    board(positions);

    while (!isWinner(positions, 'X') && !isWinner(positions, 'O') && !isDraw(positions)) {
        char turn;
        bool validMove = false;
        while (!validMove) {
            printf("Player %d, enter a number: ", playerNumber);
            scanf(" %c", &turn);
            getchar(); 

            validMove = isValidMove(positions, turn);
            if (!validMove) {
                printf("Invalid move! Please choose an empty square.\n");
            }
        }

        // Renew the board
        for (int rows = 0; rows < 3; rows++) {
            for (int columns = 0; columns < 3; columns++) {
                if (turn == positions[rows][columns]) {
                    positions[rows][columns] = currentPlayer;
                }
            }
        }

        board(positions);

        // Change player
        if (currentPlayer == 'X') {
            currentPlayer = 'O';
            playerNumber = 2;
        } else {
            currentPlayer = 'X';
            playerNumber = 1;
        }
    }

    // Check if there's a winner or a draw
    if (isWinner(positions, 'X')) {
        printf("Player 1 is the winner!\n");
    } else if (isWinner(positions, 'O')) {
        printf("Player 2 is the winner!\n");
    } else {
        printf("It's a draw!\n");
    }

    return 0;
}