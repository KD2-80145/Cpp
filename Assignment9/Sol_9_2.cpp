#include<iostream>
using namespace std;


enum account_type{
    SAVING=10,
    CURRENT=20,
    DMAT=30
};

class insufficient_funds
{
    int acc_id;
    double curr_balance;
    double withdraw_amount;

public:
    insufficient_funds(int acc_id,double curr_balance,double withdraw_amount)
    {
        this->acc_id=acc_id;
        this->curr_balance=curr_balance;
        this->withdraw_amount=withdraw_amount;
    }

    void display()
    {
        cout<<"ERROR : Can't Withdraw money, Insufficient Balance."<<endl;
        cout<<"Withdrawl amount : "<<this->withdraw_amount<<endl;
        cout<<"Current Balance : "<<this->curr_balance<<endl;
    }
};

class Account
{
    int id;
    account_type type;
    double balance;

public:
    Account()
    {

    }

    Account(int id,account_type type,double balance)
    {
        this->id=id;
        this->type=type;
        this->balance=balance;
    }

    int get_id()
    {
        return this->id;
    }

    double get_balance()
    {
        return this->balance;
    }

    account_type get_type()
    {
        return type;
    }

    void set_id(int id)
    {
        this->id=id;
    }

    void set_type(account_type type)
    {
        this->type=type;
    }

    void withdraw(double amount)
    {
        if(amount > this->get_balance()){
            throw insufficient_funds(this->id,this->get_balance(),amount);
        }
        this->balance=this->balance-amount;
        cout<<"UPDATED BALANCE : "<<this->balance<<endl;
    }   

    void deposit(double amount)
    {
        this->balance=this->balance+amount;
        cout<<"UPDATED BALANCE : "<<this->balance<<endl;
    }

    void accept()
    {
        cout<<"Enter Id :";
        cin>>this->id;

        cout<<"Enter type: ";
        cout<<"Type of Account ::"<<endl<<"10 for Savings"<<endl<<"20 Current"<<endl<<"30 Dmat: "<<endl;
        int choice;
        cin>>choice;
        this->type=account_type(choice);

        cout<<"Enter balance: ";
        cin>>this->balance;
    }

    //Display all account details
    void display()
    {
        cout<<"---------------ACCOUNT DETAILS-----------------"<<endl;

        cout<<"Id : "<<this->id<<endl;
        cout<<"Type of Account : ";
        switch(this->type){
            case SAVING:
                cout<<"SAVINGS"<<endl;
                break;
            case CURRENT:
                cout<<"CURRENT"<<endl;
                break;
            case DMAT:
                cout<<"DMAT"<<endl;
                break;
        }

        cout<<"Balance : "<<this->balance<<endl;
    }

};

enum Emenu
{
    CREATE=1,
    DEPOSIT,
    WITHDRAW,
    DISPLAY
};

Emenu menu()
{
    cout<<"-----------------------------------------------------------"<<endl;
    cout<<"Enter your choice : "<<endl;
    cout<<"0. EXIT"<<endl;
    cout<<"1. CREATE ACCOUNT"<<endl;
    cout<<"2. DEPOSIT"<<endl;
    cout<<"3. WITHDRAW"<<endl;
    cout<<"4. DISPLAY"<<endl;
    cout<<"-----------------------------------------------------------"<<endl;

    int choice;
    cin>>choice;
    return Emenu(choice);
}
int main()
{
    Account *bank[5];//static ptr pointing to static memory
    int acc_no=0;
    Emenu choice;

    int id=-1;
    bool found_acc=false;
    double amt=0;

    while((choice=menu())!=0)
    {
        switch (choice)
        {
        case CREATE:
            bank[acc_no]->accept();
            acc_no++;
            break;
        case DEPOSIT:
            id=-1;
            found_acc=false;
            amt=0;

            cout<<"Enter id of account : ";
            cin>>id;
            for(int i=0;i<acc_no;i++)
            {
                if(bank[i]->get_id()==id)
                {
                    cout<<"Enter Amount to deposit : "<<endl;
                    cin>>amt;
                    bank[i]->deposit(amt);
                    found_acc=true;
                    break;
                }
            }
            if(!found_acc)
            {
                cout<<"No Such account with id = "<<id<<endl;
            }
            break;
        case WITHDRAW:
            id=-1;
            found_acc=false;
            amt=0;
            
            cout<<"Enter id of account : ";
            cin>>id;
            
            for(int i=0;i<acc_no;i++)
            {
                if(bank[i]->get_id()==id)
                {
                    found_acc=true;
                    cout<<"Enter Amount to withdraw : "<<endl;
                    cin>>amt;
                    try{
                        bank[i]->withdraw(amt);    
                    }
                    catch(insufficient_funds e)
                    {
                        e.display();
                    }
                    
                    break;
                }
            }
            if(!found_acc)
            {
                cout<<"No Such account with id = "<<id<<endl;
            }
            break;
        case DISPLAY:
            id=-1;
            found_acc=false;

            cout<<"Enter id of account : ";
            cin>>id;
            for(int i=0;i<acc_no;i++)
            {
                if(bank[i]->get_id()==id)
                {
                    bank[i]->display();
                    found_acc=true;
                    break;
                }
            }
            if(!found_acc)
            {
                cout<<"No Such account with id = "<<id<<endl;
            }

            break;
        
        default:
            break;
        }
    }

    return 0;
}