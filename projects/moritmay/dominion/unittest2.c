//unit test 2
//check whoseTurn function

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
  int player = whoseTurn(&state);

  if (player > state.numPlayers){
    printf("whoseTurn test failed\n");
  }
  else if (player < 0){
    printf("whoseTurn test failed\n");
  }
  else {
    printf("whoseTurn test passed\n");
  }
  return 0;
}


