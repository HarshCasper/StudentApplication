# StudentApplication

[![Codacy Badge](https://api.codacy.com/project/badge/Grade/89cdbb63958a4c86b52dbb09280a76c5)](https://www.codacy.com/manual/HarshCasper/StudentApplication?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=HarshCasper/StudentApplication&amp;utm_campaign=Badge_Grade)


This is a C implementation of a Student Educational Loan where the user needs to enter his personal and academic details and all his data are stored in an External File which can be viewed and deleted later.

## User-Defined Functions used: 

creditX(float,float,float,float): Used for calculating the Scholarship Score for the Student\
mainmenu(): Used for displaying the Main Menu\
addrec(): Used for adding a new application\
delrec(): Used for deleting a Previous Record\
search(): Used for Searching and Displaying a Record\
delay(): Used for delaying the output\
gotoxy(): Used for jumping to a co-ordinate

## Scholarship Calculation

Scholarship is calculated by getting the Credit Score, Tenth Standard Score, Twelfth Standard Score and Engineering Entrance Exam Score.
Credit Score: A Total of 2.5 is assigned by Credit Score. If the Credit Score is greater than 80 and less than or equal to 100, then a
score of 2.5 is assigned.If the Credit Score is greater than 60 and less than or equal to 80, then a score of 2.0 is assigned. If the Credit Score is greater than 40 and lesser than or equal to 60 then a Score of 1.5 is assigned. If the Credit Score is greater than 20 and lesser than or equal to 40 then a Score of 1.0 is assigned For all other conditions, a Score of 0.5 is assigned. In a similar way, putting in multiple If-Else Conditions, a Criteria for 10th, 12th and Engineering Entrance Exam score is taken and a Score is returned
to suggest the amount of scholarship that a student is assigned to.

## Compiled on: 

Written and Compiled on Borland C++ Version: 5.02 for Windows.

## Developed by: 

Harsh Bardan Mishra\
hbmcasper@gmail.com
