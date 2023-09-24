#include "./cylinder.h"
#include "./menu.h"

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