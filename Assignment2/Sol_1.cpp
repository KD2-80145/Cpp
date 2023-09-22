#include <iostream>
using namespace std;
namespace NStudent
{
    class Student
    {

        int roll_no;
        string name;
        int marks;

    public:
        void initStudent()
        {
            this->roll_no = 1;
            this->name = "Abhey";
            this->marks = 90;
        }
        void printStudentOnConsole()
        {
            cout << "----------------------------------------------------------" << endl;
            cout << "Roll No : " << this->roll_no << endl;
            cout << "Name : " << this->name << endl;
            cout << "Marks : " << this->marks << endl;

            cout << "-----------------------------------------------------------" << endl;
        }
        void acceptStudentFromConsole()
        {
            string name;

            cout << "Enter Roll No : ";
            cin >> this->roll_no;

            cout << "Enter Name : ";

            getline(cin>>ws,this->name);

            cout << "Enter Marks : ";
            cin >> this->marks;
        }
    };
}
int main()
{

    NStudent::Student s1;

    while (1)
    {
        printf("**********************************************************\n");
        printf("1.INITIALISE STUDENT\n2.ACCEPT STUDENT DEATILS\n3.DISPLAY STUDENT DETAILS\n4.EXIT\n");
        printf("**********************************************************\n");

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        

        switch (choice)
        {
        case 1:
            s1.initStudent();
            break;
        case 2:
            s1.acceptStudentFromConsole();
            break;
        case 3:
            s1.printStudentOnConsole();
            break;
        case 4:
            cout << "OUT OF LOOP" << endl;
            return 0;
        default:
            printf("INVALID CHOICE");
            break;
        }

        // break;
    }
    return 0;
}