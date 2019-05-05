#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

//dominion card unit test for adventurer
int main (int argc, char** argv) {
   struct gameState G, test;
   int kingCards[] = {gardens, adventurer, mine, remodel, great_hall, village, baron, council_room};
   initializeGame(1, kingCards, 100, &G);

   memcpy(&test, &G, sizeof(struct gameState));
   //handcount should increase by two when player puts two treasure cards in hand for adventurer card played
   int temphand[MAX_HAND];
   test.handCount[2] = 0;
   adventurerPlayed(0, &test, 0, temphand, 0);
   //printf("hand count is %d\n", test.handCount[0]);
   if(test.handCount[0] == 2){
      printf("Card Test 1 passed successfully!\n");
   }else{
      printf("Card Test 1 failed!\n");
   };
}
