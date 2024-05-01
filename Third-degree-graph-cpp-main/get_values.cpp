#include <iostream>
#include "get_values.h"
using namespace std;

get_values::get_values()
{
    settings();
    get_input();
}

void get_values::get_input(){
    cout<<"d(x^3)+a(x^2)+bx+c"<<endl;
    cout<<"Enter d:";
    cin>>d;
    cout<<"Enter a:";
    cin>>a;
    cout<<"Enter b:";
    cin>>b;
    cout<<"Enter c:";
    cin>>c;
}

bool get_values::tweak_mode_check(){
    string selection;
    cout<<"Enter 1 to tweak settings(not recommended), else to continue:";
    cin>>selection;
    if(selection=="1"){
        return true;
    }else{
        return false;
    }
}

void get_values::settings(){
    if(!tweak_mode_check()){
        width=800;
        height=600;
        x_range=10;
        y_range=10;
        increment=0.1;
        return;
    }else{
        cout<<"Enter width in pixels:";
        cin>>width;
        cout<<"Enter height in pixels:";
        cin>>height;
        cout<<"Enter x_range:";
        cin>>x_range;
        cout<<"Enter y_range:";
        cin>>y_range;
        cout<<"Enter increment:";
        cin>>increment;
    }
}

get_values::~get_values()
{

}
