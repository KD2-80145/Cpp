#ifndef CYLINDER_H
#define CYLINDER_h
// #define PI 3.14f;
#include<iostream>
using namespace std;

class Cylinder
{
private:
    double radius;
    double height;

public:
    Cylinder();
    Cylinder(double radius, double height);

    // INSPECTORS
    double getRadius();
    double getHeight();
    double getVolume();

    // MUTATORS
    void setRadius();
    void setHeight();

    // FACILITATOR
    void printVolume();
};

#endif