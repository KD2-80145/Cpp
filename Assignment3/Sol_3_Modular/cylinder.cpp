#include "./cylinder.h"

    Cylinder::Cylinder()
    {
        radius=10.00f;
        height=20.00f;
    }
    
    Cylinder::Cylinder(double radius, double height):radius(radius),height(height)
    {

    }

    //INSPECTORS
    double Cylinder::getRadius()
    {
        return this->radius;
    }
    double Cylinder::getHeight()
    {   
        return this->height;
    }
    double Cylinder::getVolume()
    {
        return 3.14 *( (this->radius) * (this->radius)) * this->height;
        // return PI *( (this->radius) * (this->radius)) * this->height;
    }

    //MUTATORS
    void Cylinder::setRadius()
    {
        double radius;
        cout<<"Enter Radius of Cylinder : ";
        cin>>radius;
        this->radius=radius;
    }
    void Cylinder::setHeight()
    {
        double height;
        cout<<"Enter Height of Cylinder : ";
        cin>>height;
        this->height=height;
    }

    //FACILITATOR
    void Cylinder::printVolume()
    {
        cout<<"VOLUME OF BOX : "<<this->getVolume()<<endl;
    }