#ifndef CLASS_H
#define CLASS_H


class timer
{
    public:
       timer();
       int operation();
       void time(double seconds);
       void printtime();
       void alarm(int input);
        ~timer();

    protected:

    private:
        int totalseconds;
        int hour,minute,second;
        int c;
        int duration;
};
#endif // CLASS_H
