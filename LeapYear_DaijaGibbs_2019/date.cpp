//*********************************************************************************************
//*********************************************************************************************
// D A T E . C P P
//This stub (for now) should be implemented in date.cpp
//*************************************************************************************
//Name:				Date (Defualt Constructor)
//Precondition:		The state of the object (private data) has not been initialized.
//Postcondition:	The state has been initialized to today's date.
//Description:		This is the default constructor which will be called automatically when
//					an object is declared. It will initialize the state of the class
//*************************************************************************************
#include "date.h"
Date::Date()
{
	cout << "Default constructor has been called." << endl;
	myMonth = 1;
	myDay = 1;
	myYear = 1;
	display();

	
}

//*************************************************************************************
//Name:				Date (Explicit Value)
//Precondition:		The Date object takes 3 unsigned integers. 
//Postcondition:	The state has been initialized to with user input, and qualified for correct input.
//Description:		Explicit-value constructor to set date equal to today's
//					date. Use 2-digits for month (m) and day (d), and 4-digits for year (y); this function should //print a message if a leap year.
//					Checks if the month is valid then uses function to check if the day is valid, and lastly checks if the year is valid. 
//*************************************************************************************
Date::Date(unsigned m, unsigned d, unsigned y)
{
	myMonth = m;
	myDay = d;
	myYear = y;

	cout << endl<< "Explicit value constructor called" << endl;

	//If Month, Day and Year are correct, print all
	if ((CheckMonth(m, d, y)) && (CheckDay(m, d, y)) && (CheckYear(m, d, y)) == 1)
	{
		display();
	}

	//Check if Day is correct, and print if it is leap year
	if ((CheckDay(m, d, y) == 1) && ((d > 0) && (d <= 29)))
	{
		cout << "This is a leap year" << endl;
	}

	//Check if Month, Day and Year are correct independently
	if (CheckMonth(m, d, y) == 0)
	{
		cout << setw(2) << setfill('0') << "Month = " << m << " is incorrect" << endl;
	}
	if (CheckDay(m, d, y) == 0)
	{
		cout << setw(2) << setfill('0') << "Day = " << d << " is incorrect" << endl;
	}
	if (CheckYear(m, d, y) == 0)
	{
		cout << "Year = " << setw(4) << setfill('0') << y << " is incorrect" << endl;
		cout << endl;
	}
		
}




//*************************************************************************************
//Name:				Display
//Precondition:		Display is a member function of the Date class that takes no arguments.
//Postcondition:	Sets output conditions to show 2 places and fill with 0 for myMonth and myDay.
//					Sets ouptput conditions to show 4 places and fill with 0 for myYear.
//Description:		Outputs myMonth, myDay and myYear of current object. 
//*************************************************************************************
void Date::display()
{
	
	
	cout << setw(2) << setfill('0') << myMonth << "/";
	cout << setw(2) << setfill('0') << myDay << "/";
	cout << setw(4) << setfill('0') << myYear << endl;

	
}
//*************************************************************************************
//Name:					getMonth
//Precondition:			getMonth is a member function of the Date class that takes no arguments.
//Postcondition:		getMonth returns myMonth of current object to function that called it. 
//Description:			Accessor to output the month of current object/ Date object that called it.
//*************************************************************************************
int Date::getMonth() 
{	
	cout << endl;
	return myMonth; 
	cout << endl;
}

//*************************************************************************************
//Name:					getDay
//Precondition:			getDay is a member function of the Date class that takes no arguments.
//Postcondition:		getDay returns myMonth of current object to function that called it. 
//Description:			Accessor to output the day of current object. 
//*************************************************************************************
int Date::getDay()
{
	return myDay;
	cout << endl;
}

//*************************************************************************************
//Name:					getYear
//Precondition:			getYear is a member function of the Date class that takes no arguments.
//Postcondition:		getYear returns myYear to of current object to function that called it. 
//Description:			Accessor to output the year of current object/ Date object that called it.
//*************************************************************************************
int Date::getYear()
{
	     
	return myYear;
	cout << endl;

}
//*************************************************************************************
//Name:				setMonth
//Precondition:		setMonth is a member function of date that takes and unsigned int called 'm'.
//Postcondition:	myMonth of Date object that called it set to value of unsigned 'm'passed. 
//Description:		Changes myMonth value of Date object that called it. 
//
//*************************************************************************************
void Date::setMonth(unsigned m)
{
	//only way to change value
	myMonth = m; 

}

