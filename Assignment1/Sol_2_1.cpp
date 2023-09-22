#include<iostream>
using namespace std;
class DATE{
    int day;
    int month;
    int year;
public:
    void initDate()
    {
        this->day = 22;
        this->month = 9;
        this->year = 2023;
    }

    void printDateOnConsole()
    {
        cout<<"DATE : "<<this->day<<"-"<<this->month<<"-"<<this->year<<endl;
    }
    void acceptDateFromConsole()
    {
        cout<<"Enter Day : ";
        cin>>this->day;

        cout<<"Enter Month : ";
        cin>>this->month;

        cout<<"Enter Year :";
        cin>>this->year;
    }


    bool isLeapYear()
    {
        int in_year=this->year;

        if((in_year%100!=0 && in_year%4 == 0 )|| (year%400==0)){
            cout<<this->year<<" is a leap year."<<endl;
            return true;
        }
        else{
            cout<<this->year<<" is not a leap year."<<endl;
            return false;
        }
    }
};

int main()
{
    DATE d1;
    while(1)
    {
        printf("**********************************************************\n");
        printf("1.INITIALISE DATE\n2.ACCEPT DATE\n3.DISPLAY DATE\n4.CHECK LEAP YEAR\n5.EXIT\n");
        printf("**********************************************************\n");

        int choice;
        printf("Enter your choice: ");
        scanf("%d",&choice);

        
        switch(choice)
        {
            case 1:
                d1.initDate();
                break;
            case 2:
                d1.acceptDateFromConsole();
                break;
            case 3:
                d1.printDateOnConsole();
                break;
            case 4:
                d1.isLeapYear();
                break;
            case 5:
                cout<<"OUT OF LOOP"<<endl;
                return 0;
            default:
                printf("INVALID CHOICE");
        }

        // break;
    }
}