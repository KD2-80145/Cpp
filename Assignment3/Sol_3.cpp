#include<iostream>
using namespace std;
#define PI 3.14f;


class Cylinder{
private:
    double radius;
    double height;

public:
    Cylinder()
    {
        radius=10.00f;
        height=20.00f;
    }
    Cylinder(double radius, double height):radius(radius),height(height)
    {

    }

    //INSPECTORS
    double getRadius()
    {
        return this->radius;
    }
    double getHeight()
    {   
        return this->height;
    }
    double getVolume()
    {
        return 3.14f *( (this->radius) * (this->radius)) * this->height;
    }

    //MUTATORS
    void setRadius()
    {
        double radius;
        cout<<"Enter Radius of Cylinder : ";
        cin>>radius;
        this->radius=radius;
    }
    void setHeight()
    {
        double height;
        cout<<"Enter Height of Cylinder : ";
        cin>>height;
        this->height=height;
    }

    //FACILITATOR
    void printVolume()
    {
        cout<<"VOLUME OF BOX : "<<this->getVolume()<<endl;
    }
};

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

Emenu menu()
{
    int choice;
    cout<<"--------------------------------------------"<<endl;
    cout<<"0. EXIT"<<endl;
    
    cout<<"1. GET_RADIUS"<<endl;
    cout<<"2. GET_HEIGHT"<<endl;
    cout<<"3. GET_VOLUME"<<endl;

    cout<<"4. SET_RADIUS"<<endl;
    cout<<"5. SET_HEIGHT"<<endl;
    cout<<"6. PRINT_VOLUME"<<endl;

    cout<<"--------------------------------------------"<<endl;
    cout<<"Enter Choice : ";
    cin>>choice;

    return Emenu(choice);
}


int main()
{
    Cylinder c1;
    int choice;
    while((choice = menu())!=0)
    {
        switch(choice)
        {
            case GET_RADIUS:
                // cout<<"GET RADIUS";
                cout<<"RADIUS OF CYLINDER : "<<c1.getRadius()<<endl;
                break;
            
            case GET_HEIGHT:
                // cout<<"GET HEIGHT";
                cout<<"HEIGHT OF CYLINDER : "<<c1.getHeight()<<endl;
                break;
            case GET_VOLUME:
            //  cout<<"GET VOLUME";
            cout<<"VOLUME OF CYLINDER : "<<c1.getVolume()<<endl;
                break;

            case SET_RADIUS:
            //  cout<<"SET RADIUS";
                c1.setRadius();
                break;
            case SET_HEIGHT:
            //  cout<<"SET HEIGHT";
                c1.setHeight();
                break;    

            case PRINT_VOLUME:
            //  cout<<"PRINT VOLUME";
                c1.printVolume();
                break;
            default:
                cout<<"INVALID CHOICE";
        }
    }
}