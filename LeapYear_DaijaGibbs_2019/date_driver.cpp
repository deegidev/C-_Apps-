//*********************************************************************************************
//*********************************************************************************************
// D A T E D R I V E R . C P P
//EXAMPLE OF PROGRAM HEADER
/********************************************************************************************
Name:			Brandaija Gibbs
Z#:				23062242
Course:			Date Structures and Algorithm Analysis (COP3530)
Professor:		Dr. Lofton Bullard
Due Date:		2/7/19 
Due Time:		11:59pm
Total Points:	25
Assignment 3:	Date program
Description:	Implement the Date class and test it's functionality to be able to distinguish between valid
				and not valid days, years and months. And print that information back to the user. 
*********************************************************************************************/
#include "date.h"
int main()
{
	//month, day, year
	Date myDate;
	Date yourDate(12, 31, 1957);
	Date test1Date(15, 1, 1962); //should generate error message that bad month
	Date test2Date(2, 29, 1956); //ok, should say leap year
	Date test3Date(2, 30, 1956); //should generate error message that bad day
	Date test4Date(12,31,0000); //should generate error message that bad year
	Date test5Date(80,40,0000); //should generate error message that bad month, day and year
	yourDate.display();

	//GET CURRENT MONTH, DAY AND YEAR , check to see if vaild 
	cout<<yourDate.getMonth()<<endl;
	cout<<yourDate.getDay()<<endl;
	cout<<yourDate.getYear()<<endl;

	//CHANGE MONTH, DAY AND YEAR
	myDate.setMonth(11);
	myDate.setDay(12);
	myDate.setYear(2015);
	cout<<"myDate: "<<myDate<<" test2Date: "<<test2Date<<" yourDate: "<<yourDate<<endl;
	return 0;
}