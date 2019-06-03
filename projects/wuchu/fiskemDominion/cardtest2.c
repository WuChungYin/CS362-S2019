#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

//unit test for council room card
int main (int argc, char** argv) {
   struct gameState G;
   int kingCards[] = {gardens, adventurer, mine, remodel, great_hall, village, baron, council_room};
   initializeGame(1, kingCards, 100, &G);
   int currentPlayer = 0; //initializing current player by presetting to certain player
   int handPos = 0; //initializing hand position by presetting to 0

   G.handCount[0] = 0;
   printf("initial hand count = %d\n", G.handCount[currentPlayer]);
   //cardEffect(council_room, -1, -1, -1, &G, 0, 0);
   playCouncilRoom(currentPlayer, &G, handPos);
   printf("final hand count = %d\n", G.handCount[currentPlayer]);
   //normally, player should draw 4 cards for council room being played
   if(G.handCount[0] == 4){
      printf("Card Test 2 passed successfully!\n");
   }else{
      printf("Card Test 2 failed!\n");
   };
}
