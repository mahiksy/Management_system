#pragma once
#include <iostream>
#include<string>
#include<fstream>

using namespace std;
//desc: creating a node for student information
struct Student
{
	Student* next;
	int ID;
	string name;
	string lastName;
	string major;
	double averageExam = 0;
	double averageQuiz = 0;
	double averageproject = 0;
	double finalGarde=0;
	double exam1;
	double exam2;
	double final;
	double project1;
	double project2;
	double presentation;
	double quiz1, quiz2, quiz3, quiz4, quiz5;
	bool high = false;
	bool failed = false;
};


class studentList
{
	private:
		Student* top;
		int size;
		int A = 0, B = 0, C = 0, D = 0;
		ofstream output;
		int classSize = 0;
	public:
		studentList();

		int length();
		void addStudent(int id, string n, string lastN, string maj,
			double ex1, double ex2, double fin, double pro1, double pro2, double present, double q1,
			double q2, double q3, double q4, double q5);
		Student* findStudent(int id);
		void deleteStudent(int id);
		bool isEmpty();
		void findportions();
		void highGrade();
		void failedStudent();
		void CLassDistribution();
		void textFileClss(string name_file);
		bool checkIfOpen(string file_name);
};