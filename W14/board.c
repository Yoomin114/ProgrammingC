//
//  board.c
//  sharkGame
//

#include "board.h"

// ----- EX. 3 : board ------------
// 
#define N_COINPOS       12 // Number of boards where coins can be located
#define MAX_COIN        4 // Maximum number of coins
// ----- EX. 3 : board ------------

// ----- EX. 5 : shark ------------
#define MAX_SHARKSTEP   6  //The maximum number of boards a shark can advance on is 6.
#define SHARK_INITPOS   -4 //Set the shark's initial position to board -4
// ----- EX. 5 : shark ------------

// ----- EX. 3 : board ------------
static int board_coin[N_BOARD];
static int board_status[N_BOARD]; //0 - OK, 1 - destroyed
// ----- EX. 3 : board ------------
static int shark_position;


// ----- EX. 3 : board ------------
// Prints the current status of the board.
// Depending on the array value of the board_status, it will output O or X.
void board_printBoardStatus(void)
{
    int i;
    
    printf("----------------------- BOARD STATUS -----------------------\n");
    for (i=0;i<N_BOARD;i++) //Our definition of N_BOARD is 20
    
        printf("|"); // Use | to divide the board.
        if (board_status[i] == BOARDSTATUS_NOK) // If the status of the board is NOT OKAY, it has 1. 
            printf("X"); // Print an X because it was eaten by a shark.
        else
            printf("O"); // Since it is the surviving board, it prints O.
    }
    printf("|\n");
    printf("------------------------------------------------------------\n");
}

// Board Initialization Function
int board_initBoard(void)
{
    int i;
    
    //variable initialization
    for (i=0;i<N_BOARD;i++)
    {
        board_status[i] = BOARDSTATUS_OK;
        board_coin[i] = 0;
    }
    
    for (i=0; i<COINPOS; i++){
    	while ()
	}
    
// ----- EX. 5 : shark ------------
    shark_position = SHARK_INITPOS;
// ----- EX. 5 : shark ------------

    //coin allocation
   
    
    return N_COINPOS;
}
// ----- EX. 3 : board ------------


// ----- EX. 5 : shark ------------
int board_stepShark(void)
{

}
// ----- EX. 5 : shark ------------


// ----- EX. 3 : board ------------
int board_getBoardStatus(int pos)
{
    return board_status[pos];
    // Return board_status array elements
}

int board_getBoardCoin(int pos)
{
	
    int coin = board_coin[pos];
    //The action of picking up the coin in the posth board compartment
	
	board_coin[pos] = 0;
    return coin;
    // Returns the value of the board_coin array, making the array value 0.
}
// ----- EX. 3 : board ------------

