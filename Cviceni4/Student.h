#pragma once
#include <iostream>
#include <list>
#include "Subject.h"
using namespace std;

class Student
{
private:
	list<Subject> subjects;
	char* name = new char[250];
	void GetMarks();
	void PassedExams();
	const char* AverageMark();

public:
	Student() {};
	Student(const char* nm) { strcpy(this->name, nm); }
	Student(const Student& stud) { this->subjects = stud.subjects; strcpy(this->name, stud.name); };

	Student& operator=(const Student& stud);

	char* GetName() { return name; }
	void SetName(const char* nm) { strcpy(this->name, nm); }
	void Enroll(Subject sub);
	void Score(SubjectType subject, bool credit);
	void Score(SubjectType subject, Mark mark);
	void PrintStudentInfo();

	~Student() { delete[] name; }
};