//card test 3
//check garden implementation

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

  int turn = whoseTurn(&state);
  int pTurn = whoseTurn(&previousState);

  previousState = state;
  cardEffect(gardens, 0, 0, 0, &state, NULL, NULL);
  //if (&previousState == &state){
  if (turn == pTurn){
      printf("garden test passed\n");
  }
  else {
     printf("garden test failed\n");
  }


  return 0;
}

