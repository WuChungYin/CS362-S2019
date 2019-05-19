#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
//random test for villagePlayed() function
int main () {
   int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
   struct gameState G;

   printf("Testing village.\n");
   printf("RANDOM TESTS\n");

   SelectStream(2);
   PutSeed(3);

   int n;
   for(n = 0; n < 1000; n++){
//setting up random values to input into villagePlayed()
      int currentPlayer = rand() % 2;
      int m;
      for(m = 0; m < sizeof(struct gameState); m++){
         ((char*)&G)[m] = floor(rand() * 256);
      }
      int handPos = rand() % MAX_HAND;
//storing initial value of numActions, should be increased by 2 after villagePlayed() is implemented
      int oldnumActions = G.numActions;
      villagePlayed(currentPlayer, &G, handPos);
//checking if numActions has indeed been increased by 2
      if(G.numActions == oldnumActions + 2){
         printf("Village random test passed!\n");
      }else{
         printf("Village random test failed!\n");
      }
   }
}
