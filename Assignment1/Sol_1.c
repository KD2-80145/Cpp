//MENU DRIVEN CODE FOR DATE STRUCTURE C

#include<stdio.h>

struct Date{
    int day;
    int month;
    int year;
};

void initDate(struct Date *ptrDate);
void acceptDateFromConsole(struct Date *ptrDate);
void displayDateOnConsole(struct Date *ptrDate);




void initDate(struct Date *ptrDate)
{
    ptrDate->day=22;
    ptrDate->month=9;
    ptrDate->year=2023;   
}

void acceptDateFromConsole(struct Date *ptrDate)
{
    printf("Enter Day : ");
    scanf("%d",&ptrDate->day);

    printf("Enter Month : ");
    scanf("%d",&ptrDate->month);

    printf("Enter Year : ");
    scanf("%d",&ptrDate->year);
}

void displayDateOnConsole(struct Date *ptrDate)
{  
    printf("DATE: %d-%d-%d \n",ptrDate->day,ptrDate->month,ptrDate->year);

}

int main()
{
    struct Date d1;
    while(1)
    {
        printf("**********************************************************\n");
        printf("1.INITIALISE DATE\n2.ACCEPT DATE\n3.DISPLAY DATE\n4.EXIT\n");
        printf("**********************************************************\n");

        int choice;
        printf("Enter your choice: ");
        scanf("%d",&choice);

        
        switch(choice)
        {
            case 1:
                initDate(&d1);
                break;
            case 2:
                acceptDateFromConsole(&d1);
                break;
            case 3:
                displayDateOnConsole(&d1);
                break;
            case 4:
                printf("OUT OF LOOP\n");
                return 0;
            default:
                printf("INVALID CHOICE");
        }

        // break;
    }

}