//*************************************************************************************
//Name:				setDay
//Precondition:		setDay is a member function of date that takes and unsigned int called 'd'.
//Postcondition:	myDay of Date object that called it set to value of unsigned 'd' passed. 
//Description:		Changes myDay value of Date object that called it. 
//*************************************************************************************
void Date::setDay(unsigned d)
{
	myDay = d;
}

//*************************************************************************************
//Name:				setYear
//Precondition:		setYear is a member function of date that takes and unsigned int called 'y'.
//Postcondition:	myYear of Date object that called it set to value of unsigned 'y'passed. 
//Description:		Changes myYear value of Date object that called it. 
//
//*************************************************************************************
void Date::setYear(unsigned y)
{
	myYear = y;
}

//*************************************************************************************
//Name:					insertion overload <<
//Precondition:			Overloading operator funtion that is a friend of the Date class.
//						Takes and outputstream and a Date object as arguments.
//Postcondition:		Prints each field of the Date object and returns and outputstream to the 
//						main/function that called it. 
//Description:			Overloading the insertion << operator as a friend function.
//						Prints every variable of the calling Date object. 
//
//*************************************************************************************
ostream & operator<<(ostream &out, const Date &dateObj)
{
	

	out <<setw(2) << setfill('0') << dateObj.myMonth << "/";
	out << setw(2) << setfill('0') << dateObj.myDay << "/";
	out << setw(4) << setfill('0') << dateObj.myYear << '\t';

	return out;
}

//// ************ My Functions ***************** 
//*************************************************************************************
//Name:				CheckMonth
//Precondition:		CheckMonth takes 3 unsigned integers. 
//Postcondition:	Returns True if month is between 0-12. Returns False if month less than 0 or more than 12.
//Description:		Checks for valid month. 
//*************************************************************************************
bool Date::CheckMonth(unsigned m, unsigned d, unsigned y)
{
	//CHECKS FOR MONTH VALIDITY
	if (m < 0 || m > 12) //if the month is less than 0 or greater than 12
	{
		return 0;
	}
	return 1;
}

//*************************************************************************************
//Name:				CheckDay
//Precondition:		Takes the 3 same unsigned integers passed to CheackYear from the explicit value constructor.
//Postcondition:	If Days are between 0-31.
//					Returns true if days are valid for February in leap year.
//					Returns true if days are valid for February in non leap year.
//					Returns false if days are not between 0-31.
//Description:		Checks for correct Day input in leap and non-leap years.
//				
//*************************************************************************************
bool Date::CheckDay(unsigned int m, unsigned int d, unsigned int y)
{
	

	if (d > 0 && d <= 31) //if day is between 0 and 31 
	{

		//IF MONTH == 02, check for proper leap year days
		if (m == 02)
		{
			int leapyear = LeapYear(y); 	//CHECKS FOR LEAP YEAR

			if (leapyear == 1) //if it is FEB of a leapyear
			{

				if ( d > 0 && d <= 29) //,then the day is valid
				{
					//cout << "This is a leap year." << endl;
					return 1;
				}
				else return 0;
			}

			//if it is FEB of a non-leapyear
			if (leapyear == 0)
			{
				if (d > 0 && d <= 28) //, then the day is valid
				{
					return 1;
				}

			}
		}
	}
	else if  (d < 0 || d > 31) 
	{
		return 0;
	}

}

//*************************************************************************************
//Name:				CheckYear
//Precondition:		CheckYear takes 3 unsigned integers. 
//Postcondition:	If Year is less than or equal to 0, returns false.
//					If Year is > 0 returns true.
//Description:		Checks if the year is a valid year input. 
//*************************************************************************************

bool Date::CheckYear(unsigned int m, unsigned int d, unsigned int y)
{

	if (y <= 0) //CHECKS IF YEAR IS > 0
	{
		return 0;
	}
	return 1;

}


//*************************************************************************************
//Name:				LeapYear
//Precondition:		Takes the unsigned int y, passed to CheckYear from the explicit value constructor.
//Postcondition:	Returns 1 if unsigned int y is divisible by 4 (and is therefore a leapyear).
//					Returns 0 if unsigned int y is not divisible by 4 (and therefore not a leap year).
//Description:		Checks for leap and non-leap years.
//				
//*************************************************************************************
bool Date::LeapYear(unsigned int y)
{

	//CHECKING FOR LEAP YEAR
	if (y % 4 == 0) //if the year is dvisible by 4 it is a leap year
	{

		return 1;
	}
	//else //if year is not divisible by 4
	return 0;


}