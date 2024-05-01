#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int c;//counter for "for" loop
int lastline(FILE *fp,int totalline){
    fseek(fp,0,SEEK_SET);
    int pos=0;
    int countline=0;
    while(!feof(fp)){
        int let=fgetc(fp);
        pos++;
        if(let=='\n'){
            countline++;
        }else{continue;}
        if(countline==totalline){
            return pos+totalline;//add totalline for '\0' character at the end of each line
        }
    }
    return -1;
}
int lastnum(FILE *fp){
    fseek(fp,0,SEEK_SET);
    int linenumber=0;
    while(!feof(fp)){
        int let=fgetc(fp);
        if(let=='\n'){
            linenumber++;
        }
    }
    int pos=lastline(fp,linenumber);
    int num;
    fseek(fp,pos,SEEK_SET);
    fscanf(fp," %d", &num);
    fseek(fp,0,SEEK_END);
    if(pos==-1){
        return 1;
    }else{
    return num;}
}
int main(){
	int number;//all numbers
	int remainder;
	int match;//non primes;
	int primes=0;//amount of primes
	int wanted;//wanted number of primes;
	printf("This program will create a text file and save the results on the same folder.");
	printf("\nEnter the amount of primes you want to get:");
    scanf(" %d", &wanted);

    FILE *save;
    save=fopen("prime numbers.txt", "a+");
    number=lastnum(save)+1;

	while(1){
    match=0;
    if(primes==wanted)//tests if the result is reached, if so shuts down the program
    {
        fclose(save);
        return 0;
    }
	if(number==2){//2 is the only even prime, it is an exception
		printf("2");
		fprintf(save,"2");
		primes++;
		number++;
		continue;
	}else{
	for(c=2;c<number;c++)//divides the number, if 0 is reached, terminates the loop
	{
		remainder=number%c;
		if(remainder==0)
		{
		match++;
	    break;
	    }
	}

	if(match==0){//if no zeros are reached, the number is a prime
	printf("\n%d:%d",primes+1,number);
	fprintf(save,"\n%d",number);
	primes++;
	number++;
	continue;
	}else{//number is not prime
    number++;
    continue;
    }
	}
	}
}
