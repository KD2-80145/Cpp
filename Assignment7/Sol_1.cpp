#include<iostream>
using namespace std;

class Date{

private:
    int day;
    int month;
    int year;

public:
    //Constructors
    Date()
    {
        this->day=0;
        this->month=0;
        this->year=0;
    }

    Date(int day,int month,int year)
    {
        this->day=day;
        this->month=month;
        this->year=year;
    }

    //Inspectors
    int get_day()
    {
        return this->day;
    }
    int get_month()
    {
        return this->month;
    }

    int get_year()
    {
        return this->year;
    }

    //Mutators

    void set_day(int day)
    {
        this->day=day;
    }

    void set_month(int month)
    {
        this->month=month;
    }

    void set_year(int year)
    {
        this->year=year;
    }

    //Facilitators

    void display()
    {
        cout<<this->day<<"/"<<this->month<<"/"<<this->year<<endl;
    }

    void accept()
    {
        cout<<"Enter Day : ";
        cin>>this->day;

        cout<<"Enter Month : ";
        cin>>this->month;

        cout<<"Enter Year : ";
        cin>>this->year;
    }
    bool isLeap()
    {
        if((this->year%100!=0 && year%4==0) ||(year%400 == 0))
        {
            cout<<this->year<<" is a Leap Year.";
            return true;
        }
        return false;
    }
};

class Person
{
private:

    string name;
    string addr;
    Date birth_date;

public:

    //Constructors
    Person()
    {
        this->name="";
        this->addr="";
        this->birth_date=Date();
    }

    Person(string name,string addr,Date birth_date)
    {
        this->name=name;
        this->addr=addr;
        this->birth_date=birth_date;
    }

    //Inspectors
    string get_name()
    {
        return this->name;
    }

    string get_addr()
    {
        return this->addr;
    }
    Date get_birth_date()
    {
        return this->birth_date;
    }

    //Setters

    void set_name(string name)
    {
        this->name=name;
    }
    void set_addr(string addr)
    {
        this->addr=addr;
    }
    void set_birth_date(Date birth_date)
    {
        this->birth_date=birth_date;
    }

    //Facilitators
    void display()
    {
        cout<<"---------------------------"<<endl;
        cout<<"Name : "<<this->name<<endl;
        cout<<"Address : "<<this->addr<<endl;
        cout<<"Birth Date: ";
        this->birth_date.display();
    }

    void accept()
    {
        cout<<"Enter Name : ";
        cin>>this->name;

        cout<<"Enter Address : ";
        cin>>this->addr;

        cout<<"Enter Birth Date : "<<endl;
        this->birth_date.accept();
    }
};

class Employee:Person
{

private:
    int id;
    float sal;
    string dept;
    Date joining;

public:
    Employee()
    {
        id=0;
        sal=0;
        dept="";
        joining=Date();
    }
    Employee(string name,string addr,Date birth_date, int id,float sal,string dept,Date joining):Person(name,addr,birth_date)
    {
        this->id=id;
        this->sal=sal;
        this->dept=dept;

        this->joining=joining;
    }

    //Getters
    int get_id(){
        return this->id;
    }
    float get_sal()
    {
        return this->sal;
    }
    string get_dept()
    {
        return this->dept;
    }
    Date get_joining_date()
    {
        return this->joining;
    }

    //Setters

    void set_id(int id)
    {
        this->id=id;
    }
    void set_sal(float sal)
    {
        this->sal=sal;
    }
    void set_dept(string dept)
    {
        this->dept=dept;
    }
    void set_joining_date(Date joining)
    {
        this->joining=joining;
    }

    //Facilitators
    void display()
    {
        Person::display();
        cout<<"Id :"<<this->id<<endl;
        cout<<"Dept :"<<this->dept<<endl;
        cout<<"Salary : "<<this->sal<<endl;
        cout<<"Joining Date : ";
        this->joining.display();

        cout<<"-----------------------------"<<endl;

    }

    void accept()
    {
        Person::accept();
        cout<<"Enter Id of Employee : ";
        cin>>this->id;

        cout<<"Enter Salary of Employee : ";
        cin>>this->sal;

        cout<<"Enter Dept of Employee : ";
        cin>>this->dept;

        cout<<"Enter Joining Date of Dept : "<<endl;
        this->joining.accept();
    }

};


int main()
{
    Employee e1;

    e1.accept();
    e1.display();

    int *arr;
    arr=new int[5];
    return 0;
}