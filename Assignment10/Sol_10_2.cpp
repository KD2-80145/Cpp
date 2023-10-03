#include <iostream>
#include <vector>
using namespace std;

// Exceptoion class

class Insufficient_funds
{
    // private data members
private:
    int accid;
    double cur_balance;
    double withdraw_amount;
    // member Functions
public:
    Insufficient_funds(int accid, double cur_balance, double withdraw_amount)
    {
        this->accid = accid;
        this->cur_balance = cur_balance;
        this->withdraw_amount = withdraw_amount;
    }
    void display()
    {
        cout << "ERROR  : INSUFFICIENT FUNDS" << endl;
        cout << "Cant withdraw " << this->withdraw_amount << " from your account having balance :" << this->cur_balance << endl;
    }
};

// enums

enum account_type
{
    SAVING,
    CURRENT,
    DMAT

};

// Account class

class Account
{
    // private data members;
private:
    int id;
    account_type type;
    double balance;

    // public functions members;
public:
    Account()
    {
    }
    Account(int id, account_type type, double balance)
    {
        this->id = id;
        this->type = type;
        this->balance = balance;
    }

    void accept()
    {
        int choice;

        cout << "Please Enter the Acc Id : ";
        cin >> this->id;

        cout << "Please Enter the account type (0 for Saving , 1 for current , 2 for dmat) : ";
        cin >> choice;

        this->type = account_type(choice);

        cout << "Please Enter the starting balance : ";
        cin >> this->balance;
    }

    void display()
    {
        cout << "Account Id : " << this->id << endl;

        cout << "Account type : ";
        switch (type)
        {
        case SAVING:
            cout << "Saving ";
            break;

        case CURRENT:
            cout << "Current ";
            break;

        case DMAT:
            cout << "Dmat ";
            break;
        }
        cout << endl;
        cout << "Current balance : " << this->balance << endl;
    }

    void set_id(int id)
    {
        this->id = id;
    }

    void set_type(account_type t)
    {
        this->type = t;
    }

    int get_id()
    {
        return this->id;
    }
    account_type get_type()
    {
        return this->type;
    }

    double get_balance()
    {
        return this->balance;
    }

    void deposite(double amount)
    {
        this->balance += amount;
        cout << "The updated balance : " << this->balance << endl;
    }

    void withdraw(double amount)
    {
        if (amount > this->balance)
            throw Insufficient_funds(this->id, this->balance, amount);

        else
        {
            this->balance -= amount;
            cout << "The updated balance : " << this->balance << endl;
        }
    }
};

int menu()
{
    int flag;
    cout << "-----------------------------------------" << endl;
    cout << "WELCOME TO CPP - BANK ACCOUNTS" << endl;
    cout << "0. Exit" << endl;
    cout << "1. Deposite " << endl;
    cout << "2. Withdraw " << endl;
    cout << "3. Display the account detais  " << endl;
    cout << "4. Display ALL account detais in order " << endl;
    cout << "5. Display ALL account detais in reverse order " << endl;
    cout << "Please enter your choice : ";
    cin >> flag;
    cout << "------------------------------------------" << endl;
    return flag;
}

int main()
{

    vector<Account> arr;
    for (int i = 0; i < 5; i++)
    {
        cout << "PLEASE ENTER YOUR BANK DETAILS : " << endl;
        Account a1;
        a1.accept();
        arr.push_back(a1);
    }
    double temp;
    int temp2;
    int flag;
    while ((flag = menu()) != 0)
    {

        switch (flag)
        {
        case 1:
            cout << "Please enter your acc no : ";
            cin >> temp2;

            for (int i = 0; i < 5; i++)
            {
                if (arr[i].get_id() == temp2)
                {
                    cout << "Please enter Amount : ";
                    cin >> temp;
                    arr[i].deposite(temp);
                }
            }
            break;
        case 2:

            cout << "Please enter your acc no : ";
            cin >> temp2;

            for (int i = 0; i < 5; i++)
            {
                if (arr[i].get_id() == temp2)
                {
                    cout << "Please enter Amount : ";
                    cin >> temp;
                    try
                    {
                        arr[i].withdraw(temp);
                    }
                    catch (Insufficient_funds e)
                    {
                        e.display();
                    }
                }
            }

            break;
        case 3:
            cout << "Please enter your acc no : ";
            cin >> temp2;

            for (int i = 0; i < 5; i++)
            {
                if (arr[i].get_id() == temp2)
                {

                    arr[i].display();
                }
            }
            break;
        case 4:
            for (int i = 0; i < arr.size(); i++)
                arr[i].display();
            break;
        case 5:
            for (int i = arr.size() - 1; i >= 0; i--)
                arr[i].display();
            break;
        default:
            cout << "Please Try Again :" << endl;
            break;
        }
    }

    return 0;
}