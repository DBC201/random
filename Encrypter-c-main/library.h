//add or remove letters here, don't forget the space!
//do not use '~', refer to readme.txt for further information
const char alphabet[]="\n\t\"?,.*();:!><'^%+=/\\-_1234567890abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ[] ";
int c,d,r,temp;
int method=0;
int checkinput=0;

void PalphabetScreen(int totalletter){
    for(c=0;c<totalletter-1;c++){
        if(alphabet[c]=='\n'){
            continue;
        }else if(alphabet[c]=='\t'){
            continue;
        }else{printf("%c",alphabet[c]);}
    }
}

void Palphabetfile(FILE *fp,int totalletter){
    fprintf(fp,"const char alphabet[]=\"");
    for(c=0;c<totalletter-1;c++){
        if(alphabet[c]=='\n'){
            fprintf(fp,"\\n");
        }else if(alphabet[c]=='\t'){
            fprintf(fp,"\\t");
        }else{fprintf(fp,"%c",alphabet[c]);}
    }
    fprintf(fp,"\"");
}

FILE *createRfile(FILE *fp){
    fp=fopen("Encrypter.txt","r");
    return fp;
}

FILE *createWfile(FILE *fp){
    fp=fopen("Encrypter.txt","w");
    return fp;
}

void printtime(FILE *fp){
    char te[64];
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    strftime(te, sizeof(te), "%c", tm);
    fprintf(fp,"%s",te);
}

void wronginput(){
    printf("\aUnsupported letter found, this program will now terminate.");
    printf("\nPress any key to continue:");
    getchar();
    getchar();
    exit(-1);
}

int textlength(FILE *fp){
fseek(fp,0,SEEK_END);
size_t length=ftell(fp);
return length;
}

void get_text(FILE *fp,char *text, int length){
    fseek(fp,0,SEEK_SET);
    fread(text,sizeof(char),length,fp);
    for(c=0;c<length-1;c++){
    if(text[c]=='\0'){
        text[c]=' ';
    }else{continue;}
    }
    text[length]='\0';
}
