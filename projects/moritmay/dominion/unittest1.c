//unit test 1
//check isGameOver function

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <time.h>
#include <stdlib.h>

int main(){
    struct gameState state;
    int k[10] = {adventurer, gardens, embargo, village, great_hall, mine, cutpurse,
	       sea_hag, tribute, smithy};
    int p;
    srand(time(0));
    int  go = isGameOver(&state);
    
    //randomize number of players from 2-4
    p = (rand()%3) + 2;

    initializeGame(p, k, rand(), &state);

    if (state.supplyCount[province == 0]) {
        if (go == 1){
            printf("province card exhausted to end game, and isGameOver test passed\n");
        }        
        else {
            printf("province card exhausted to end game, and isGameOver test failed\n");
        }
    }
    else {
        int j = 0;
        for (int i = 0; i<30; i++){
            if (state.supplyCount[i] == 0){
                j++;
            }
        }
        if (j > 2){
            if (go == 1){
                printf("at least 3 supply piles are empty to end the game, and isGameOver test passed\n");
            }
            else {
                printf("at least 3 supply piles are empty to end the game, and isGameOver test failed\n");
            }
        }
        else{
            printf("game is not over and isGameOver test passed\n");
        }
    } 
    return 0;
}

