#ifndef GET_VALUES_H
#define GET_VALUES_H

class get_values
{
    public:
        get_values();
        void get_input();
        bool tweak_mode_check();
        void settings();
        ~get_values();

    protected:
    int width,height,x_range,y_range;
    double increment;
    double a,b,c,d;
    private:
};

#endif // GET_VALUES_H
