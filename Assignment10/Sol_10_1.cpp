#include <iostream>
#include <vector>

using namespace std;

class Box
{
private:
    double len;
    double wdth;
    double hght;

public:
    Box()
    {
        this->len = 0;
        this->hght = 0;
        this->wdth = 0;
    }
    Box(double len)
    {
        this->len = len;
        this->wdth = 0;
        this->hght = 0;
    }
    Box(double len, double wdth)
    {
        this->len = len;
        this->wdth = wdth;
        this->hght = 0;
    }
    Box(double len, double wdth, double hgth)
    {
        this->len = len;
        this->wdth = wdth;
        this->hght = hght;
    }
    void accept()
    {
        cout << "please enter length : ";
        cin >> this->len;
        cout << "please enter width : ";
        cin >> this->wdth;
        cout << "please enter hight : ";
        cin >> this->hght;
    }
    void display()
    {
        cout << "Length : " << len << endl;
        cout << "Width : " << wdth << endl;
        cout << "Hight : " << hght << endl;
    }

    void volume()
    {
        cout << "THE VOLUME OF THE BOX IS : " << len * wdth * hght << endl;
    }
};

template <class T>
class Stack
{
    // Data members
    vector<T> arr;
    int top = -1;
    int size;

    // Functionality
public:
    Stack(int size)
    {
        this->size = size;
    }
    void push(T element)
    {
        if (this->top < this->size - 1)
        {
            this->top++;
            arr.push_back(element);
            cout << "Element added " << endl;
        }
        else
        {
            cout << "STACK OVERFLOW : NOT ADDED " << endl;
        }
    }

    void pop()

    {
        if (top > 0)
        {

            arr.pop_back();
            cout << "Element deleted " << endl;

            top--;
        }
        else
        {
            cout << "STACK UNDERFLOW : EMPTY" << endl;
        }
    }

    T peek()
    {
        if (top >= 0)
            return arr[top];
        cout << "empty" << endl;
        return NULL;
    }

    bool isEmpty()
    {
        return top < 0;
    }

    void print()
    {
        cout << "STACK :" << endl;
        for (int i = 0; i <= top; i++)
        {
            cout << arr[i] << endl;
        }
        cout << "------END-------" << endl;
    }

    T at(int index)
    {
        if (index <= top)
            return arr[index];
        return NULL;
    }

    int length()
    {
        return top;
    }
};

int menu()
{
    int flag;
    cout << "-----------------------------------------" << endl;
    cout << "WELCOME TO CPP - STACK  - Operations " << endl;
    cout << "0. Exit" << endl;
    cout << "1. Push " << endl;
    cout << "2. Pop " << endl;
    cout << "3. Peek  " << endl;
    cout << "4. isEmpty  " << endl;
    cout << "5. Print  " << endl;
    cout << "Please enter your choice : ";
    cin >> flag;
    cout << "------------------------------------------" << endl;
    return flag;
}

int menu2()
{
    int flag;
    cout << "-----------------------------------------" << endl;
    cout << "WELCOME TO CPP - STACK using vectors" << endl;
    cout << "ENTER WHAT TYPE OF STACK" << endl;
    cout << "0. Exit" << endl;
    cout << "1. Box " << endl;
    cout << "2. int " << endl;
    cout << "3. double  " << endl;
    cout << "Please enter your choice : ";
    cin >> flag;
    cout << "------------------------------------------" << endl;
    return flag;
}

int main(void)
{
    int flag1;
    while ((flag1 = menu2()) != 0)
    {
        switch ((flag1))
        {
        case 1:
        {

            int size;
            cout << "Please enter the size of stack : ";

            cin >> size;
            Stack<Box> s1(size);

            int flag;
            while ((flag = menu()) != 0)
            {

                switch (flag)
                {
                case 1:
                {
                    Box b1;
                    b1.accept();
                    s1.push(b1);
                }
                break;
                case 2:
                    s1.pop();
                    break;
                case 3:
                    s1.peek().display();
                    break;
                case 4:
                    if (s1.isEmpty())
                    {
                        cout << "Empty" << endl;
                    }
                    else
                    {
                        cout << "NOT EMPTY" << endl;
                    }
                    break;
                case 5:
                    for (int i = 0; i <= s1.length(); i++)
                    {
                        s1.at(i).display();
                    }
                    break;
                default:
                    cout << "Please Try Again :" << endl;
                    break;
                }
            }
        }
        break;

        case 2:
        {

            int size;
            cout << "Please enter the size of stack";

            cin >> size;
            Stack<int> s1(size);

            int flag;
            while ((flag = menu()) != 0)
            {

                switch (flag)
                {
                case 1:
                {
                    cout << "please enter value :" << endl;
                    int b1;
                    cin >> b1;
                    s1.push(b1);
                }
                break;
                case 2:
                    s1.pop();
                    break;
                case 3:
                    cout << s1.peek() << endl;
                    break;
                case 4:
                    if (s1.isEmpty())
                    {
                        cout << "Empty";
                    }
                    break;
                case 5:
                    s1.print();
                    break;
                default:
                    cout << "Please Try Again :" << endl;
                    break;
                }
            }
        }
        break;

        case 3:
        {

            int size;
            cout << "Please enter the size of stack";

            cin >> size;
            Stack<double> s1(size);

            int flag;
            while ((flag = menu()) != 0)
            {

                switch (flag)
                {
                case 1:
                {
                    cout << "please enter value :" << endl;
                    double b1;
                    cin >> b1;
                    s1.push(b1);
                }
                break;
                case 2:
                    s1.pop();
                    break;
                case 3:
                    cout << s1.peek() << endl;
                    break;
                case 4:
                    if (s1.isEmpty())
                    {
                        cout << "Empty";
                    }
                    break;
                case 5:
                    s1.print();
                    break;
                default:
                    cout << "Please Try Again :" << endl;
                    break;
                }
            }
        }
        break;

        default:
            cout << "please try again" << endl;
            break;
        }
    }
    return 0;
}