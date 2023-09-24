#include "./menu.h"
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