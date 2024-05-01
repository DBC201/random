#include <iostream>
#include <stdlib.h>
#include <ctime>
#include "class.h"
using namespace std;

timer::timer()
{
    cout<<"Timer by DBC"<<endl;
    cout<<"Enter hours:";
    cin>>hour;
    cout<<"Enter minutes:";
    cin>>minute;
    cout<<"Enter seconds:";
    cin>>second;
    cout<<"Enter the alarm duration in seconds(0 for infinite loop):";
    cin>>duration;
    minute+=second/60;
    second%=60;
    hour+=minute/60;
    minute%=60;
    totalseconds=(hour*3600)+(minute*60)+second;
}
timer::~timer()
{
    system("cls");
    cout<<"Time is up";
    alarm(duration);
}
int timer::operation(){
    int operate;//if int c is used, the variables get mixed up if timer.time is used in a c based for loop and so on
for(operate=0;operate<100000;operate++){
    int e=5;
}
return 1;
}
void timer::time(double seconds){
    double secondspassed=0;
    while(secondspassed<seconds){
    clock_t start=clock();
    operation();
    clock_t stop=clock();
    secondspassed+=(stop-start)/(double)CLOCKS_PER_SEC;
    }
}
void timer::printtime(){
    for(c=totalseconds;totalseconds>0;totalseconds--){
    system("cls");
    cout<<totalseconds/3600<<":";
    cout<<(totalseconds/60)%60<<":";
    cout<<totalseconds%60<<endl;
    time(1);
    }
}
void timer::alarm(int input){
    if(input==0){
        while(1){
            cout<<"\a";
            time(1);
        }
    }else{
    for(c=0;c<input;c++){
        cout<<"\a";
        time(1);
    }
    }
}
