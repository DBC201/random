#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int c;
void pawns(){
    for(c=0;c<8;c++)
        {
            if(c==7)
            {
                printf("P\n");
            }else{printf("P ");}
        }
}
void row(){
         for(c=0;c<8;c++)
        {
            if(c==7)
            {
                printf("|\n");
            }else{printf("| ");}
        }
}
void pieces(){
        char pieces[9]="KQNNBBRR";
        int temp,r;
        int pos[8];
        srand(time(NULL));
        for(c=0;c<8;c++)
        {
            pos[c]=c;
        }
        for(c=0;c<8;c++)
        {
         r=rand()%8;
         temp=pos[r];
         pos[r]=pos[c];
         pos[c]=temp;
        }
        for(c=0;c<8;c++)
        {
            if(c==7)
            {
                printf("%c\n", pieces[pos[7]]);
            }else{printf("%c ", pieces[pos[c]]);}
        }
}
