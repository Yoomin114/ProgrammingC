//
//  board.c
//  sharkGame
//

#include "board.h"

// ----- EX. 3 : board ------------
#define N_COINPOS       12 // Number of coins allocated to a game
#define MAX_COIN        4 // Maximum number of coins that can fit in a board

// ----- EX. 5 : shark ------------
#define MAX_SHARKSTEP   6  //The maximum number of boards a shark can advance on is 6.
#define SHARK_INITPOS   -4 //Set the shark's initial position to board -4

// ----- EX. 3 : board ------------
static int board_coin[N_BOARD];
static int board_status[N_BOARD];
//0 - OK, 1 - destroyed

static int shark_position;


// ----- EX. 3 : board ------------
// Prints the current status of the board.
// Depending on the array value of the board_status, it will output O or X.
void board_printBoardStatus(void)
{
    int i;
    
    printf("----------------------- BOARD STATUS -----------------------\n");
    for (i=0;i<N_BOARD;i++) { //Our definition of N_BOARD is 20
    
        printf("|"); // Use | to divide the board.
        if (board_status[i] == BOARDSTATUS_NOK) // If the status of the board is NOT OKAY, it has 1. 
            printf("X"); // Print X because it was eaten by a shark.
        else
            printf("O"); // Since it is the surviving board, it prints O.
    }
    
    printf("\n");
    printf("------------------------------------------------------------\n");
}

// Board Initialization Function
int board_initBoard(void)
{
    int i, randomPos;
    
    // Initialize board variables
    for (i = 0; i < N_BOARD; i++) {
        board_status[i] = BOARDSTATUS_OK; // Set board status to "OK"
        board_coin[i] = 0;               // Initialize coins to 0
    }
    
// ----- EX. 5 : shark ------------
    shark_position = SHARK_INITPOS;

    //coin allocation
    for (i = 0; i < N_COINPOS; i++) {
        while (1) { // Loop until a valid position is found
            randomPos = rand() % N_BOARD; // Random position within the board range

            // Check if a coin is already placed in the random position
            if (board_coin[randomPos] == 0) {
                board_coin[randomPos] = 1 + (rand() % MAX_COIN); // Assign a random coin value (1 to MAX_COIN)
                break; // Exit the loop once a valid position is assigned
            }
        }
    }
    
    return N_COINPOS;
}

// ----- EX. 5 : shark ------------
// Shark Movement Function
int board_stepShark(void)
{
    shark_position += rand() % MAX_SHARKSTEP + 1; // // Randomly move 1 to 6 spaces
    if (shark_position >= N_BOARD) {
        shark_position = N_BOARD - 1; // Processing not to cross the end of the board
    }
    
    return shark_position;
}


// ----- EX. 3 : board ------------
/*
static int board_status[N_BOARD];
static int board_coin[N_BOARD];
These arrays are used only inside board.c and should not be accessed directly by other files.
Instead, you must interact with them through functions
such as 'board_getBoardStatus' and 'board_getBoardCoin'.
*/

int board_getBoardStatus(int pos)
{
    return board_status[pos];  // Returns the status of the board at position `pos`
}

int board_getBoardCoin(int pos)
{
    int coin = board_coin[pos]; 
    board_coin[pos] = 0;         // Sets the coin count at the specified position to 0
    return coin;                 // Returns the number of coins at the specified positions
}


