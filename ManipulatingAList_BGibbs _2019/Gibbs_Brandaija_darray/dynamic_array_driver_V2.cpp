//****DYNAMIC_ARRAY_DRIVER PROGRAM HEADER***********************************************************************
//Brandaija Gibbs	        
//Total Points: 25
//Due Date:		5/22/2019
//Course:		C0P3530
//Assignment:	Assignment 1 / Module 3
//Professor:	Dr. Lofton Bullard
//
//Description: In this program we: allocate dynamic memort, implement a default constructor, insert and remove an item from
//				dynamic array of strings, use string class member functions, implement a copy constructor, overload the assignment
//				and insertion operator, search an array, change the size of a dynamic array,  write function and program headers,
//				and implement a destructor.
//*************************************************************************************************


#include <iostream>
#include <fstream>
#include <string>
using namespace std;


class tlist

{

public:

	tlist();//default constructor
	~tlist();//destructor
	tlist(const tlist &);//copy constructor
	bool IsEmpty(); //checks for empty array
	bool IsFull(); //checks for full array
	int Search(const string &); //searches array for string
	void Insert(const string &); //adds a new string to array
	void Remove(const string &); //removes a string from array
	void Triple_size(); //triples the size of array
	tlist & operator=(const tlist &);//assignment operator overloaded
	friend ostream & operator<<(ostream &, const tlist &);//insertion operator overloaded
private:
	string *DB; //dynamic array
	int count; //number of filled elements
	int capacity; //number of total cells in the array
};

//***************************Default Constructor**********************
// Function Name: tlist
// Pre-Condition: The count, capacity and the dynamic array DB have not been initialized.
// Post-Condition:The count, capacity and the dynamic array DB have been initialized.
// Description:The default constructor initializes that state of the class. 
//				Creates a dynamic array and fills it. 
//				Count is the amount of elements in the file. Capacity the amount of cells
//				added to the array.
//********************************************************************
tlist::tlist()
{
	string s;
	ifstream input;
	input.open("ourData-1.txt");

	if (input.fail())
	{
		cout << "problem with input data file\n";
		exit(1);
	}

	cout << "\n\nDefault Constructor Invoked\n"
		<< "***************************\n\n";
	count = 0;
	capacity = 1;
	DB = new string[capacity];

	IsEmpty();

	while (!input.eof())
	{
		input >> s;
		Insert(s);
	}
	input.close();
	
}

//***************************Destructor**********************
// Function Name:	~tlist
// Pre-Condition:	Takes nothing and returns nothing.
// Post-Condition:	Releases the memory of the dynamic arrarys.
// Description:		Releases the memory of the dynamic arrays when the program
//					ends to avoid a memory leak. 
//********************************************************************
tlist::~tlist()
{
	cout << "\n\nDestructor Invoked\n"
		<< "*******************\n\n";
	delete[] DB;
}

//***************************Copy Constructor**********************
// Function Name:	tlist
// Pre-Condition:	A tlist object was passed by reference.
// Post-Condition:	A deep copy of a tlist object has been done.
// Description:		Creates a hard copy of a tlist class when:  an object 
//					of the tlist class is returned or passed by value or
//					when a tlist object is initialized based on another tlist object.
//********************************************************************
tlist::tlist(const tlist & org)
{
	cout << "\n\nCopy Constructor Invoked\n"
		<< "*************************\n\n";
	count = org.count;
	capacity = org.capacity;
	DB = new string[capacity];
	for (int i = 0; i < count; i++)
	{
		DB[i] = org.DB[i];
	}
}

//***************************Is Empty**********************
// Function Name:	IsEmpty 
// Pre-Condition:	Has an arrary to test.Takes no arguments. Returns true or false.
// Post-Condition:	Returns true if  the array is empty and false if there is something
//					in the array.
// Description:		Checks for an empty array.
bool tlist::IsEmpty()
{
	cout << "\n\nIsEmpty Invoked\n"
		<< "****************\n\n";
	return count == 0;
}

//***************************Is Full**********************
// Function Name:	IsFull
// Pre-Condition:	Has an arrary to test. Takes no arguments. Returns true or false.
// Post-Condition:	Returns true if  the array is full and false if there is
//					still room in the array.
// Description:		Checks for an full array.
bool tlist::IsFull()
{
	cout << "\n\nIsFull Invoked\n"
		<< "***************\n\n";
	return count == capacity;
}

