//
//  main.c
//  sharkGame
//


#include <stdio.h>

// ----- EX. 1 : Preparation------------
// Include header for using the rand() and srand() functions.
#include <stdlib.h>
#include <time.h>


// ----- EX. 1 : Preparation------------
#include "board.h"


// ----- EX. 4 : player ------------
#define N_PLAYER            3


// ----- EX. 4 : player ------------
#define MAX_CHARNAME        200


// ----- EX. 3 : board ------------
#define MAX_DIE             6


// ----- EX. 4 : player ------------
#define PLAYERSTATUS_LIVE   0
#define PLAYERSTATUS_DIE    1
#define PLAYERSTATUS_END    2


int player_position[N_PLAYER];
char player_name[N_PLAYER][MAX_CHARNAME];
int player_coin[N_PLAYER];
int player_status[N_PLAYER]; //0 - live, 1 - die, 2 - end
char player_statusString[3][MAX_CHARNAME] = {"LIVE", "DIE", "END"};

// ----- EX. 3 : board ------------
int rolldie(void)
{
    return rand()%MAX_DIE+1;
}


// ----- EX. 1 : Preparation------------
void opening(void)
{
    printf("==============================================================\n");
    printf("==============================================================\n");
    printf("==========                SHARK GAME!!!                =======\n");
    printf("==============================================================\n");
    printf("==============================================================\n");
}

// ----- EX. 6 : game end ------------
int game_end(void)
{
    int i;
    int flag_end = 1;
    
    //if all the players are died?
    for (i = 0; i < N_PLAYER; i++) {
    	
        if (player_status[i] == PLAYERSTATUS_LIVE || player_status[i] == PLAYERSTATUS_END) {
            return 0; // Continue the game if at least one player is still playing
        }
    }
    
    return flag_end;
}


// ----- EX. 4 : player ------------
void printPlayerPosition(int player)
{
    int i;
    
    for (i=0;i<N_BOARD;i++)
    {
        printf("|");
        if (player_position[player] == i)
            printf("%c", player_name[player][0]);
        else
        {
            if (board_getBoardStatus(i) == BOARDSTATUS_NOK)
                printf("X");
            else
                printf(" ");
        }
    }
    printf("|\n");
}

void printPlayerStatus(void)
{
    int i;
    printf("\nplayer status ---\n");
    for (i=0;i<N_PLAYER;i++)
    {
        printf("%s : pos %i, coin %i, status %s\n", player_name[i], player_position[i], player_coin[i], player_statusString[player_status[i]]);
        printPlayerPosition(i);
    }
    printf("-----------------\n");
}


// ----- EX. 5 : shark ------------
void checkDie(void)
{
    int i;
    for (i = 0; i < N_PLAYER; i++) {
        if (player_status[i] == PLAYERSTATUS_LIVE && board_getBoardStatus(player_position[i]) == BOARDSTATUS_NOK) {
            printf("%s in pos %i has died!! (coin %i)\n", player_name[i], player_position[i], player_coin[i]);
            player_status[i] = PLAYERSTATUS_DIE;
        }
    }
}



// ----- EX. 6 : game end ------------
// Get the number of players that survived
int getAlivePlayer(void)
{
    int i, alive_count = 0;

    for (i = 0; i < N_PLAYER; i++) {
        // Include live players
		if (player_status[i] == PLAYERSTATUS_LIVE || player_status[i] == PLAYERSTATUS_END) { 
            alive_count++;
        }
    }
    return alive_count;
}


/*
Game end conditions based on the number of alive players and coin comparison

1. Win if one of the three survived
2. If 2 survive, compare the number of coins to win
3. If all 3 survive, compare the number of coins to win
(If the number of coins is the same, the person who arrived earlier wins)
4. No winners if all did not survive
*/

int getWinner(void)
{
    int i;
    int winner =-1;
    int max_coin = -1;
    int earliest_finish = N_BOARD +1; // A value larger than the maximum board position
    
    

    for (i = 0; i < N_PLAYER; i++) {
		// Only consider live players 
        if (player_status[i] == PLAYERSTATUS_LIVE || player_status[i] == PLAYERSTATUS_END) {
            // Check if the player has collected more coins than the current maximum
            // OR if they have collected the same number of coins but finished earlier
            if (player_coin[i] > max_coin || 
                (player_coin[i] == max_coin && player_position[i] < earliest_finish)) {
                max_coin = player_coin[i]; // Update the maximum coins
                earliest_finish = player_position[i]; // Update the earliest finish position
                winner = i; // Set the current player as the winner
            }
        }
    }
    	
    return winner;
}


