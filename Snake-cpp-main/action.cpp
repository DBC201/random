#include "action.h"
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <windows.h>

action::action()
{
    play_game();
}

void action::play_game(){
    while(dir!='x'){
    while(!_kbhit()){
    system("cls");
    create_map();
    if(fruit_picked==true||fruit_duration==0){
    create_fruit();}
    move_snake(dir);
    check_collusion();
    test_pickup();
    overwrite_map();
    print_map();
    delete_map();//for preventing memory leak
    std::cout<<"Score: "<<score<<std::endl;
    //std::cout<<"length: "<<length<<std::endl;
    //std::cout<<"head:  "<<snake[0][0]<<" "<<snake[0][1]<<std::endl;
    Sleep(speed);
    }
    char tempc=dir;
    dir=_getch();
        if( (dir=='W'||dir=='w') && (tempc=='s' || tempc=='S' ) ){
                dir='s';
        }else if( (dir=='S'||dir=='s') && (tempc=='W' || tempc=='w' ) ){
                dir='w';
        }else if( (dir=='A'||dir=='a') && (tempc=='D' || tempc=='d' ) ){
                dir='d';
        }else if( (dir=='D'||dir=='d') && (tempc=='A' || tempc=='a' ) ){
                dir='a';
        }
    }
}

void action::check_collusion(){
    for(int c=1;c<length;c++){
        if(snake[0][0]==snake[c][0] && snake[0][1]==snake[c][1]){
            char quit='y';
            while(1){
            overwrite_map();
            print_map();
            std::cout<<"\aGame Over"<<std::endl;
            std::cout<<"Score: "<<score<<std::endl;
            std::cout<<"Press x to exit:";
            quit=getchar();
            system("cls");
            if(quit=='x' || quit=='X'){
                break;
            }
            }
            exit(0);
        }
    }
}

action::~action()
{
    //dtor
}
