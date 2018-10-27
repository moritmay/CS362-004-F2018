//unit test 3
//check number of supplyCount function

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

    //randomize number of players from 2-4
    p = (rand()%3) + 2;

    initializeGame(p, k, rand(), &state);

    for (int i = 0; i < 26; i++){
        if (state.supplyCount[i]<0){
            printf("Negative number of cards, supplyCount test failed\n");
        }
        else {
            for (i = 1; i < 4; i++){
                if (state.supplyCount[i] > 12){
                    printf("Too many victory cards, supplyCount test failed\n");
                }
                else {
                    printf("Victory cards supplyCount test passed\n");
                }
            }
            for (i = 4; i < 7; i++){
                if (state.supplyCount[4] > 46 || state.supplyCount[5] > 40 || state.supplyCount[6] > 30){
                    printf("Too many treasure cards, supplyCount test failed\n");
                }
                else{
                    printf("Treasure cards supplyCount test passed\n");
                }
            }    
            for (i = 7; i < 26; i++){
                if (state.supplyCount[i] > 10){
                    printf("Too many action cards, supplyCount test failed\n");
                }
                else {
                    printf("supplyCount test passed\n");
                }
            }
        } 
    }

    return 0;
}

