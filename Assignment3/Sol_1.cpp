#include <iostream>
using namespace std;

class Box
{
private:
    int length;
    int width;
    int height;

public:
    Box()
    {
        this->length=10;
        this->width=20;
        this->height=30;
    }
    void accept()
    {
        cout<<"Enter Length : ";
        cin>>this->length;

        cout<<"Enter Width : ";
        cin>>this->width;

        cout<<"Enter Height : ";
        cin>>this->height;
    }

    void display()
    {
        cout<<"LENGTH : "<<this->length<<endl;
        cout<<"WIDTH : "<<this->width<<endl;
        cout<<"HEIGHT : "<<this->height<<endl;
    }


    //INSPECTORS
    int getLength()
    {
        return this->length;
    }

    int getWidth()
    {
        return this->width;
    }

    int getHeight()
    {   
        return this->height;
    }
};

inline int calc_Vol(Box *b1)
{
    return (b1->getLength()) *  (b1->getWidth()) *  (b1->getHeight());
}

enum Emenu
{
    EXIT,
    ACCEPT,
    DISPLAY,
    CALC_VOL
};

Emenu menu()
{
    int choice;
    cout << "*****************************" << endl;
    cout << "0. EXIT" << endl;
    cout << "1. ACCEPT" << endl;
    cout << "2. DISPLAY" << endl;
    cout << "3. CALC_VOL" << endl;
    cout << "*******************************" << endl;

    cout << endl
         << "Enter Your choice : ";
    cin >> choice;

    return Emenu(choice);
}

int main()
{
    int choice;
    Box b1;
    while ((choice = menu()) != 0)
    {
        switch (choice)
        {
        case ACCEPT:
            b1.accept();
            break;
        case DISPLAY:
            b1.display();
            break;
        case CALC_VOL:
            // cout << "CALC" << endl;
            cout<<"VOLUME OF BOX : "<<calc_Vol(&b1)<<endl;
            break;

        default:
            cout<<"WRONG INPUT"<<endl;
            break;
        }
    }

    cout<<"EXIT.."<<endl;
}