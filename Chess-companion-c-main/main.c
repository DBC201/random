#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main()
{
    int selection=0;
    do{
    printf("Press 1 for side picker, 2 for Chess960 generator, 3 to quit.\n");
    scanf(" %d", &selection);
        
    if(selection==1)
    {
        int side;
        side=rand()%2+1;
        if(side==1){puts("You play as white.");}
        else if(side==2){puts("You play as black.");}
        else{puts("Unknown error.");}

    }else if(selection==2)
    {
    int c;
    pieces();
    pawns();
    for(c=0;c<4;c++){
        row();
    }
    pawns();
    pieces();
    }
    }while(selection!=3);
    return 0;
}


