#ifndef MENU_H
#define MENU_H
#include<iostream>
using namespace std;

enum Emenu
{
    EXIT,
    GET_RADIUS,
    GET_HEIGHT,
    GET_VOLUME,

    SET_RADIUS,
    SET_HEIGHT,
    PRINT_VOLUME
};

Emenu menu();


#endif