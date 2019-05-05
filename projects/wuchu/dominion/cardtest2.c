#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

//unit test for council room card
int main (int argc, char** argv) {
   struct gameState G, test;
   int kingCards[] = {gardens, adventurer, mine, remodel, great_hall, village, baron, council_room};
   initializeGame(1, kingCards, 100, &G);
   G.handCount[0] = 0;

   memcpy(&test, &G, sizeof(struct gameState));
   printf("initial hand count = %d\n", test.handCount[0]);
   cardEffect(council_room, -1, -1, -1, &test, 0, 0);
   printf("final hand count = %d\n", test.handCount[0]);
   //normally, player should draw 4 cards for council room being played
   if(test.handCount[0] == 4){
      printf("Card Test 2 passed successfully!\n");
      }else{
         printf("Card Test 2 failed!\n");
         };
   }
