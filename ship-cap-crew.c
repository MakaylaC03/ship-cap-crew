#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "gamefunct.h"



int main(){
    srand(time(NULL));                  //initialization
    int roll[5];
    int i =0;
    int comp =0;
    int winner;
    int players = playercount();
    int score[players];
   

    for( int j = 0; j<players;j++){
    printf("\nStarting player %d\n", j+1);
    int play = 0;
    play = validplay(roll);

    printf("Your Final Hand: ");
    for(i=0;i<5; i++){
        printf("%d", roll[i]);
    }

    int points = roll[3]+roll[4];
    if(play==1){                                                                       //Will need to be changed, to add on more players
        score[j] = points;
    }
    else{
        score[j]=0;
    }

    handreset(roll);

    } 

    for(i=0;i<players; i++){
        printf("\nPlayer %d score: %d\n", i+1,score[i]);
        if(score[i]>comp){
            comp = score[i];
            winner = i+1;
        }
    }

    printf("Player %d wins with %d points\n", winner, comp);

return 0;
}

