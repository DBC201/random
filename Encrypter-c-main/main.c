#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "library.h"
#include "Fencrypt.h"
#include "Fdecrypt.h"
/*
-letters can be added by editing char alphabet
-for this program to work properly, both parties must have the same char array,
in the same exact order(located in library.h)
*/
int main()
{
    const int totalletter=strlen(alphabet)+1;//total amount of letters in alphabet
    int *Salphletters;//shuffled alphabet letters(in number)
    Salphletters=(int*)calloc(totalletter,sizeof(int));
    int quantity;
    int seed1,seed2;
    char *input;
    int selection='o';
    int *letterpos;
    FILE *fp;

    printf("Enter e to encrypt, d to decrypt:");
    scanf(" %c", &selection);
    if(selection=='e'||selection=='E'){
    printf("Currently supported characters:\n");
    PalphabetScreen(totalletter);

    fp=createRfile(fp);
    quantity=textlength(fp);
    input=(char*)calloc(quantity+1,sizeof(char));
    get_text(fp,input,quantity+1);
    fclose(fp);

    getmethod(&seed1,&seed2);

    letterpos=(int*)calloc(quantity,sizeof(int));

    randomizeInput(input,seed1,Salphletters,letterpos,totalletter,quantity);
    free(Salphletters);

    shuffleLetters(input,seed2,letterpos,quantity);
    free(input);

    fp=createWfile(fp);

    encryptOutput(fp,seed1,seed2,quantity,letterpos,totalletter);
    free(letterpos);
    fclose(fp);
    }else if(selection=='d'||selection=='D'||selection=='C'||selection=='c'){

    getseed(&seed1,&seed2);

    fp=createRfile(fp);
    quantity=textlength(fp);
    input=(char*)calloc(quantity+1,sizeof(char));
    get_text(fp,input,quantity+1);
    fclose(fp);

    letterpos=(int*)calloc(quantity,sizeof(int));

    readtext(input,letterpos,quantity,totalletter);
    free(input);

    unshuffleLetters(seed2,letterpos,quantity);

    char *elphabet;
    elphabet=(char*)calloc(totalletter,sizeof(char));

    decrypt(elphabet,seed1,Salphletters,totalletter);
    free(Salphletters);

    fp=createWfile(fp);
    if(selection=='C'||selection=='c'){
    decryptOutput(fp,elphabet,letterpos,quantity,1);
    }else{
    decryptOutput(fp,elphabet,letterpos,quantity,0);}
    free(letterpos);
    free(elphabet);
    fclose(fp);
    }
    return 0;
}
