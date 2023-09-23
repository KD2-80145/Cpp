#include <iostream>
using namespace std;

class ToolBooth
{
private:
    unsigned int total_cars;
    double total_money;

public:
    ToolBooth()
    {
        this->total_cars = 0;
        this->total_money = 0;
    }

    void payingCar()
    {
        this->total_cars=this->total_cars+1;
        this->total_money += 0.50;
        cout<<"YOU PAID THE TOLL."<<endl;
    }

    void nopayCar()
    {
        this->total_cars=this->total_cars+1;
        cout<<"YOU DID NOT PAY THE TOLL."<<endl;
    }

    void printOnConsole()
    {
        cout << "TOTAL CARS : " << this->total_cars << endl;
        cout << "TOTAL MONEY: " << this->total_money << endl;

        double desired_money = (this->total_cars) * 0.50;
        // cout<<desired_money<<endl;
        if (desired_money == this->total_money)
        {
            cout << "PAYING CARS : " <<this->total_cars<< endl;
            cout << "NON-PAYING CARS : 0"<< endl;
        }
        else{
            int non_pay_cars=(desired_money-this->total_money)/0.50;
            cout << "PAYING CARS : " <<(this->total_cars) - non_pay_cars<< endl;
            cout << "NON-PAYING CARS : "<<non_pay_cars<< endl;
        }
    }
};

enum EToll_Options
{
    PAY=1,
    DONT_PAY,
    SHOW_STATS
};

EToll_Options menu()
{
    int choice;
    cout<<"--------------------------------------------"<<endl;
    cout<<"0. EXIT"<<endl;
    cout<<"1. PAY TOLL"<<endl;
    cout<<"2. DON'T PAY TOLL"<<endl;
    cout<<"3. SHOW ALL STATS"<<endl;
    cout<<"--------------------------------------------"<<endl;
    cout<<"Enter Choice : ";
    cin>>choice;

    return EToll_Options(choice);
}


int main()
{
    int choice;
    ToolBooth t1;
    while((choice=menu()) !=0)
    {
        switch(choice)
        {
            case PAY:
                // cout<<"PAID"<<endl;
                t1.payingCar();
                break;

            case DONT_PAY:
                // cout<<"NOT PAID"<<endl;
                t1.nopayCar();
                break;
            case SHOW_STATS:
                // cout<<"SHOW STATS"<<endl;
                t1.printOnConsole();
                break;
            
            default:
                cout<<"INVALID REQUEST"<<endl;

        }
    }

    cout<<"OUT OF TOLL PLAZA.."<<endl;
}