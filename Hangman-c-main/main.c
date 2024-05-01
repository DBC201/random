#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    int n;//how many words
    int c,d;//counter
    char *word;//the word
    int *letter;//letters of each word
    int lettertotal=0;//total amount of letters including spaces
    char *gword;//the players guess
    int lives;//pretty self explanatory(amount of tries)
    int pick='o';

    do{
    system("cls");
    printf("Welcome to HANGMAN created by THE_L0SS");
    printf("\nEnter how many words you will have the other player guess:");
    scanf(" %d", &n);
    letter=(int*)calloc(n, sizeof(int));

    for(c=0;c<n;c++)//gets the amount of letters
    {
        printf("Enter how many letters the word %d will have:", c+1);
        scanf(" %d", &letter[c]);
        lettertotal+=(letter[c]+1);
    }
    word=(char*)calloc(lettertotal,sizeof(char));
    for(c=0;c<n;c++)//gets the words
    {
        if(c==0)
        {
        printf("Now enter word %d(no uppercase letters):", c+1);
        scanf(" %s", word);
        }else if((c+1)==n){
        char Ltemp[(letter[c]+1)];
        printf("Now enter word %d(no uppercase letters):", c+1);
        scanf(" %s", Ltemp);
        strcat(word, " ");
        strcat(word, Ltemp);
        strcat(word, "\0");
        }else{
        char temp[letter[c]];
        printf("Now enter word %d(no uppercase letters):", c+1);
        scanf(" %s", temp);
        strcat(word, " ");
        strcat(word, temp);
        }
    }

    printf("Now enter the lives the opponent will have:");//gets the lives
    scanf(" %d", &lives);
    free(letter);

    printf("\nYour word(s) is(are):%s\n", word);//prints the word
    gword=(char*)calloc(lettertotal,sizeof(char));
    for(c=0;c<lettertotal;c++)//creates the gword
    {
    if(isalpha(word[c]))
    {
        gword[c]='_';
    }else{gword[c]=' ';}
    }
    gword[lettertotal]='\0';

    getchar();
    printf("\nPress enter to continue\n");//screen will be cleared
    getchar();
    system("cls");
    printf("\nInput cleared, opponent's turn.\n");

    do{
    int selection='o';
    printf("\n%s", gword);
    printf("\nRemaining lives:%d", lives);
    printf("\nType 'L' to guess a letter, 'C' to guess all:");
    scanf(" %c", &selection);
    if((selection=='l')||(selection=='L'))
    {
    int gletter='o';//user's letter guess
    int match=0;//the amount of matches
    printf("Enter a letter:");
    scanf(" %c", &gletter);
    for(c=0;c<lettertotal;c++)
    {
        if(word[c]==gletter)
        {
            gword[c]=gletter;
            match++;

        }
    }
    if(match==0){lives--;}
    }else if( (selection=='c')||(selection=='C') )
    {
    char guess[lettertotal];//user's word guess
    getchar();
    printf("Enter your guess:", guess);
    fgets(guess,lettertotal,stdin);
    if( (strcmp(word,guess))==0 )
    {
        break;
    }else
    {
        printf("Wrong guess, try again.\n");
        lives--;
    }
    }
    }while(lives>0);
    free(gword);


    if(lives==0)
    {
    printf("\nSorry, but you have run out of lives.");
    printf("\nThe word was:%s", word);
    }else{printf("\nCongratulations, you won!");}
    free(word);
    printf("\nType p to play again, any other letter to quit(don't just press enter!):");
    scanf(" %c", &pick);
    }while(pick=='p');

    return 0;
}
