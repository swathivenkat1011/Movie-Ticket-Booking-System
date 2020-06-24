#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct booking
{
    char name[20];
    int seatno;
    char age[5];
}book[100];
int booking();
void cancel();
int validate1(char*);
int validate2(char*);
void check();
void display();
int main()
{
    int choice;
    while(1)
    {
    printf("\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ARRS MULTIPLEX CINIMAS-TITANIC\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("1.Booking\n2.Cancel\n3.Check Status\n4.Display\n5.Exit\n");
    scanf("%d",&choice);

    switch(choice)
    {
    case 1:
        booking();
        break;
    case 2:
        cancel();
        break;
    case 3:
        check();
        break;
    case 4:
        display();
        break;
    case 5:
        exit(1);
        break;
    }
    }
}
void display()
{
    int i;
    printf("\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2TICKET BOOKING\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("\t\t=========================================\n");
    printf("\t\tNAME\t\t\tSEAT NO\n");
    printf("\t\t=========================================\n");
    for(i=1;i<=100;i++)
    {
        if(book[i].seatno==1)
        {
            printf("\t\t%s\t\t\t%d\n",book[i].name,i);
        }
    }
}
int booking()
{
    int n,i,seat;
    char str[20],a[5];
    printf("\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 BOOKING\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("Enter the no of seats--------->");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter the seat no---->");
        scanf("%d",&seat);
        if(book[seat].seatno!=1)
        {
            printf("Enter name---->");
            scanf("%s",str);
            if(!validate1(str))
            {
                printf("Enter a valid name\n");
                return 0;
            }
            strcpy(book[seat].name,str);
            printf("Enter age----->");
            scanf("%s",a);
            if(!validate2(a))
            {
                printf("Enter a valid age\n");
                return 0;
            }
            strcpy(book[seat].age,a);
            book[seat].seatno=1;
        }
        else
        {
            printf("seat no %d not available",seat);
        }
    }
}
void cancel()
{
    char str[20];
    int n;
    char ch;
    char y[3]="yes";
    printf("\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2TICKET CANCELATION\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("Enter your name----->");
    scanf("%s",str);
    printf("Enter your seat no----->");
    scanf("%d",&n);
    if(!strcmp(book[n].name,str))
    {
          printf("Cancellation Successfull :)\n");
            book[n].seatno=0;
    }
    else{
        printf("Invalid Cancellation :(\n");
    }
}
void check()
{
    char str[20];
    int flag=0,i;
    printf("\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2TICKET CHECKING\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("Enter your name---->");
    scanf("%s",str);
    for(i=1;i<=100;i++)
    {
        if(!strcmp(str,book[i].name))
        {
            printf("your seat no ----> %d\n",i);
            flag=1;
        }
    }
    if(flag==0){
        printf("you have not yet booked for a movie");
    }
}
int validate1(char* name)
{
    int len,i;
    len=strlen(name);
    for(i=0;i<len;i++)
    {
        if(!(((name[i]>96)&&(name[i]<123))||((name[i]>64)&&(name[i]<91))))
        {
            return 0;
        }
    }
    return 1;
}
int validate2(char* a)
{
    int len,i;
    len=strlen(a);
    for(i=0;i<len;i++)
    {
    if(a[0]=='0')
    {
        return 0;
    }
    if(!((a[i]>47)&&(a[i]<60)))
    {
        return 0;
    }
    }
    return 1;
}
