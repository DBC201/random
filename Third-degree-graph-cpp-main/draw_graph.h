#ifndef DRAW_GRAPH_H
#define DRAW_GRAPH_H
#include "get_values.h"

class draw_graph:public get_values
{
    public:
        draw_graph();
        void draw_axis(int x,int y,int color);
        void draw_numbers(int w,int h,int xr,int yr,int color);
        ~draw_graph();

    protected:
    const int WIDTH,HEIGHT,X_RANGE,Y_RANGE;
    const double INCREMENT;
    private:
};

#endif // DRAW_GRAPH_H
