#include "Student.h"
#include <algorithm>
#include "SubjectExtensions.h"
using namespace std;

Student& Student::operator=(const Student& stud)
{
	this->subjects = stud.subjects;
	delete[] this->name;
	this->name = new char[250];
	strcpy(this->name, stud.name);
	return *this;
}

void Student::Enroll(Subject sub)
{
	if (this->subjects.size() < 20)
	{
		for (Subject elem : this->subjects)
			if (elem.GetType() == sub.GetType())
			{
				cout << "you have already assigned to this subject" << endl;
				return;
			}
		this->subjects.push_back(sub);
	}
	else
		cout << "Over the subject limit" << endl;
}

void Student::Score(SubjectType subjectT, bool credit)
{
	bool found = false;
	for (Subject& elem : this->subjects)
	{
		if (elem.GetType() == subjectT)
		{
			elem.SetCredit(credit);
			found = true;
			break;
		}
	}
	if (!found)
		cout << "Such subject not assigned" << endl;
}

void Student::Score(SubjectType subjectT, Mark mark)
{
	bool found = false;
	bool allowed = true;
	for (Subject& elem : this->subjects)
	{
		if (elem.GetType() == subjectT)
		{
			found = true;

			if (elem.GetCredit() && elem.GetAttempts() < 3)
				elem.SetExam(mark);
			else
				allowed = false;
			break;
		}
	}
	if (!found)
		cout << "Such subject not assigned" << endl;
	if (!allowed)
		cout << "student is not allowed to pass the exam" << endl;
}

void Student::GetMarks()
{
	for (Subject sub : this->subjects)
		cout << "Subject name: " << SubjectExtensions::subjectTypeText[sub.GetType()] << " - " << SubjectExtensions::subjectMarkText[sub.GetExam()] << endl;
}

void Student::PassedExams()
{
	int passedCount = 0;
	for (Subject sub : this->subjects)
		if (sub.GetExam() >= 0 && sub.GetExam() < 3)
		{
			cout << "Subject name: " << SubjectExtensions::subjectTypeText[sub.GetType()] << " - " << SubjectExtensions::subjectMarkText[sub.GetExam()] << endl;
			passedCount++;
		}
	cout << "Total successfully pased subjects: " << passedCount << endl;
}

const char* Student::AverageMark()
{
	double total = 0;
	for (Subject sub : this->subjects)
		total += sub.GetExam();
	return SubjectExtensions::subjectMarkText[(int)round(total / subjects.size())];
}

void Student::PrintStudentInfo()
{
	char decision;
	cout << "Student name is: " << this->GetName() << "\n" << "Enter 1 - for getting marks, 2 - to get passed exams, 3 - to get average marks" << endl;
	cin >> decision;
	switch (decision)
	{
	case '1':
		this->GetMarks();
		break;
	case'2':
		this->PassedExams();
		break;
	case'3':
		cout << "Average mark is: " << this->AverageMark() << endl;
		break;
	default:
		break;
	}
}