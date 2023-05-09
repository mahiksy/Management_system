#include "list.h"
#include "textFile.h"
#include <iostream >
#include <string>
#include <iomanip>

using namespace std;
//desc: creating a consturctor
//pre: top and size must have been defined;
//pos: top has been assigned to nullprt and size has been assigned to 0
studentList::studentList()
{
	top = nullptr;
	size = 0;
}

//desc: finding the number of students
//pre: size must have been assigned a value
//post: the value of size has been returned
int studentList::length()
{
	return size;
}

//desc: chekcing if the list is empty or not
//pre: top must have been defined
//post: the result has been returned
bool studentList::isEmpty()
{
	if (top == nullptr)
	{
		return true;
	}
	else
		return false;
}

bool studentList::checkIfOpen(string name_file)
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
}
//desc: adding a new student
//pre: all the inputs must have been assigned a value
//post: the new student has been added to the list successfuly
void studentList::addStudent(int id, string n, string lastN, string maj,
	double ex1, double ex2, double fin, double pro1, double pro2, double present, double q1,
	double q2, double q3, double q4, double q5)
{
	Student* current = new Student();
	current->ID = id;
	current->name = n;
	current->lastName = lastN;
	current->major = maj;
	current->exam1 = ex1;
	current->exam2 = ex2;
	current->final = fin;
	current->project1 = pro1;
	current->project2 = pro2;
	current->presentation = present;
	current->quiz1 = q1;
	current->quiz2 = q2;
	current->quiz3 = q3;
	current->quiz4 = q4;
	current->quiz5 = q5;
	size++;
	if (isEmpty())
	{
		current->next = nullptr;
		top = current;
	}
	if (!isEmpty())
	{
		current->next = top;
		top = current;
	}
	classSize++;
}


Student* studentList::findStudent(int id)
{
	Student* current = top;
	if (isEmpty())
	{
		return nullptr;
	}
	if (!isEmpty())
	{
		while (current != nullptr)
		{
			if (current->ID == id)
			{
				return current;
			}
			current = current->next;
		}
	}
	return nullptr;
}

//desc: delteing a student form the list
//pre: id must have beend assigned a value
//post: the studetn with the id has been removed from the list
void studentList::deleteStudent(int id)
{
	Student* temp = findStudent(id);
	if (isEmpty())
	{
		cout << "This list is empty!" << endl;
	}
	if (temp == top)
	{
		top = top->next;
		delete temp;
	}
	if (!isEmpty())
	{
		Student* before = top;
		while (before->next != temp)
		{
			before = before->next;
		}
		before->next = temp->next;
		delete temp;
	}
}

//desc: finding protians ofthe final grade for each student
//pre: students grade mus thave been assigned a value
//post: each portion has been assingned a value after calculations.
void studentList::findportions()
{
	Student* current = top;
	int size = classSize;
	while (size!=0)
	{
		if (isEmpty())
		{
			cout << "It is an empty list!" << endl;
		}
		if (!isEmpty())
		{
			current->averageExam = ((current->exam1 + current->exam2 + current->final) / 3) * 0.4;
			current->averageproject = ((current->project1 + current->project2 + current->presentation) / 3) * 0.35;
			current->averageQuiz = ((current->quiz1 + current->quiz2 + current->quiz3 + current->quiz4 + current->quiz5) / 5) * 0.25;
			current->finalGarde = current->averageExam + current->averageproject + current->averageQuiz;
		}
		current = current->next;
		size--;
	}
}

//desc: listing all the studnets that have GPA higher than 3.0
//pre: the list must have been defined
//post: the list with all the students name with GPA higher than 3.0 has been pirnted out.
void studentList::highGrade()
{
	int size = classSize;
	Student* current = top;
	while (size !=0)
	{
		if (current->finalGarde >= 90.00)
		{
			current->high = true;
		}
		current = current->next;
		size--;
	} 

}
void studentList::failedStudent()
{
	int size = classSize;
	Student* current = top;
	while (size != 0)
	{
		if (current->finalGarde < 75.00 )
		{
			current->failed = true;
		}
		current = current->next;
		size--;
	}
}

void studentList::CLassDistribution()
{
	int size = classSize;
	Student* current = top;
	if (isEmpty())
	{
		cout << "This list is empty!" << endl;
	}
	while (size != 0)
	{
		if (current->finalGarde > 90.00)
		{
			A = A + 1;
		}
		if (current->finalGarde < 90.00 && current->finalGarde >= 80.00)
		{
			B=B+1;
		}
		if (current->finalGarde < 80.00 && current->finalGarde >= 70.00)
		{
			C = C + 1;
		}
		if (current->finalGarde < 70.00)
		{
			D = D + 1;
		}
		current = current->next;
		size--;
	}
}

void studentList::textFileClss(string file_name)
{
	int size = classSize;
	bool repeat = true;
	output.clear();
	output.open(file_name);
	Student* current = top;
	output << "ID" << setw(10) << "name" << setw(15) << "LastName" << setw(15) << "Exams" << setw(10) << "Quizzes" << setw(11) << "Projects" << setw(10) << "Total" << endl;
	output << "___________________________________________________________________________" << endl;
	output << endl;
	while (size !=0)
	{
		output << current->ID << setw(10) << current->name << setw(12) << current->lastName << setw(13) << current->averageExam << setw(10) <<
			current->averageQuiz << setw(11) << current->averageproject << setw(10) << current->finalGarde << endl;
		current = current->next;
		size--;
	}
	size = classSize;
	current = top;
	output << "___________________________________________________________________________" << endl;
	output << "___________________________________________________________________________" << endl;
	output << endl;
	output << "TopGrades:" << endl;
	output << "ID" << setw(10) << "name" << setw(15) << "LastName" << endl;
	output << "___________________________________________________________________________" << endl;
	while (size != 0)
	{
		if (current->high == true)
		{
			output << current->ID << setw(10) << current->name << setw(12) << current->lastName << endl;
		}
		size--;
		current= current->next;
	}
	size = classSize;
	current = top;
	output << "___________________________________________________________________________" << endl;
	output << "___________________________________________________________________________" << endl;
	output << endl;
	output << "Failed Students:" << endl;
	output << "ID" << setw(10) << "name" << setw(15) << "LastName" << endl;
	while (size != 0)
	{
		if (current->failed == true)
		{
			output << current->ID << setw(10) << current->name << setw(12) << current->lastName << endl;
		}
		size--;
		current = current->next;
	}
	output << "___________________________________________________________________________" << endl;
	output << "___________________________________________________________________________" << endl;
	output << endl;
	output << "Destribution of the class:" << endl;
	output << "___________________________________________________________________________" << endl;
	output << "A grades: " << A << setw(15)<< "B grades: " << B << setw(15) << "C grades: " << C << setw(15) << "D Grades: " << D << endl;
	output.close();
}

