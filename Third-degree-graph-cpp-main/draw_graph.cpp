#include <iostream>
#include <graphics.h>
#include <conio.h>
#include <cmath>
#include "draw_graph.h"
using namespace std;

draw_graph::draw_graph():
WIDTH(width),HEIGHT(height),X_RANGE(x_range),Y_RANGE(y_range),INCREMENT(increment)
{
    initwindow(WIDTH,HEIGHT);
    draw_axis(WIDTH,HEIGHT,YELLOW);
    draw_numbers(WIDTH,HEIGHT,X_RANGE,Y_RANGE,YELLOW);
}

void draw_graph::draw_axis(int x,int y,int color){
    setcolor(color);
    moveto(0,y/2);
    lineto(x,y/2);
    outtextxy(x-20,y/2+10,"x");
    moveto(x/2,0);
    lineto(x/2,y);
    outtextxy(x/2+10,10,"y");
}

void draw_graph::draw_numbers(int w,int h,int xr,int yr,int color){
    int i;
    for(i=0;i<w;i+=xr){
        outtextxy(i,h/2-8,"|");
    }
    for(i=0;i<h;i+=yr){
        outtextxy(w/2+1,i-8,"-");
    }
}

draw_graph::~draw_graph()
{

}
