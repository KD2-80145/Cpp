#include<iostream>
using namespace std;

int factorial(int num)
{
    if(num<0){
        throw -1;
    }
    if(num == 0 || num==1)
    {
        return num;
    }

    return num*factorial(num-1);
}

int main()
{
    try{
    cout<<factorial(-1)<<endl;
    }
    catch(int err)
    {
        cout<<"Do not enter Negative Number."<<endl;
    }
}