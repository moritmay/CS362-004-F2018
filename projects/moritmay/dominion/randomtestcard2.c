//random test card 2
//validating that the state of whose turn is correct
  

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
  
  for (int testRun = 0; testRun < 200; testRun++){
    //randomize number of players from 0-5
    p = (rand()%6);

    initializeGame(p, k, rand(), &state);
    int player = whoseTurn(&state);

    if (player > state.numPlayers || p == 0){
        printf("whoseTurn test failed\n");
    }
    if (player < state.numPlayers) {
        printf("whoseTurn test passed\n");
    }
    else if (player == 0){
	printf("whoseTurn test failed\n");
    }	  

  }
  return 0;
}
