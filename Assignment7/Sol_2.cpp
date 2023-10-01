#include <iostream>
using namespace std;

class Product
{
protected:
    int id;
    string title;
    float price;
    char TYPE;
    
public:
    Product()
    {
        this->id = -1;
        this->title = "";
        this->price = 0;
    }

    Product(int id, string title, float price)
    {
        this->id = id;
        this->title = title;
        this->price = price;
    }   

    char get_type()
    {
        return this->TYPE;
    }

    virtual void accept() = 0;

    virtual void display() = 0;

    virtual float get_price() = 0;
};

class Book : public Product
{

private:
    string author;

public:
    Book()
    {
        this->TYPE = 'B';
        this->author = "";
    }
    Book(int id, string title, float price, string author) : Product(id, title, price)
    {
        this->author = author;
    }

    void accept()
    {
        int id;
        string title;
        float price;

        cout << "Enter id of Book :";
        cin >> id;
        this->id = id;

        cout << "Enter Title of Book : ";
        cin >> title;
        this->title = title;

        cout << "Enter Price of Book : ";
        cin >> price;
        this->price = price;

        cout << "Enter Author of Book : ";
        cin >> this->author;
    }

    float get_price()
    {
        return this->price;
    }

    void display()
    {
        cout << "Id of Book : " << this->id << endl;
        cout << "Title of Book : " << this->title << endl;
        cout << "Price of Book : " << this->price << endl;
        cout << "Author of Book : " << this->author << endl;
    }
};

class Tape : public Product
{

private:
    string artist;

public:
    Tape()
    {
        this->TYPE = 'T';
        this->artist = "";
    }
    Tape(int id, string title, float price, string artist) : Product(id, title, price)
    {
        this->artist = artist;
    }

    void accept()
    {
        int id;
        string title;
        float price;

        cout << "Enter id of Tape :";
        cin >> id;
        this->id = id;

        cout << "Enter Title of Tape : ";
        cin >> title;
        this->title = title;

        cout << "Enter Price of Tape : ";
        cin >> price;
        this->price = price;

        cout << "Enter Artist of Tape : ";
        cin >> this->artist;
    }
    float get_price()
    {
        return this->price;
    }
    void display()
    {
        cout << "Id of Tape : " << this->id << endl;
        cout << "Title of Tape : " << this->title << endl;
        cout << "Price of Tape : " << this->price << endl;
        cout << "Artist of Tape : " << this->artist << endl;
    }
};

class Shop
{
private:
    static int item_no;
    Product *cart[3];

public:
    Shop()
    {
        for(int i=0;i<3;i++)
        {
            cart[i]=NULL;
        }
    }
    void buyBook()
    {
        if (item_no == 3)
        {
            cout << "Cart is Full, Can not buy more Books.";
            return;
        }

        // Tape t; Product is Abstract class

        cout << endl;
        cart[item_no] = new Book; // Upcasting
        cart[item_no]->accept();
        item_no++;

        cout << endl;
        cout << "You bought a book of Rs" << cart[item_no]->get_price() << endl;
    }

    void buyTape()
    {

        if (item_no == 3)
        {
            cout << "Cart is Full,Can not buy more Tapes.";
            return;
        }
        
        
        cart[item_no] = new Tape; // Upcasting
        cart[item_no]->accept();
        item_no++;

        cout << endl;
        cout << "You bought a Tape of Rs" << cart[item_no]->get_price() << endl;
        ;
    }

    float calc()
    {
        float total_amt = 0;
        for (int i = 0; i < item_no; i++)
        {
            if (cart[i]->get_type() == 'B')
            {
                float bPrice = cart[i]->get_price();
                bPrice = bPrice - (bPrice * 0.01);
                total_amt += bPrice;
            }
            if (cart[i]->get_type() == 'T')
            {
                float tPrice = cart[i]->get_price();
                tPrice = tPrice - (tPrice * 0.05);

                total_amt += tPrice;
            }
        }
        cout << "TOTAL BILL AMOUNT : " << total_amt << endl;
        return total_amt;
    }

    ~Shop()
    {
        // cout << "SHOP DTOR" << endl;
        for (int i = 0; i < 3; i++)
        {
            if (cart[i] != NULL)
                delete cart[i];
        }
    }
};
int Shop::item_no = 0;

enum Bill
{
    BUY_BOOK = 1,
    BUY_TAPE,
    PRINT_BILL
};

Bill menu()
{
    int choice;
    cout << "--------------------------------" << endl;
    cout << "Enter your choice : " << endl;
    cout<< "0. EXIT"<<endl;
    cout << "1. Buy Book" << endl;
    cout << "2. Buy Tape" << endl;
    cout << "3. Print Bill" << endl;
    cout << "--------------------------------" << endl;
    cin >> choice;

    return Bill(choice);
}

int main()
{
    Shop s1;
    Bill choice;
    while((choice = menu())!=0)
    {
        switch(choice)
        {
            case BUY_BOOK:
                s1.buyBook();

                break;
            case BUY_TAPE:
                s1.buyTape();
                break;
            case PRINT_BILL:
                s1.calc();
                break;
            default :
                cout<<"Invalid Choice"<<endl;

        }
    }
    return 0;

}