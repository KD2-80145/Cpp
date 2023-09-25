#include<iostream>
using namespace std;

class Stack
{
private:
    int top;
    int *arr;
    int size;

public:
    Stack()
    {
        arr = new int[5];
        this->size=5;
        top=-1;
    }

    Stack(int size)
    {
        arr = new int[size];
        this->size=size;
    }

    void Push(int ele)
    {
        if(this->isFull())
        {
            resize();
        }
        top++;
        arr[top]=ele;
    }

    int pop()
    {
        if(this->isEmpty())
        {
            cout<<"STACK IS EMPTY."<<endl;
        }
        int last_ele=arr[this->top];
        this->top--;
        return last_ele;
    }

    int peek()
    {
        if(this->isEmpty())
        {
            cout<<"STACK IS EMPTY."<<endl;
        }
        return arr[this->top];
    }



    bool isEmpty()
    {
        return this->top == -1;
    }

    bool isFull()
    {
        return this->top==(this->size-1);
    }

    void print()
    {
        if(!this->isEmpty())
        {
            cout<<"STACK FROM TOP TO BOTTOM : "<<endl;
            for(int i=top;i>=0;i--)
            {
                cout<<i+1<<" Element : ";
                cout<<arr[i]<<endl;
            }
        }
        else{
            cout<<"STACK IS EMPTY."<<endl;
        }
    }

    void resize()
    {
        int *arr1=new int[this->size*2];
        for(int i=0;i<=top;i++)
        {
            arr1[i]=arr[i];
        }

        this->arr=arr1;
    }
};

int main()
{
    // Stack s1;
    // s1.Push(1);
    // s1.Push(2);
    // s1.Push(3);
    // cout<<"PEEK : "<<s1.peek()<<endl;
    // s1.Push(4);
    // s1.Push(5);
    // s1.Push(6);

    // cout<<"POP : "<<s1.pop()<<endl;
    // cout<<"POP : "<<s1.pop()<<endl;
    // cout<<"POP : "<<s1.pop()<<endl;
    // cout<<"POP : "<<s1.pop()<<endl;
    // cout<<"POP : "<<s1.pop()<<endl;
    // s1.Push(6);

    // s1.print();
}