// ----------main------------
int main(int argc, const char * argv[]) {
    
    int i;
    int turn=0;
	int numTurns = 0; // Add a counter for the number of turns taken by players

// ----- EX. 1 : Preparation------------
// Call the rand initialization function to generate random numbers differently each time.
	srand((unsigned)time(NULL));
    opening();


// ----- EX. 2 : structuring ------------
    //step1 : initialization
    //step1-1 : board initialization
    board_initBoard();


// ----- EX. 4 : player ------------
    //step1-2 : initialize player
    for (i=0;i<N_PLAYER;i++)
    {
    	// Initialize various variable values (position, coin, status)
        player_position[i] = 0;
        player_coin[i] = 0;
        player_status[i] = PLAYERSTATUS_LIVE;
        
        // Get a user's name
        printf("Player %i's name: ", i);
        scanf("%s", player_name[i]);
    }


// ----- EX. 4 : player ------------  
    //step 2. : game start, turn loop
    do {
    	
        int dieResult;
        int dum;


// ----- EX. 4 : player ------------
    	// Skip players who are not alive
    	if (player_status[turn] != PLAYERSTATUS_LIVE) {
        	turn = (turn + 1) % N_PLAYER; // Skip this player and move to the next
        	continue;
    	} 
        
// ----- EX. 4 : player ------------     
        //step 2-1. status printing
        printPlayerStatus();

// ----- EX. 3 : board ------------
        board_printBoardStatus();

// ----- EX. 4 : player ------------
        //step 2-2. rolling die
        printf("%s turn!! ", player_name[turn]); // Output player turn
        printf("Press any key to roll a die!\n");
        scanf("%d", &dum);
        fflush(stdin); 
        
// ----- EX. 4 : player ------------
        dieResult = rolldie(); // Calling a function to receive input and roll the dice
        
		//step 2-3. moving
		if (player_position[turn] + dieResult >= N_BOARD) {
			player_position[turn] = N_BOARD - 1; // Move to the last position
    		player_status[turn] = PLAYERSTATUS_END; // Mark player as finished
			printf("%s has reached the end of the board!\n", player_name[turn]);
		} 
		else {
    		player_position[turn] += dieResult; // Regular movement
		}

        
		// ----- EX. 4 : player ------------
		//step 2-4. coin
		int pos = player_position[turn]; // Save the moved location
		
		// Call board_getBoardCoin function to obtain number of coins
		int coinsAtPosition = board_getBoardCoin(pos);  // Use the function to get the coin count
		
		if (coinsAtPosition > 0) {
			printf("\n%s picked up %d coins at position %d!\n", player_name[turn], coinsAtPosition, pos);
			player_coin[turn] += coinsAtPosition;  // Add the coins to the player's total
		}
		
		//step 2-5. end process
		
		// Check if player died (if on a shark position before a shark moves)
        checkDie();
        
        // Move to the next player's turn
		if (player_status[turn] == PLAYERSTATUS_LIVE) {
			turn = (turn + 1) % N_PLAYER;
		}

        // All players completed their turn-> move the shark.
        numTurns++;
        
        if (numTurns == N_PLAYER) {
            int shark_pos = board_stepShark();  // Move shark
            printf("\nShark moved to position %i\n", shark_pos);

            // Check for any deaths caused by the shark
            checkDie();

            numTurns = 0;  // Reset the number of turns after the shark moves
        }
        
// ----- EX. 6 : game end ------------
   } while(game_end() == 0);

	// step 3. game end process
	printf("\nGAME END!!\n");

	// Determine the winner after the game ends
	int winner = getWinner();

	if (winner == -1) {
    	printf("No players survived. No winner!\n");
	} 
	else {
    	printf("%i players are alive! Winner is %s\n", getAlivePlayer(), player_name[winner]);
	}

// ----- EX. 2 : structuring ------------
	return 0;
}
