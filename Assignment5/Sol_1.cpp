#include <iostream>
#include <array>
using namespace std;

class Student
{
private:
    string Name;
    char Gender;
    int Roll_no;
    int marks[3];

    double calcPercentage()
    {
        double marks = 0;
        for (int i = 0; i < 3; i++)
            marks += this->marks[i];

        return (marks / 300) * 100;
    }

public:
    //INSPECTOR
    int getRoll()
    {
        return this->Roll_no;
    }

    //MUTATOR
    void acceptDetails()
    {
        cout << "Enter Roll No. : ";
        cin >> this->Roll_no;

        getchar();

        cout << "Enter Name : ";
        getline(cin, this->Name);
        // cin>>this->Name;

        cout << "Enter Gender : ";
        cin >> this->Gender;

        for (int i = 0; i < 3; i++)
        {
            cout << "Enter Marks of " << (i + 1) << " Subject : ";
            cin >> this->marks[i];
        }
    }

    //FACILITATOR
    void print_Details()
    {
        cout << "Roll No. : " << this->Roll_no << endl;

        cout << "Name : " << this->Name << endl;

        cout << "Gender : " << this->Gender << endl;

        cout << "Percentage : " << this->calcPercentage() << endl;
    }
};

void swap(Student arr[], int i, int j)
{
    Student temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void sortRecords(Student arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j].getRoll() > arr[j + 1].getRoll())
            {
                swap(arr,j,j+1);
            }
        }
    }
}

int searchRecords(Student arr[], int n)
{
    int roll_no;
    cout << endl<<"Enter Roll No : ";

    cin >> roll_no;

    for(int i=0;i<n;i++)
    {
        if(arr[i].getRoll() == roll_no){
            cout<<"Roll no : "<<roll_no<<" exists at Idx "<<i<<endl;
            return i;
        }
    }

    cout << "Student with Roll No :" << roll_no << " doesn't exists."<<endl;
    return -1;
}

void acceptObjects(Student s_arr[],int n)
{
    for (int i = 0; i < n; i++)
    {
        cout<<"-------------------------------------"<<endl;
        cout << "Enter Details of " << i + 1 << " Student." << endl;
        Student temp;
        temp.acceptDetails();
        s_arr[i] = temp;
    }
}
void printObjects(Student s_arr[],int n)
{
    cout<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<"--------------------------------------"<<endl;
        cout << "Details of " << i + 1 << " Student: " << endl;
        s_arr[i].print_Details();
    }
}
enum Enum
{
    ACCEPT=1,
    PRINT,
    SEARCH,
    SORT
};
Enum menu()
{
    int choice;

    cout<<"****************************"<<endl;
    cout<<"0. EXIT"<<endl;
    cout<<"1. ACCEPT"<<endl;
    cout<<"2. PRINT"<<endl;
    cout<<"3. SEARCH"<<endl;
    cout<<"4. SORT"<<endl;
    cout<<"****************************"<<endl;

    cout<<"Enter Choice: ";
    cin>>choice;

    return Enum(choice);
}
int main()
{
    int n;

    cout << "Enter No of Students : " << endl;
    cin >> n;

    Student s_arr[n];

    Enum choice;

    while((choice=menu())!=0)
    {
        switch(choice)
        {
            case ACCEPT :
                acceptObjects(s_arr,n);
                break;
            case PRINT :
                printObjects(s_arr,n);
                break;
            case SEARCH:
                searchRecords(s_arr,n);
                break;
            case SORT:
                sortRecords(s_arr,n);
                cout<<"SORTING COMPLETE."<<endl;
                break;
            default:
                cout<<"INVALID CHOICE";
                break;
            
        }
    }
    return 0;
}