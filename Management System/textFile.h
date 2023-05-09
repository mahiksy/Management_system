#include"list.h"
#include <iostream>
#include<sstream>
#include<fstream>
#include<string>

using namespace std;

class testFile
{
	private:
		ifstream input;
		ofstream output;
		fstream fStream;

public:
	void readFile(string f_name);
	void seachID(string ID_number, string file_name);
	void printingFile(string f_name);
	bool inputCheck(string file_name);
	bool setOutputFile(string file_name);
};