//***************************Search**********************
// Function Name:	Search
// Pre-Condition:	Has an arrary to test. 
//					Takes a constant reference to a string. Returns an integer.
// Post-Condition:	Returns the location of a string if found. Returns -1 if not 
//					found in the array.
// Description:		Iterates through an array to find a certain string in an array. 
int tlist::Search(const string & key)
{
	for (int i = 0; i < count; i++)
	{
		if (DB[i] == key)
		{
			return i;
		}
	}
	return -1;
}

//***************************Insert**********************
// Function Name:	Insert
// Pre-Condition:	Takes a constant reference to a string. Returns an nothing;
// Post-Condition:	Triples the size of the array if it is full. Adds a string to the next
//					available element in the array. 
// Description:		Adds a string to the array. 
void tlist::Insert(const string & key)
{

	if (IsFull())
	{
		Triple_size();
	}
	DB[count++] = key;
}

//***************************Remove**********************
// Function Name:	Remove
// Pre-Condition:	Takes a constant reference to a string. Returns an nothing;
// Post-Condition:	Removes an item from an array.  
// Description:		Searches for a string in an array. Removes the string if it is
//					there. Does nothing to the array if it is empty or not found.
void tlist::Remove(const string & key)
{
	int i = Search(key);

	if (i == -1)
	{
		if (IsEmpty())
		{
			cout << "DB is empty\n\n";
		}
		else
		{
			cout << key << " not in DB\n\n";
		}
	}
	else
	{
		for (int j = i; j < count - 1; j++)
		{
			DB[j] = DB[j + 1];
		}
		cout << key << " found and deleted\n\n";
		count--;
	}

}

//***************************Triple Size**********************
// Function Name:	Triple_Size
// Pre-Condition:	Takes no arguments and returns nothing.
// Post-Condition:	Triples the size of the array if it is full. Adds a string to the next
//					available element in the array. 
// Description:		Adds a string to the array. 
void tlist::Triple_size()
{

	cout << "\n\nTriple_size Invoked\n"
		<< "***************************\n\n";
	capacity *= 3;
	string *temp = new string[capacity];


	for (int i = 0; i < count; i++)
	{
		temp[i] = DB[i];
	}

	delete[] DB;
	DB = temp;
}

//***************************Assignemnt Operator**********************
// Function Name:	operator=
// Pre-Condition:	Takes a constant reference to an object arguments and returns
//					a reference to an object.
//					2 objects have been already been initialized. 
// Post-Condition:	Copies the contents of the object on the right of the operator to the 
//					object on the left of the operator.
// Description:		Copies values from one object to an object that has been initialized
//					in another line. 
tlist & tlist::operator=(const tlist & org)
{
	cout << "\n\noverloaded assignment operator (=) Invoked\n"
		<< "***************************\n\n";
	if (this != &org)
	{
		delete[](*this).DB;
		(*this).count = org.count;
		(*this).capacity = org.count;
		(*this).DB = new string[(*this).capacity];
		for (int i = 0; i < (*this).count; i++)
		{
			(*this).DB[i] = org.DB[i];
		}
	}
	return *this;
}

//*************************** Insertion Operator **********************
// Function Name:	Triple_Size
// Pre-Condition:	The insertion operator has been overloaded as a friend of the tlist class.
//					Takes a reference to a stream and a constant reference to a tlist object.
//					Returns a reference to an ostream object. 
// Post-Condition:	Prints the contents of an array within a tlist object.
// Description:		Puts the contents of an array within a tlist object into an output stream.
ostream & operator<<(ostream & cout, const tlist & org)
{
	for (int i = 0; i < org.count; i++)
	{
		cout << org.DB[i] << endl;
	}
	return cout;
}

int main()
{
	tlist ListOne; //(1) Default Constructor
	cout << ListOne; //(2) Insertion Operator
	tlist ListTwo = ListOne; //(3) Copy Constructor
	cout << ListTwo; //(4) Checking Copy

	ListOne.Remove("google"); //(5) Remove
	cout << ListOne; //(6) Cheking Remove 
	ListOne.Remove("amazon");  //(7) Remove
	cout << ListOne;  //(8) Checking Remove
	ListOne.Remove("firefox"); //(9) Remove
	cout << ListOne; //(10) Cheking Remove 

	ListOne.IsEmpty(); //(11) IsEmpty 
	ListOne.Remove("xyz"); //(12) Remove
	cout << ListOne;  //(13) Check Remove

	tlist ListThree; //(14) Default Constructor
	ListThree = ListTwo; //(15) Assignment Operator 
	cout << ListThree; //(16) Check Assignment Operator 
	return 0;
}







