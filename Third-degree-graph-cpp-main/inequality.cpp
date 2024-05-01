#include "inequality.h"
#include <iostream>
#include <graphics.h>
#include <conio.h>
#include <cmath>
using namespace std;

inequality::inequality()
{
    graph(X_RANGE,Y_RANGE,INCREMENT,WIDTH,HEIGHT,WHITE);
    system("pause");
}

void inequality::graph(int xr,int yr,double inc,int w,int h,int color){
    double x,y;
    setcolor(color);
    for(x=0;x<w/2;x+=inc){
        y=d*(pow(x,3))+a*(pow(x,2))+b*x+c;
        if(x==0){
            moveto(w/2+x*xr,h/2-y*yr);
        }
        lineto(w/2+x*xr,h/2-y*yr);
    }
    for(x=0;x*-1<w/2;x-=inc){
        y=d*(pow(x,3))+a*(pow(x,2))+b*x+c;
        if(x==0){
            moveto(w/2+x*xr,h/2-y*yr);
        }
        lineto(w/2+x*xr,h/2-y*yr);
    }
}

inequality::~inequality()
{

}
