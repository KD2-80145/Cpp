#include <iostream>
using namespace std;

// Employee class
class Employee
{
    // private data members
private:
    int id;
    float sal;
    // protected data members
protected:
    string type;

    // member functions
public:
    // parameterless constructor // default = -99
    Employee()
    {
        this->id = -99;

        this->sal = -99;
    }

    // parameterized construrtor
    Employee(int id, float sal)

    {
        this->id = id;
        this->sal = sal;
    }

    // Inspectors
    string getType()
    {

        return type;
    }
    int get_id()
    {
        return this->id;
    }
    float get_sal()
    {
        return this->sal;
    }

    // Mutators
    void set_sal(float sal)
    {
        this->sal = sal;
    }
    void set_id(int id)
    {
        this->id = id;
    }

    // Accept
    virtual void accept()
    {

        cout << "Please Enter id : ";
        cin >> this->id;

        cout << "Please Enter sal : ";
        cin >> this->sal;
    }

    // Display
    virtual void display()
    {
        cout << "Id : " << this->id << endl;
        cout << "Sal : " << this->sal << endl;
    }
};

class Manager : virtual public Employee
{
    // data members
private:
    float bonus;
    // member functions
public:
    // Parameterless constructor
    Manager()
    {
        this->bonus = -99;
    }

    // Parameterised constructor
    Manager(int id, float sal, float bonus) : Employee::Employee(id, sal)
    {
        this->bonus = bonus;
    }

    // Inspecters

    float get_bonus()
    {
        return this->bonus;
    }

    // Mutators
    void set_bonus(float bonus)
    {
        this->bonus = bonus;
    }

    // Accept Function

    virtual void accept()
    {
        this->type = "m";
        Employee::accept();
        cout << "Please enter Bonus : ";
        cin >> this->bonus;
    }

    // Display Funtion

    void display()
    {
        Employee::display();
        cout << "Bonus :" << this->bonus << endl;
    }

    // Some protected Functions to maintain Abstraction
protected:
    void display_manager()
    {
        cout << "Bonus :" << this->bonus << endl;
    }

    void accept_manager()
    {
        cout << "Please enter Bonus : ";
        cin >> this->bonus;
    }
};

// SalesMan class
class Salesman : virtual public Employee
{
    // data members
private:
    float comm;
    // member functions
public:
    // Parameterless constructor
    Salesman()
    {
        this->comm = -99;
    }

    // Parameterised constructor
    Salesman(int id, float sal, float comm) : Employee::Employee(id, sal)
    {
        this->comm = comm;
    }

    // Inspecters

    float get_comm()
    {
        return this->comm;
    }

    // Mutators
    void set_comm(float comm)
    {
        this->comm = comm;
    }

    // Accept Function

    virtual void accept()
    {
        this->type = "s";
        Employee::accept();
        cout << "Please enter comm : ";
        cin >> this->comm;
    }

    // Display Funtion

    void display()
    {
        Employee::display();
        cout << "comm :" << this->comm << endl;
    }

    // Some protected Functions to maintain Abstraction
protected:
    void display_salesman()
    {
        cout << "comm :" << this->comm << endl;
    }

    void accept_salesman()
    {
        cout << "Please enter comm : ";
        cin >> this->comm;
    }
};

// sales_manager Class

class Sales_manager : public Manager, public Salesman
{

public:
    // Member Functions
    Sales_manager()
    {
    }
    Sales_manager(int id, float sal, float bonus, float comm) : Employee(id, sal), Manager(id, sal, bonus), Salesman(id, sal, comm)
    {
    }

    // Display function
    void display()
    {
        Employee::display();
        Manager::display_manager();
        Salesman::display_salesman();
    }

    // Accept function
    void accept()
    {
        this->type = "sm";
        Employee::accept();
        Manager::accept_manager();
        Salesman::accept_salesman();
    }
};

// menu function

int menu()
{
    int flag;
    cout << "-----------------------------------------" << endl;
    cout << "WELCOME TO CPP - Employee management" << endl;
    cout << "0. Exit" << endl;
    cout << "1. Accept Employee " << endl;
    cout << "2. Display the count with respect to designation " << endl;
    cout << "3. Display respective designation " << endl;
    cout << "4. Display ALL employee " << endl;
    cout << "Please enter your choice : ";
    cin >> flag;
    cout << "------------------------------------------" << endl;
    return flag;
}

int main()
{

    Employee *arr[10];
    string designation;
    int index = 0;
    int scount = 0;
    int mcount = 0;
    int smcount = 0;
    int flag;
    while ((flag = menu()) != 0)
    {
        switch (flag)
        {
        case 1:
            if (index < 10)
            {
                cout << "Please type the designation (s-Salesman , m-Manager , sm-salesmanager) : ";
                cin >> designation;
                if (designation == "s")
                {
                    arr[index] = new Salesman;
                    arr[index]->accept();
                    index++;
                }
                else if (designation == "m")
                {
                    arr[index] = new Manager;
                    arr[index]->accept();
                    index++;
                }
                else if (designation == "sm")
                {
                    arr[index] = new Sales_manager;
                    arr[index]->accept();
                    index++;
                }
                else
                {
                    cout << "WRONG SELECTION , TRY AGAIN " << endl;
                }
            }
            else
            {
                cout << "List is full " << endl;
            }

            break;
        case 2:
            scount = 0;
            mcount = 0;
            smcount = 0;
            for (int i = 0; i < index; i++)
            {
                if (arr[i]->getType() == "s")
                {
                    scount++;
                }
                else if (arr[i]->getType() == "m")
                {
                    mcount++;
                }
                else if (arr[i]->getType() == "sm")
                {
                    smcount++;
                }
            }
            cout << "Manager : " << mcount << endl;
            cout << "Salesman : " << scount << endl;
            cout << "Sales_Manager : " << smcount << endl;

            break;
        case 3:
            cout << "Please type the designation (s-Salesman , m-Manager , sm-salesmanager) : ";
            cin >> designation;
            for (int i = 0; i < index; i++)
            {
                if (designation == arr[i]->getType())
                {
                    arr[i]->display();
                }
            }

            break;
        case 4:
            for (int i = 0; i < index; i++)
                arr[i]->display();

            break;
        default:
            cout << "Please Try Again :" << endl;
            break;
        }
    }

    for (int i = 0; i < index; i++)
        delete[] arr[i];
}