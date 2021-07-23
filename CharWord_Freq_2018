/*
Name:			Brandaija Gibbs
Z#:				23062242
Course:			Foundations of Computer Science (COP3014)
Total Points:	10
Assignment 7:	CharWord_Freq

Description:	This program will find and ouput the number of words in a file, as well as find and output the
				amount of times a letter is found in a file. 

*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	string line;
	
	ifstream in("mytext.dat");
	if (!in.eof())
	{
		
		while (getline(in, line)) 
		{
			int count[26] = { 0 }, i, numWords = 0;
			for (i = 0; i < line.size(); i++)
			{
				if (((line[i] >= 'a' && line[i] <= 'z') || (line[i] >= 'A' && line[i] <= 'Z')) && (line[i + 1] == '.' || line[i + 1] == ',' || line[i + 1] == ' ')) numWords++;
				if (line[i] >= 'a' && line[i] <= 'z') count[line[i] - 'a']++;
				if (line[i] >= 'A' && line[i] <= 'Z') count[line[i] - 'A']++;
			}
			
			char letter = line[line.size() - 1]; //counting words
			if (letter != '.' && letter != 'z' && letter != ' ') numWords++;
			cout << endl << numWords << " words" << endl;
			for (i = 0; i < 26; i++)
			{
				if (count[i] > 0) cout << count[i] << " " << (char)('a' + i) << endl;
			}
		}
		
		in.close();
	}
	else cout << "line file did not open correctly.";
	

	return 0;
}
