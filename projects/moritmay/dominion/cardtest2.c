//card test 2
//check smithy card implementation

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
  int newNumCards = numHandCards (&state);
  int numCards = numHandCards(&previousState);
  
  previousState = state;
  cardEffect(smithy, 0, 0, 0, &state, NULL, NULL);
  if (&previousState == &state){
      printf("Smithy test failed\n");
  }
  else {
      if((numCards + 3) == newNumCards){
          printf("Smithy test passed\n");
      }
      else {
          printf("Smithy test failed\n");
      }
  }
  return 0;
}

