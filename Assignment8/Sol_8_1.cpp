#include<iostream>

using namespace std;

class Distance
{
private:
    int feet;
    int inches;

public:
    Distance()
    {
        feet=0;
        inches=0;
    }
    Distance(int feet,int inches)
    {
        this->feet=feet;
        this->inches=inches;
    }

    Distance operator+(Distance d1)
    {
        Distance result;

        int extra_feet=(this->inches+d1.inches)/12;

        result.feet=(this->feet+d1.feet)+extra_feet;

        result.inches=(this->inches+d1.inches)-(extra_feet*12);

        return result;
    }

    void operator++()
    {
        this->inches=this->inches+1;

        int extra_feet=(this->inches/12);

        this->feet=this->feet+extra_feet;
        this->inches=(this->inches)-(extra_feet*12);

    }

    friend bool operator ==(Distance d1,Distance d2);
    friend void operator--(Distance& d1);
    friend void operator <<(ostream& cout,Distance d1);
    friend void operator>>(istream& cin,Distance& d1);
};

bool operator ==(Distance d1,Distance d2)
{
    return (d1.feet==d2.feet && d1.inches==d2.inches);
}

void operator--(Distance& d1)
{
    int inches=d1.inches;

    if(inches==0)
    {
        d1.feet=d1.feet-1;
        d1.inches=11;
        return;
    }
    else
    {
        d1.inches=inches-1;
    }
}

void operator>>(istream& cin,Distance& d1)
{
    cout<<"Enter feet: ";
    cin>>d1.feet;
    cout<<"Enter inches: ";
    cin>>d1.inches;
}

void operator<<(ostream& cout,Distance d1)
{
    cout<<d1.feet<<" "<<d1.inches<<endl;
}

int main()
{
    Distance d1;
    // Distance d2(10,10);

    // Distance d3=d1+d2;

    // d3.display();
    // --d1;
    // cout<<d1;

        cin>>d1;
        cout<<d1;

    // bool ans = d1==d2;
    // cout<<ans;
    return 0;
}