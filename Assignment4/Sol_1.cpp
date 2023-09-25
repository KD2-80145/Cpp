#include <iostream>
using namespace std;

class Time
{
private:
    int hr;
    int min;
    int sec;

public:
    // CONSTRUCTORS
    Time()
    {
        cout << "Object of Time created" << endl;
    }
    Time(int h, int m, int s)
    {
        this->hr = h;
        this->min = m;
        this->sec = s;
    }

    // INSPECTORS
    int getHour()
    {
        return this->hr;
    }

    int getMinute()
    {
        return this->min;
    }

    int getSeconds()
    {
        return this->sec;
    }

    // MUTATORS
    void setHour()
    {
        cout << "Enter Hours: ";
        cin >> this->hr;
    }
    void setMinute()
    {
        cout << "Enter Minutes : ";
        cin >> this->min;
    }
    void setSeconds()
    {
        cout << "Enter Seconds : ";
        cin >> this->sec;
    }

    // FACILITATOR
    void printTime()
    {
        cout << "Hours : " << this->hr << endl;
        cout << "Minutes : " << this->min << endl;
        cout << "Seconds : " << this->sec << endl;
    }

    // DESTRUCTOR
    ~Time()
    {
    }
};

int main()
{
    int no_of_Objects;
    cout << "Enter no of Objects : ";
    cin >> no_of_Objects;

    Time **Time_arr = new Time *[no_of_Objects];

    for (int i = 0; i < no_of_Objects; i++)
    {
        Time_arr[i] = new Time();
    }

    for (int i = 0; i < no_of_Objects; i++)
    {
        cout << "Enter Hour value for object no " << (i + 1) << " : " << endl;
        Time_arr[i]->setHour();

    }

    for (int i = 0; i < no_of_Objects; i++)
    {
        Time_arr[i]->printTime();
    }

    //De-allocate Heap Memory
    for(int i=0;i<no_of_Objects;i++)
        delete Time_arr[i];
        
    delete[] Time_arr;
    return 0;
}
