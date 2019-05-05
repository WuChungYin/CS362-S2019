#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

//tests great_hallPlayed() in dominion.c
int main (int argc, char** argv) {
   struct gameState G, test;
   int kingCards[] = {gardens, adventurer, mine, remodel, great_hall, village, baron, council_room};
   initializeGame(1, kingCards, 100, &G);

   memcpy(&test, &G, sizeof(struct gameState));
   test.numActions = 0;
   villagePlayed(0, &test, 0);
   //normally, numActions should be increased by 1
   if(test.numActions == 1){
      printf("Unit Test 2 passed successfully!\n");
      }else{
         printf("Unit Test 2 failed!\n");
         };
   }
