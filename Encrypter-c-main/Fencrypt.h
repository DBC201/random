void getmethod(int *Pseed1,int *Pseed2){
    printf("\nMethod 1 uses user input");
    printf("\nMethod 2 selects a random seed and saves it");
    printf("\nEnter encryption method:");
    scanf(" %d", &method);
    if(method==1){
    printf("Enter seed 1:");
    scanf(" %d", Pseed1);
    printf("Enter seed 2:");
    scanf(" %d", Pseed2);
    }else if(method==2){
    srand(time(NULL));
    *Pseed1=rand();
    *Pseed2=rand();
    }else{
    printf("\aERROR");
    exit(-1);
    }
}

void randomizeInput(char *input,int seed1,int *Salphletters,int *letterpos,int totalletter,int quantity){
    for(c=0;c<quantity;c++){
        if(input[c]=='~'){
            input[c]='\n';
        }
    }
    for(c=0;c<totalletter-1;c++){
        Salphletters[c]=c;
    }

    srand(seed1);
    for(c=0;c<totalletter-1;c++){
        r=rand()%(totalletter-1);
        temp=Salphletters[c];
        Salphletters[c]=Salphletters[r];
        Salphletters[r]=temp;
    }

    for(c=0;c<quantity;c++){
        for(r=0;r<totalletter-1;r++){//figures out the input chars place in shuffled alphabet
            if(input[c]==alphabet[Salphletters[r]]){
                letterpos[c]=r;
                checkinput++;
                break;
            }else{continue;}
        }
        if(checkinput==0){
            printf("Error:%c,%d\n",input[c],c);
            printf("%c,%c,%c\n",input[c-1],input[c],input[c+1]);
            wronginput();
        }else{
        checkinput=0;
        continue;
        }
    }
}

void shuffleLetters(char *input,int seed2,int *letterpos,int quantity){
    srand(seed2);//shuffles the letters according to the seed
    for(c=0;c<quantity;c++){
        r=rand()%quantity;
        temp=letterpos[c];
        letterpos[c]=letterpos[r];
        letterpos[r]=temp;
    }
}

void encryptOutput(FILE *fp,int seed1,int seed2,int quantity,int *letterpos,int totalletter){
    printtime(fp);
    fprintf(fp,"\nSeed 1:%d",seed1);
    fprintf(fp,"\nSeed 2:%d",seed2);
    fprintf(fp,"\nAlphabet array(should be the same order in code of both parties, refer to source code when in doubt):\n");
    Palphabetfile(fp,totalletter);
    fprintf(fp,"\nNumber of letters:%d(last letter might be blank)\n",quantity);
    for(c=0;c<quantity;c++){//prints out the encrypted input as output
        if(c==quantity-1&&alphabet[letterpos[c]]==' '){//there is a one in million chance this might fail ^^
            fprintf(fp,"[blank]");
        }else if(alphabet[letterpos[c]]=='\n'){
            fprintf(fp,"%c",'~');
            continue;
        }else{fprintf(fp,"%c",alphabet[letterpos[c]]);}
    }
}
