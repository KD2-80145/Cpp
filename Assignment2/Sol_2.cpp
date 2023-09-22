#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Address{

    string building;
    string street;
    string city;
    int pin;


public:

    //CONSTRUCTORS
    Address()
    {
        cout<<"OBJECT CREATED."<<endl;
    }

    Address(string building,string street,string city,int pin)
    {
        this->building=building;
        this->street=street;
        this->city=city;
        this->pin=pin;
    }

    //FACILITATORS

    void accept()
    {
        cout<<"Enter Building : ";
        getline(cin>>ws,this->building);

        cout<<"Enter Street : ";
        getline(cin>>ws,this->street);

        cout<<"Enter City : ";
        getline(cin>>ws,this->city);

        cout<<"Enter Pin : ";
        cin>>this->pin;

    }
    void display()
    {
        cout<<"Building : "<<this->building<<endl;
        cout<<"Street : "<<this->street<<endl;
        cout<<"City : "<<this->city<<endl;
        cout<<"Pin : "<<this->pin<<endl;
    }


    //INSPECTORS
    string get_building()
    {
        return this->building;
    }
    string get_city()
    {
        return this->city;
    }
    string get_street()
    {
        return this->street;
    }
    int get_pin()
    {
        return this->pin;
    }

    //MUTATORS
    void set_building(string building)
    {
         this->building=building;
    }
    void set_city(string city)
    {
        this->city=city;
    }
    void set_street(string street)
    {
        this->street=street;
    }
    void set_pin(int pin)
    {
        this->pin=pin;
    }
    
};


int main()
{
    Address a1("J1","Manhattan","New york",11100);
    // a1.accept();
    a1.display();

    // cout<<a1.get_building()<<endl;
    // cout<<a1.get_city()<<endl;
    // cout<<a1.get_street()<<endl;
    // cout<<a1.get_pin()<<endl;

    
}