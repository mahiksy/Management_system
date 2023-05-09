#include<iostream>
#include<iomanip>
#include"list.h"
#include"textFile.h"
#include <string>

using namespace std;

int main()
{
	string fileName, fileName2, search_ID;
	int option, option2;
	bool s_repeat = true;
	bool file_repeat = true;
	bool prog_repeat = true;
	string addStudent;
	bool repeat = false;
	int st_ID;
	string st_name, st_lastName, st_major;
	double q_1, q_2, q_3, q_4, q_5, ex_1, ex_2, ex_final, pro_1, pro_2, pro_present;
	while (prog_repeat == true)
	{
		cout << "choose one of the options below: (type the number)" << endl;
		cout << "1.creating a class file." << endl;
		cout << "2. reading an existing class file." << endl;
		cout << "3.exit" << endl;
		do
		{
			cin >> option;
			if (option != 1 &&option != 2 && option != 3)
			{
				cout << "Unacceptale optition. Please try again." << endl;
			}
		} while (option != 1 && option != 2 && option != 3);
		if (option == 1)
		{
			studentList myclass;
			do
			{
				cout << "Please enter the class name file: (example: class101.txt)" << endl;
				cin >> fileName;

				if (myclass.checkIfOpen(fileName) == false)
				{
					cout << "You cannot create a text file with this name! Please try again." << endl;
				}

			} while (myclass.checkIfOpen(fileName) == false);
			while (s_repeat ==true)
			{
				cout << "please enter the sutdent ID:" << endl;
				cin >> st_ID;
				cout << "please enter the sutdent name:" << endl;
				cin >> st_name;
				cout << "please enter the sutdent lastName:" << endl;
				cin >> st_lastName;
				cout << "please enter the sutdent major:" << endl;
				cin >> st_major;
				cout << "please enter the sutdent exam1 grade:" << endl;
				cin >> ex_1;
				cout << "please enter the sutdent exam2 grade:" << endl;
				cin >> ex_2;
				cout << "please enter the sutdent finalExam grade:" << endl;
				cin >> ex_final;
				cout << "please enter the sutdent quiz1 grade:" << endl;
				cin >> q_1;
				cout << "please enter the sutdent quiz2 grade:" << endl;
				cin >> q_2;
				cout << "please enter the sutdent quiz3 grade:" << endl;
				cin >> q_3;
				cout << "please enter the sutdent quiz4 grade:" << endl;
				cin >> q_4;
				cout << "please enter the sutdent quiz5 grade:" << endl;
				cin >> q_5;
				cout << "please enter the sutdent project1 grade:" << endl;
				cin >> pro_1;
				cout << "please enter the sutdent project2 grade:" << endl;
				cin >> pro_2;
				cout << "please enter the sutdent presentation grade:" << endl;
				cin >> pro_present;

				myclass.addStudent(st_ID, st_name, st_lastName, st_major, ex_1, ex_2, ex_final, pro_1, pro_2, pro_present, q_1, q_2, q_3, q_4, q_5);
				do
				{
					cout << "Do you want to add another student to this class?(yes or no)" << endl;
					cin >> addStudent;
					if (addStudent != "yes" && addStudent != "Yes" && addStudent != "no" && addStudent != "No")
					{
						cout << "Error! Please try again." << endl;
					}
				} while (addStudent != "yes" && addStudent != "Yes" && addStudent != "no" && addStudent != "No");
				if (addStudent == "Yes" || addStudent == "yes")
				{	
					s_repeat = true;
				}
				if (addStudent == "No" || addStudent == "no")
				{
					myclass.findportions();
					cout << "step" << endl;
					myclass.failedStudent();
					cout << "step" << endl;
					myclass.highGrade();
					cout << "step" << endl;
					myclass.CLassDistribution();
					cout << "step" << endl;
					myclass.textFileClss(fileName);
					cout << "step" << endl;
					
					s_repeat = false;
				}
			}
		}
		if (option == 2)
		{
			testFile existingFile;
			while (file_repeat == true)
			{
				do
				{
					cout << "Choose one of the options below:" << endl;
					cout << "1.print the class information." << endl;
					cout << "2.Search a student with ID number." << endl;
					cout << "3.return to main menu." << endl;
					cin >> option2;
					if (option2 != 1 && option2 != 2 && option2 != 3)
					{
						cout << "Unacceptale optition. Please try again." << endl;
					}
				} while (option2 != 1 && option2 != 2 && option2 != 3);

				if (option2 == 1)
				{ 
					do
					{
						cout << "Please enter the class name file: (example: class101.txt)" << endl;
						cin >> fileName2;
						if (existingFile.inputCheck(fileName2) == false)
						{
							cout << "cannot open this file. Please try again!" << endl;
						}
					} while(existingFile.inputCheck(fileName2) == false);
					existingFile.printingFile(fileName2);
				}

				if (option2 == 2)
				{
					do
					{
						cout << "Please enter the class name file: (example: class101.txt)" << endl;
						cin >> fileName2;
						if (existingFile.inputCheck(fileName2) == false)
						{
							cout << "cannot open this file. Please try again!" << endl;
						}
					} while (existingFile.inputCheck(fileName2) == false);
					cout << "Please enter the 5 digit student ID:" << endl;
					cin >> search_ID;
					existingFile.seachID(search_ID, fileName2);
				}
				if (option2 == 3)
				{
					file_repeat = false;
				}
			}
		
		}
		if (option == 3)
		{
			prog_repeat = false;
		}
	}
	return 0;
}
	

