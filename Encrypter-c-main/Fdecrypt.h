void getseed(int *Pseed1,int *Pseed2){
    printf("Enter seed 1:");
    scanf(" %d",Pseed1);
    printf("Enter seed 2:");
    scanf(" %d",Pseed2);
}

void readtext(char *input,int *letterpos,int quantity,int totalletter){
    for(c=0;c<quantity;c++){
        for(r=0;r<totalletter-1;r++){
            if(input[c]=='~'){
                for(d=0;d<totalletter-1;d++){
                    if(alphabet[d]=='\n'){
                        temp=d;
                        break;
                    }else{continue;}
                }
            letterpos[c]=temp;
            checkinput++;
            break;
            }else if(input[c]==alphabet[r]){
                letterpos[c]=r;
                checkinput++;
                break;
            }else{continue;}
        }
        if(checkinput==0){
            printf("Error:%c\n",input[c]);
            wronginput();
        }else{
        checkinput=0;
        continue;
        }
    }
}

void unshuffleLetters(int seed2,int *letterpos,int quantity){
    int *Rnumbers;
    Rnumbers=(int*)calloc(quantity,sizeof(int));
    srand(seed2);
    for(c=0;c<quantity;c++){
        Rnumbers[c]=rand()%quantity;
    }

    for(c=quantity-1;c>=0;c--){
        temp=letterpos[c];
        letterpos[c]=letterpos[Rnumbers[c]];
        letterpos[Rnumbers[c]]=temp;
    }
    free(Rnumbers);
}

void decrypt(char *elphabet,int seed1,int *Salphletters,int totalletter){
    srand(seed1);
    for(c=0;c<totalletter-1;c++){
        Salphletters[c]=c;
    }
    for(c=0;c<totalletter-1;c++){
        r=rand()%(totalletter-1);
        temp=Salphletters[c];
        Salphletters[c]=Salphletters[r];
        Salphletters[r]=temp;
    }
    for(c=0;c<totalletter-1;c++){
        elphabet[c]=alphabet[Salphletters[c]];
    }
}

void decryptOutput(FILE *fp,char *elphabet,int *letterpos,int quantity,int deep){
    printtime(fp);
    fprintf(fp,"\n");
    if(deep==1){
    for(c=0;c<quantity;c++){//prints out the decrypted output
        if(elphabet[letterpos[c]]=='\n'){
            fprintf(fp,"~");
        }else{
        fprintf(fp,"%c",elphabet[letterpos[c]]);}
    }
    }else{
    for(c=0;c<quantity;c++){//prints out the decrypted output
        fprintf(fp,"%c",elphabet[letterpos[c]]);
    }
    }
}
