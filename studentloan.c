/*
Developed by: Harsh Bardhan Mishra
E-Mail: hbmcasper@gmail.com
College: Sathyabama Institute of Science and Technology
GitHub Account: github.com/harshcasper
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <ctype.h>
#include <dos.h>
#include <time.h>
float creditX(float a,float b,float c,float d); // Used for calculating the Scholarship Score for the Student
void mainmenu(); //Used for displaying the Main Menu
void addrec();   //Used for adding a new record
void delrec();   //Used for deleting a previous record
void search();   //Used for Searching and Displaying a Record
void gotoxy();
void X();
COORD coord = {0, 0};
COORD max_res,cursor_size;
char password[10]={"mishra9"}; //Here is the password which will be used to access the application
// Here a Structure named as record will be kept with two Structure Variables named aa and ab
struct record
{
char name[100];  //Used to store the name of the student
char time[9];    //Used to store the date of birth
int sib;         //Used to store the number of younger/elder siblings of the student
char app[100];   //Used to store the application number
char parent[100]; //Used to store the Parent Name
float credit;    //Used to store the Credit Score of the Parent given to him by Banks
char pan[100];   //Used to store the Pan Number of Parent
float tenth;     //Used to store his percentage of marks for Tenth Standard
float twe;       //Used to store his percentage of marks for Twelfth Standard
char tenthid[100]; //Used to store the Registartion ID of his Tenth Standard
char tweid[100]; // Used to store the Registartion ID of his Twelfth Standard
float jee; //Used to store the Engineering Entrance Exam Score of the Student
char jeeid[100]; //Used to store the Engineering Entrance Exam Registration Number of the Student
char mail[100]; //Used to store the E-Mail Address
float ccc; //Used to store the Credit Score
}aa,ab;
void delay(unsigned int milli) //Delay() Function
{
    clock_t target = milli + clock();
    while (target > clock());
}
void gotoxy (int x, int y) //Used to set the position
{
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
int t(void) //Used to denote the Time
{
time_t t;
time(&t);
printf("Date and time:%s\n",ctime(&t));

return 0 ;
}
int main()   //Main() Function Starts
{
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_GREEN|BACKGROUND_INTENSITY); //Used for setting the Background as Green
X(); //Calling the Password Function
getch();
}
void mainmenu()
{
system("cls");
int ch;
gotoxy(60,8);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Student Loan Application \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

gotoxy(60,10);
printf("\xDB\xDB\xDB\xDB\xB2 1. Add a New Application   ");
gotoxy(60,12);
printf("\xDB\xDB\xDB\xDB\xB2 2. Delete a Previous Application");
gotoxy(60,14);
printf("\xDB\xDB\xDB\xDB\xB2 3. Search an Already Existing Application");
gotoxy(60,16);
printf("\xDB\xDB\xDB\xDB\xB2 4. About the Application");
gotoxy(60,18);
printf("\xDB\xDB\xDB\xDB\xB2 5. Close Application");
gotoxy(60,20);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(60,22);
t();
gotoxy(60,25);
printf("Plese enter your choice:");
scanf("%d",&ch);
switch(ch) //Switch Case to get the User Input
{
case 1:
addrec(); //Adding a New Application
break;
case 2:
delrec(); //Deleting an older Application
break;
case 3:
search(); //Searching a previous application
break;
case 4:
system("cls");
gotoxy(50,8);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 About the Application \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(50,10);
printf("This application has been designed in C Programming Language Environement as an assignment to input and store,");
gotoxy(50,12);
printf("Student Information who are applying for an Educational Loan. The amount of Educational Loan given is calculated");
gotoxy(50,14);
printf("based upon your Parent's Credit Score, 10th Standard Score, 12th Standard Score and Engineering Entrance Exam.");
gotoxy(50,16);
printf("This application has been designed for Robust and Flexible Use. For any bugs report to hbmcasper@gmail.com.");
gotoxy(50,18);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
char ty;
gotoxy(50,22);
printf("To continue back to the Main Menu press 'Y' or 'y'. To exit the application completely press anything else: ");
scanf("%c",&ty);
if(ty=='Y'||ty=='y')
{
mainmenu();
}
else
{
exit(0);
}
break;
case 5:  //Exiting the Application and showing the credits
system("cls");
gotoxy(60,10);
printf("Created by Harsh Bardhan Mishra");
gotoxy(60,12);
printf("E-Mail: hbmcasper@gmail.com");
gotoxy(60,14);
printf("Phone Number:9799053844");
gotoxy(60,16);
printf("Exiting in 7 second...........");
delay(7000);
exit(0);
default:
{
gotoxy(60,20);
printf("\aWrong Entry!!Please re-entered correct option");
if(getch())
mainmenu();
}
}
getch();
}
void addrec()
{
system("cls");
FILE *fp ;
char filename[15];
gotoxy(60,10);
printf("Please enter the Aadhar Card Number of the Student:");
fflush(stdin); //Getting a unqiue filename for the Student Record
gets(filename);
fp = fopen (filename, "ab+" ) ;
if ( fp == NULL )
{
fp=fopen(filename,"wb+");
if(fp == NULL)
{
printf("\nSYSTEM ERROR...");
printf("\nPRESS ANY KEY TO EXIT");
getch();
return ;
}
}
system("cls");
gotoxy(60,8);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Enter Student Information \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(60,10);
printf("\xDB\xDB\xDB\xDB\xB2 1. Enter Student Name:");
gets(aa.name);
fflush(stdin);
gotoxy(60,12);
printf("\xDB\xDB\xDB\xDB\xB2 2. Date of Birth (Express in dd/mm/yy format):");
gets(aa.time);
fflush(stdin);
gotoxy(60,14);
printf("\xDB\xDB\xDB\xDB\xB2 3. Enter number of elder/younger siblings: ");
scanf("%d",&aa.sib);
fflush(stdin);
gotoxy(60,16);
printf("\xDB\xDB\xDB\xDB\xB2 4. Enter the Application Number: ");
gets(aa.app);
fflush(stdin);
gotoxy(60,18);
printf("\xDB\xDB\xDB\xDB\xB2 5. Enter Father's Name: ");
gets(aa.parent);
fflush(stdin);
gotoxy(60,20);
printf("\xDB\xDB\xDB\xDB\xB2 6. Enter the Credit Score: ");
scanf("%f",&aa.credit);
fflush(stdin);
gotoxy(60,22);
printf("\xDB\xDB\xDB\xDB\xB2 7. Enter your Parent PAN Number: ");
gets(aa.pan);
fflush(stdin);
system("cls");
///////////////////////////////////////////////////////////////////
gotoxy(60,8);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Enter Academic Details \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(60,10);
printf("\xDB\xDB\xDB\xDB\xB2 1. Enter 10th Standard Score:");
scanf("%f",&aa.tenth);
fflush(stdin);
gotoxy(60,12);
printf("\xDB\xDB\xDB\xDB\xB2 2. Enter 12th Standard Score:");
scanf("%f",&aa.twe);
fflush(stdin);
gotoxy(60,14);
printf("\xDB\xDB\xDB\xDB\xB2 3. Enter your 10th Marksheet Unique ID:");
gets(aa.tenthid);
fflush(stdin);
gotoxy(60,16);
printf("\xDB\xDB\xDB\xDB\xB2 4. Enter your 12th Marksheet Unique ID:");
gets(aa.tweid);
fflush(stdin);
gotoxy(60,18);
printf("\xDB\xDB\xDB\xDB\xB2 5. Enter Engineering Entrance Exam Score: ");
scanf("%f",&aa.jee);
fflush(stdin);
gotoxy(60,20);
printf("\xDB\xDB\xDB\xDB\xB2 6. Enter the Engineering Entrance Exam ID: ");
gets(aa.jeeid);
fflush(stdin);
gotoxy(60,22);
printf("\xDB\xDB\xDB\xDB\xB2 7. Enter your E-Mail: ");
gets(aa.mail);
fflush(stdin);
aa.ccc=creditX(aa.credit,aa.tenth,aa.twe,aa.jee);
system("cls");
//////////////////////////////////////////////////////
system("cls");
gotoxy(60,8);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Student Application \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(60,10); //Displaying the Data
printf("\xDB\xDB\xDB\xDB\xB2 1. Student Name: %s",aa.name);
gotoxy(60,12);
printf("\xDB\xDB\xDB\xDB\xB2 2. Date of Birth: %s",aa.time);
gotoxy(60,14);
printf("\xDB\xDB\xDB\xDB\xB2 3. Number of elder/younger siblings: %d",aa.sib);
gotoxy(60,16);
printf("\xDB\xDB\xDB\xDB\xB2 4. Application Number: %s",aa.app);
gotoxy(60,18);
printf("\xDB\xDB\xDB\xDB\xB2 5. Father's Name: %s",aa.parent);
gotoxy(60,20);
printf("\xDB\xDB\xDB\xDB\xB2 6. Credit Score: %f",aa.credit);
gotoxy(60,22);
printf("\xDB\xDB\xDB\xDB\xB2 7. PAN Card Number: %s",aa.pan);
gotoxy(60,24);
printf("\xDB\xDB\xDB\xDB\xB2 8. 10th Standard Score: %f",aa.tenth);
gotoxy(60,26);
printf("\xDB\xDB\xDB\xDB\xB2 9. 12th Standard Score: %f",aa.twe);
gotoxy(60,28);
printf("\xDB\xDB\xDB\xDB\xB2 10. 10th Standard Unique ID: %s",aa.tenthid);
gotoxy(60,30);
printf("\xDB\xDB\xDB\xDB\xB2 11. 12th Standard Unique ID: %s",aa.tweid);
gotoxy(60,32);
printf("\xDB\xDB\xDB\xDB\xB2 12. Engineering Entrance Exam Score: %f",aa.jee);
gotoxy(60,34);
printf("\xDB\xDB\xDB\xDB\xB2 13. Engineering Entrance Exam Unique ID: %s",aa.jeeid);
gotoxy(60,36);
printf("\xDB\xDB\xDB\xDB\xB2 14. Scholarship you are entitled to: %f", (aa.ccc*10));
gotoxy(60,38);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
///////////////////////////
fwrite ( &aa, sizeof(aa),1,fp ) ; //Adding everything to the file we opened
gotoxy(60,40);
char choice;
printf("To go back to Main Menu press 'Y' or 'y'. Press anything else to exit completely:");
scanf("%c",&choice);
if(choice=='Y' || choice=='y')
{
mainmenu();
}
else
exit(0);
}
float creditX(float a,float b,float c,float d) //Calculating the Credit
{
/*
Scholarship is calculated by getting the Credit Score, Tenth Standard Score, Twelfth Standard Score and Engineering Entrance Exam Score:
Credit Score: A Total of 2.5 is assigned by Credit Score. If the Credit Score is greater than 80 and less than or equal to 100, then a
score of 2.5 is assigned.If the Credit Score is greater than 60 and less than or equal to 80, then a score of 2.0 is assigned. If the Credit Score is
greater than 40 and lesser than or equal to 60 then a Score of 1.5 is assigned. If the Credit Score is greater than 20 and lesser than or equal to 40 then
a Score of 1.0 is assigned For all other conditions, a Score of 0.5 is assigned.

In a similar way, putting in multiple If-Else Conditions, a Criteria for 10th, 12th and Engineering Entrance Exam score is taken and a Score is returned
to suggest the amount of scholarship that a student is assigned to.

*/
float cr1=0,cr2=0,cr3=0,cr4=0;
if(a>-1)
{
if(a>80 && a<=100)
cr1=2.5;
else if(a<=80 && a>60)
cr1=2.0;
else if(a<=60 && a>40)
cr1=1.5;
else if(a<=40 && a>20)
cr1=1.0;
else
cr1=0.5;
}
if(b>-1)
{
if(b>90 && b<=100)
cr2=2.5;
else if(b<=90 && b>75)
cr2=2.0;
else if(b<=75 && b>60)
cr2=1.5;
else if(b<=60 && b>45)
cr2=1.0;
else
cr2=0.5;
}
if(c>-1)
{
if(c>90 && c<=100)
cr3=2.5;
else if(c<=90 && c>75)
cr3=2.0;
else if(c<=75 && c>60)
cr3=1.5;
else if(c<=60 && c>45)
cr3=1.0;
else
cr3=0.5;
}
if(d>-1)
{
if(d>=280 && d<=360)
cr4=2.5;
else if(d<=279 && c>=200)
cr4=2.0;
else if(d<=199 && d>=150)
cr4=1.5;
else if(d<=149 && d>=100)
cr4=1.0;
else if(d>=40 && d<=99)
cr4=0.5;
else
cr4=0.0;
}
float full_credit;
full_credit=(float)cr1+cr2+cr3+cr4;
return full_credit;
}
void search()
{
FILE *fpte ;
char filename[100];
system("cls");
printf("\n\tEnter your Aadhar Card Number:");
fflush(stdin);
gets(filename);
fpte = fopen ( filename, "rb" ) ;
if ( fpte == NULL )
{
puts ( "\nThe Application does not exist...\n" ) ;
printf("Press any key to Exit...");
getch();
return ;
}
system("cls");
while ( fread ( &ab, sizeof(ab),1,fpte) == 1 )  //Opening of the File
gotoxy(60,8);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Student Application \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(60,10);
printf("\xDB\xDB\xDB\xDB\xB2 1. Student Name: %s",ab.name);
gotoxy(60,12);
printf("\xDB\xDB\xDB\xDB\xB2 2. Date of Birth: %s",ab.time);
gotoxy(60,14);
printf("\xDB\xDB\xDB\xDB\xB2 3. Number of Elder/Younger Siblings: %d",ab.sib);
gotoxy(60,16);
printf("\xDB\xDB\xDB\xDB\xB2 4. Application Number: %s",ab.app);
gotoxy(60,18);
printf("\xDB\xDB\xDB\xDB\xB2 5. Father's Name: %s",ab.parent);
gotoxy(60,20);
printf("\xDB\xDB\xDB\xDB\xB2 6. Credit Score: %f",ab.credit);
gotoxy(60,22);
printf("\xDB\xDB\xDB\xDB\xB2 7. PAN Card Number %s",ab.pan);
gotoxy(60,24);
printf("\xDB\xDB\xDB\xDB\xB2 8. 10th Standard Score: %f",ab.tenth);
gotoxy(60,26);
printf("\xDB\xDB\xDB\xDB\xB2 9. 12th Standard Score: %f",ab.twe);
gotoxy(60,28);
printf("\xDB\xDB\xDB\xDB\xB2 10. 10th Standard Unique ID: %s",ab.tenthid);
gotoxy(60,30);
printf("\xDB\xDB\xDB\xDB\xB2 11. 12th Standard Unique ID: %s",ab.tweid);
gotoxy(60,32);
printf("\xDB\xDB\xDB\xDB\xB2 12. Engineering Entrance Exam Score: %f",ab.jee);
gotoxy(60,34);
printf("\xDB\xDB\xDB\xDB\xB2 13. Engineering Entrance Exam Unique ID: %s",ab.jeeid);
gotoxy(60,36);
printf("\xDB\xDB\xDB\xDB\xB2 14. Scholarship you are entitled to: %f", (ab.ccc*10));
gotoxy(60,38);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
///////////////////////////
char choice;
gotoxy(60,40);
printf("To go back to Main Menu press 'Y' or 'y'. Press anything else to exit completely:");
scanf("%c",&choice);
if(choice=='Y' || choice=='y')
{
mainmenu();
}
else
exit(0);
}
void delrec()
{
char ty;
FILE *fpte ;
char filename[100];
system("cls");
gotoxy(60,8);
printf("\n\tEnter your Aadhar Card Number:");
fflush(stdin);
gets(filename);
fpte = fopen ( filename, "rb" ) ;
if ( fpte == NULL )
{
gotoxy(60,10);
puts ( "The Application does not exist...\n" ) ;
gotoxy(60,12);
printf("Press any key to Exit...");
getch();
return ;
}
fclose(fpte);
remove(filename);  //Deleting the File completely
gotoxy(60,10);
printf("Your Application has been deleted.");
gotoxy(60,12);
printf("To continue back to the Main Menu press 'Y' or 'y'. To exit the application completely press anything else: ");
scanf("%c",&ty);
if(ty=='Y'||ty=='y')
{
mainmenu();
}
else
{
exit(0);
}
}
void X()
{
system("cls");
char d[25]="Password Protected";
char ch,pass[10];
int i=0,j;
gotoxy(50,4);
for(j=0;j<20;j++)
{
delay(50);
printf("*");
}
for(j=0;j<20;j++)
{
delay(50);
printf("%c",d[j]);
}
for(j=0;j<20;j++)
{
delay(50);
printf("*");
}
gotoxy(50,10);
gotoxy(50,7);
printf("Enter Password:");
while(ch!=13)
{
ch=getch();
if(ch!=13 && ch!=8){
putch('*'); //Displaying the Stars as the Password is entered
pass[i] = ch;
i++;
}
}
pass[i] = '\0';
if(strcmp(pass,password)==0)  //Comparing the Inputted Password with the initialized password
{
gotoxy(50,9);
printf("Password match");
gotoxy(50,10);
printf("Press any key to countinue.....");
getch();
mainmenu();
}
else
{
gotoxy(50,16);
printf("\aWarning!! Incorrect Password");
getch();
}
X();
}//Program End. Status Completed.
