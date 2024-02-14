#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void roller(int roll[5], int size, int start);
int checker(int roll[5], int check, int start);

int main(){
    srand(time(NULL));                  //initialization
    int roll[5];
    int i =0;
    int ship=0;
    int capt =0;
    int crew =0;
    int rollc=0;

    roller(roll, 5, 0);                 // first roll
    

    while(rollc<3){
    rollc++;                                //increment roll
    ship=checker(roll, 6, 0);               //checking rolls for 6
    if (ship==1){
        printf("You have a ship! \n");
        capt=checker(roll, 5, 1);           // checking roll for 5
        if (capt==1){
            printf("You have a captain! \n");
            crew=checker(roll,4,2);             //check roll for 4
            if(crew==1){
                printf("You have a crew! \n");  //leave loop if all are present
                break;
            }
            else{

                if(rollc==3){                       //Leave if on roll 3 or roll again
                    break;
                }
                roller(roll,5,2);
                
                crew=checker(roll,4,2);             //Check again
                if(crew==1){
                 printf("You have a crew! \n");
                 rollc++;
                break;
                }
            
            }
        }
        else{
            if(rollc==3){                           //leaves if on roll 3
                break;
            }
            roller(roll,5,1);
            
        }
    } 
    else{                                          //Leaves if on roll 3
        if(rollc==3){
            break;
        }
        roller(roll, 5, 0);
       
    } 
    }

    printf("Your Final Hand: ");
    for(i=0;i<5; i++){
        printf("%d", roll[i]);
    }

    int p1points = roll[3]+roll[4];
    if(crew==1){                                                                       //Will need to be changed, to add on more players
        printf("\nYou have %d points, you have %d rolls left \n", p1points, 3-rollc);
        if(rollc<3){
            printf("Would you like to roll or hold?");
        }
    }


return 0;
}



void roller(int roll[5], int size, int start)
{int i;
    
    for(start; start<size; start++){
        roll[start]=rand()%(6)+1;
    }

    printf("Current Roll:");
    for(i=0; i<5; i++){
        printf("%d", roll[i]);
    }
    printf("\n");
}

int checker(int roll[5], int check, int start){
    int T=0;
    int found = 0;
    int temp;
    for(start;start<5;start++){
        if(roll[start]==check){
            T=1;
            found = roll[start];
            break;
        }
    }

    if(T==1){

         if (check==6){
        temp = roll[0];
        roll[0]=found;
        roll[start]=temp;
        }
        if (check==5){
            temp = roll[1];
            roll[1]=found;
            roll[start]=temp;
        }
        if (check==4){
        temp = roll[2];
        roll[2]=found;
        roll[start]=temp;
         }
        return 1;
    }
    else{
        return 0;
    }

}