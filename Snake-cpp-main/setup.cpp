#include "setup.h"
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include <vector>
#include <ctime>
setup::setup(){
    score=0;
    length=1;
    fruit_duration=0;
    fruit_picked=false;
    opening_screen();
    //std::cout<<rows<<std::endl;
    //std::cout<<columns<<std::endl;
    //system("pause");
    create_snake();
    random_start();
}

void setup::opening_screen(){
    std::cout<<"Snake by dbc201"<<std::endl;
    std::cout<<"Press s to change settings, else to use default."<<std::endl;
    char pick=getchar();
    if(pick=='s'||pick=='S'){
        while(1){
        std::cout<<"Enter speed in miliseconds(10 by default):";
        std::cin>>speed;
        if(speed<0){
            std::cout<<"Wrong input";
            system("cls");
        }else{
            break;
        }
        }
        while(1){
        std::cout<<"Enter width(80 by default):";
        std::cin>>columns;
        if(speed<0){
            std::cout<<"Wrong input";
            system("cls");
        }else{
            break;
        }
        }
        while(1){
        std::cout<<"Enter heigth(10 by default):";
        std::cin>>rows;
        if(speed<0){
            std::cout<<"Wrong input";
            system("cls");
        }else{
            break;
        }
        }
    }else{
        rows=10;
        columns=80;
        speed=10;
    }
}

void setup::random_start(){
    srand(time(0));
    part_snake_pos(0,rand()%columns,rand()%rows);
    int start_dir=(rand()%4)+1;
    if(start_dir==1){
        dir='w';
    }else if(start_dir==2){
        dir='s';
    }else if(start_dir==3){
        dir='a';
    }else if(start_dir==4){
        dir='d';
    }else{
        system("cls");
        std::cout<<"\aStupid error while randomly placing the snake. Check setup.random_start;"<<std::endl;
        system("pause");
        exit(-1);
    }
}

void setup::create_fruit(){
    srand(time(0));
    fruit_location[0]=rand()%columns;
    fruit_location[1]=rand()%rows;
    test_snake_clear();
}

void setup::test_snake_clear(){
    for(int c=0;c<length;c++){
        if(snake[c][0]==fruit_location[0] && snake[c][1]==fruit_location[1]){
            create_fruit();
        }
    }
}

void setup::test_pickup(){
    if( (snake[0][0]==fruit_location[0]) && (snake[0][1]==fruit_location[1]) ){
        length++;
        score++;
        lengthen_snake();
        fruit_picked=true;
        fruit_duration=0;
    }else{
        fruit_duration++;
        fruit_picked=false;
    }
}

void setup::lengthen_snake(){
    snake.push_back( std::vector<int>() );
    snake[length-1].resize(2);
    if(dir=='d' || dir=='D'){
        if(snake[length-2][0]==0){
        part_snake_pos(length-1,columns-1,snake[length-2][1]);
        }else{
        part_snake_pos(length-1,snake[length-2][0]-1,snake[length-2][1]);
        }
    }else if(dir=='a' || dir=='A'){
        if(snake[length-2][0]==columns-1){
        part_snake_pos(length-1,0,snake[length-2][1]);
        }else{
        part_snake_pos(length-1,snake[length-2][0]+1,snake[length-2][1]);
        }
    }else if(dir=='w' || dir== 'W'){
        if(snake[length-2][1]==rows-1){
        part_snake_pos(length-1,snake[length-2][0],0);
        }else{
        part_snake_pos(length-1,snake[length-2][0],snake[length-2][1]+1);
        }
    }else if(dir=='s' || dir=='S'){
        if(snake[length-2][1]==0){
        part_snake_pos(length-1,snake[length-2][0],rows-1);
        }else{
        part_snake_pos(length-1,snake[length-2][0],snake[length-2][1]-1);
        }
    }
}

void setup::print_map(){
    for(int c=0;c<rows;c++){
        for(int r=0;r<columns;r++){
            std::cout<<map[c][r];
        }
    }
}

void setup::move_snake(char direction){
    shift_snake();
    if(direction=='w'||direction=='W'){
        snake[0][1]--;
        if(snake[0][1]<0){
            snake[0][1]=rows-1;
        }else if(snake[0][1]>rows-1){
            snake[0][1]=0;
        }
    }else if(direction=='s'||direction=='S'){
        snake[0][1]++;
        if(snake[0][1]<0){
            snake[0][1]=rows-1;
        }else if(snake[0][1]>rows-1){
            snake[0][1]=0;
        }
    }else if(direction=='d'||direction=='D'){
        snake[0][0]++;
        if(snake[0][0]<0){
            snake[0][0]=columns-1;
        }else if(snake[0][0]>columns-1){
            snake[0][0]=0;
        }
    }else if(direction=='a'||direction=='A'){
        snake[0][0]--;
        if(snake[0][0]<0){
            snake[0][0]=columns-1;
        }else if(snake[0][0]>columns-1){
            snake[0][0]=0;
        }
    }else{
        snake[0][1]--;
        if(snake[0][1]<0){
            snake[0][1]=rows-1;
        }else if(snake[0][1]>rows-1){
            snake[0][1]=0;
        }
    }
}

void setup::shift_snake(){
    for(int c=length-1;c>0;c--){
        snake[c][0]=snake[c-1][0];
        snake[c][1]=snake[c-1][1];
    }
}

void setup::part_snake_pos(int part,int x,int y){
    snake[part][0]=x;
    snake[part][1]=y;
}

void setup::overwrite_map(){
    for(int c=1;c<length;c++){
        map[snake[c][1]][snake[c][0]]='o';
    }
    map[snake[0][1]][snake[0][0]]='O';
    map[fruit_location[1]][fruit_location[0]]='X';
}

void setup::create_snake(){
    snake.resize(length);
    for(int c=0;c<length;c++){
        snake[c].resize(2);
    }
}

void setup::create_map(){
    map=new char*[rows];
    for(int c=0;c<rows;c++){
    map[c]=new char[columns];
    }
    for(int r=0;r<rows;r++){
        for(int c=0;c<columns;c++){
            if(c==columns-1){
                map[r][c]='\n';
            }else{
                map[r][c]=' ';
            }
        }
    }
}

void setup::delete_map(){
    for(int c=0;c<rows;c++){
        delete[] map[c];
    }
    delete[] map;
}

setup::~setup()
{
    //dtor
}
