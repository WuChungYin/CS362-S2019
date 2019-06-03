#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
//random test for adventurer
int main () {
   int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
   struct gameState G;

   printf("Testing adventurer.\n");
   printf("RANDOM TESTS\n");

   SelectStream(2);
   PutSeed(3);

   int n;
   for(n = 0; n < 10; n++){
      //randomizing inputs for adventurerPlayed() function
      int m;
      for(m = 0; m < sizeof(struct gameState); m++){
         ((char*)&G)[m] = floor(rand() * 256);
      }
      int currentPlayer = rand() % 2;
      int handPos = random() % MAX_HAND;
      int temphand[MAX_HAND];

      //saving initial value of handcount, should be increased by 2 after drawing 2 treasure cards
      int oldhandcount = G.handCount[currentPlayer];       
printf("old handcount is %d\n", oldhandcount);        
      //executing adventurerPlayed() with randomized inputs
      playAdventurer(currentPlayer, &G, handPos, temphand); 
      //testing if handcount has been incremented by 2
printf("new handcount is %d\n", G.handCount[currentPlayer]);
      if(G.handCount[currentPlayer] == oldhandcount + 2){
         printf("Handcount has incremented by 2, PASS!\n");
      }else{
         printf("Handcount has not incremented by 2!\n");
         int incrementNum;
         incrementNum = G.handCount[currentPlayer] - oldhandcount;
         printf("Handcount has incremented by %d instead!\n", incrementNum);
      }
   }
}
