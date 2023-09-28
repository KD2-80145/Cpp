#include <iostream>

using namespace std;

// BASE
class Employee
{

private:
    int id;
    float sal;

public:
    // Constructors
    Employee()
    {
        this->id = 0;
        this->sal = 0;
    }
    Employee(int id, float sal)
    {
        this->id = id;
        this->sal = sal;
    }

    // Getters
    int get_id()
    {
        return this->id;
    }

    float get_sal()
    {
        return this->sal;
    }

    // Setters
    void set_id(int id)
    {
        this->id = id;
    }

    void set_sal(float sal)
    {
        this->sal = sal;
    }

    // Facilitators
    void accept()
    {
        cout << "Enter Id : ";
        cin >> this->id;

        cout << "Enter Sal : ";
        cin >> this->sal;
    }

    void display()
    {

        cout << "Id : " << this->id << endl;
        cout << "Salary : " << this->sal << endl;
    }
};

// DERIVED 1
class Manager : virtual protected Employee
{
private:
    float bonus;

public:
    // Constructors

    Manager()
    {
        this->bonus = 0;
    }

    Manager(int id, float sal, float bonus) : Employee(id, sal)
    {
        this->bonus = bonus;
    }

    // Instpectors

    float get_bonus()
    {
        return this->bonus;
    }

    // Mutators
    void set_bonus(float bonus)
    {
        this->bonus = bonus;
    }

    // Facilitators
    void display()
    {
        cout << "Bonus : " << this->bonus << endl;
    }

    void display_manager()
    {
        this->Employee::display();
        this->display();
    }

    void accept()
    {
        this->Employee::accept();
        cout << "Enter bonus : ";

        cin >> this->bonus;
    }

    void accept_manager()
    {
        int id;
        float sal;
        float bonus;

        cout << "Enter Id of Manager : ";
        cin >> id;
        this->Employee::set_id(id);

        cout << "Enter Salary of Manager : ";
        cin >> sal;
        this->Employee::set_sal(sal);

        cout << "Enter Bonus of Manager : ";
        cin >> this->bonus;
    }
};

// DERIVED 2
class Salesman : virtual protected Employee
{
protected:
    float comm;

public:
    // Constructors
    Salesman()
    {
        this->comm = 0;
    }
    Salesman(int id, float sal, float comm) : Employee(id, sal)
    {
        this->comm = comm;
    }

    // Inspectors
    float get_comm()
    {
        return this->comm;
    }

    // Mutators
    void set_comm(float comm)
    {
        this->comm = comm;
    }

    // Facilitators
    void display()
    {
        cout << "Commission : " << this->comm << endl;
    }

    void display_salesman()
    {
        this->Employee::display();
       this->display();
    }

    void accept()
    {
        this->Employee::accept();
        cout << "Enter Commission : ";

        cin >> this->comm;
    }

    void accept_salesman()
    {
        int id;
        float sal;

        cout << "Enter Id of Salesman : ";
        cin >> id;
        this->Employee::set_id(id);

        cout << "Enter Salary of Salesman : ";
        cin >> sal;
        this->Employee::set_sal(sal);

        cout << "Enter Commission of Salesman : ";
        cin >> this->comm;
    }
};

class Sales_manager : Manager, Salesman
{
public:
    Sales_manager()
    {
    }

    Sales_manager(int id, float sal, float bonus, float comm) : Employee(id, sal)
    {
        Manager::set_bonus(bonus);
        Salesman::set_comm(comm);
    }

    void display()
    {
        this->Employee::display();
        this->Manager::display();
        this->Salesman::display();
    }

    void accept()
    {
    }
};
int main()
{
    Sales_manager s1(10, 5000, 100, 200);

    s1.display();
}