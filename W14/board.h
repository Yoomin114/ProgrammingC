//
//  board.h
//  sharkGame
//


#ifndef board_h
#define board_h

#include <stdio.h>
#include <stdlib.h>

// ----- EX. 3 : board ------------
// Define the size of the board users want to progress
#define N_BOARD                 20

//0 - OK, 1 - destroyed
// Definition of survival by sharks.
#define BOARDSTATUS_NOK          1
#define BOARDSTATUS_OK           0

// Designing Interface Functions
int board_initBoard(void); //board initialization.
int board_getBoardStatus(int pos); // Print the status of the entire board
int board_getBoardCoin(int pos); // Picking up coins in the pos board slot
int board_getSharkPosition(void);
int board_stepShark(void);
void board_printBoardStatus(void); // Print the damage to a specific slot

#endif /* board_h */
