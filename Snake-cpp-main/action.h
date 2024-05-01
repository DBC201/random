#ifndef ACTION_H
#define ACTION_H
#include "setup.h"


class action:public setup
{
    public:
        action();
        void check_collusion();
        void play_game();
        ~action();

    protected:

    private:
};

#endif // ACTION_H
