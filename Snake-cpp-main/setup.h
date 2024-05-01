#ifndef SETUP_H
#define SETUP_H
#include <vector>

class setup
{
    public:
        setup();
        void opening_screen();
        void random_start();
        void create_snake();
        void create_map();
        void overwrite_map();
        void delete_map();
        void part_snake_pos(int part,int x,int y);
        void move_snake(char direction);
        void shift_snake();
        void create_fruit();
        void test_pickup();
        void lengthen_snake();
        void test_snake_clear();
        void print_map();
        ~setup();

    protected:
    char dir;
    std :: vector < std::vector<int> > snake;
    bool fruit_picked;
    int fruit_duration;
    int length;
    int score;
    int speed;
    private:
    int rows,columns;
    int fruit_location[2];
    char **map;

};

#endif // SETUP_H

