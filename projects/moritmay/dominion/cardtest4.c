//card test 3
//check great hall implementation

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
  struct gameState previousState;
  int k[10] = {adventurer, gardens, embargo, village, great_hall, mine, cutpurse,
	       sea_hag, tribute, smithy};
  int p;
  srand(time(0));
  
  //randomize number of players from 2-4
  p = (rand()%3) + 2;

  initializeGame(p, k, rand(), &state);

  int actions = state.numActions;
  int pActions = previousState.numActions;
  
  pActions = actions;
  cardEffect(great_hall, 0, 0, 0, &state, NULL, NULL);
  if (pActions != actions){
      printf("great hall test failed\n");
  }
  else {
      printf("great hall test passed\n");
  } 

  return 0;
}
