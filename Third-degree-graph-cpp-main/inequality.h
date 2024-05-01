#ifndef INEQUALITY_H
#define INEQUALITY_H1
#include <draw_graph.h>

class inequality:public draw_graph
{
    public:
        inequality();
        void graph(int xr,int yr,double inc,int w,int h,int color);
        ~inequality();

    protected:
    private:
};

#endif // INEQUALITY_H
