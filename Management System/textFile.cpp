#include "list.h"
#include "textFile.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include<string>

using namespace std;


//desc: reading the test file
//pre: inout file muts have been defined
//post: the text file has been printed
void testFile::readFile(string file_name)
{
	input.clear();
	input.open(file_name, ios::app);
	string line;

	while (getline(input, line))
	{
		cout << line << endl;
	}
	output.close();
}

//desc: prints out the students information by using studnet ID
//pre: input file must have been defiend
//post: the student's information has been printed. 
void testFile::seachID(string ID_number, string file_name)
{
	input.close();
	input.close();
	bool check = false;
	string line;
	string ID;
	input.open(file_name);
	while (!input.eof())
	{
		getline(input, line);
		istringstream sstring(line);
		sstring >> ID;
		if (ID == ID_number)
		{
			cout << line << endl;
			check = true;
			break;
		}
	}
	if (check == false)
	{
		cout << "There is no student with this ID number in this class." << endl;
	}
	input.close();
}

//desc: printing the text file.
//pre: file_name must have been assigned a value.
//posT: text file has been printed.
void testFile::printingFile(string file_name)
{

	input.close();
	input.open(file_name);
	{
		string line;
		while (!input.eof())
		{
			getline(input, line);
			cout << line << endl;
		}
	}
	input.close();
}

bool testFile::inputCheck(string file_name)
{
	input.open(file_name);
	if (input.is_open())
	{
		return true;
	}
	else
	{
		return false;
	}
	input.close();
}

bool testFile::setOutputFile(string name_file)
{
	output.open(name_file);
	if (output.is_open())
	{
		return true;
	}
	else
	{
		return false;
	}
	output.close();

}
