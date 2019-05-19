#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int main () {
   int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
   struct gameState G;

   printf("Testing adventurer.\n");
   printf("RANDOM TESTS\n");

   SelectStream(2);
   PutSeed(3);
   //printf("still working 1\n");
   int n;
   for(n = 0; n < 1000; n++){
      //printf("still working 2\n");      
      int drawntreasure = rand() % 2;
      int m;
      for(m = 0; m < sizeof(struct gameState); m++){
         ((char*)&G)[m] = floor(rand() * 256);
      }
      int currentPlayer = rand() % 2;
      int z = random() % MAX_HAND;
      int temphand[MAX_HAND];

      int oldhandcount = G.handCount[currentPlayer];     
      adventurerPlayed(drawntreasure, &G, currentPlayer, temphand, z);
      if(G.handCount[currentPlayer] = oldhandcount + 2){
         printf("Adventurer random test passed!\n");
      }else{
         printf("Adventurer random test failed!\n");
      }
   }

}
