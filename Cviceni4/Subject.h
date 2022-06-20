#pragma once

enum SubjectType
{
	Math, Literature, Physics, Chemistry, Movie, LazyDay, Drive, English, Spanish, Swimming, History, Czech,
	Biology, Ukranian, Russian, Romanian, Management, Accounting, Science, Geography, Economics, Art

};

enum Mark
{
	A, B, C, D, E, F
};

class Subject
{
private:
	SubjectType subType;
	int attempts;
	bool credit;
	Mark exam;

public:

	Subject() { attempts = 0; credit = false; exam = Mark::F; }
	Subject(SubjectType type) :Subject() { subType = type; }

	SubjectType GetType() { return this->subType; }
	int GetAttempts() { return this->attempts; }

	bool GetCredit() { return this->credit; }
	void SetCredit(bool value) { this->credit = value; }

	Mark GetExam() { return this->exam; }
	void SetExam(Mark mark) { this->attempts++; this->exam = mark; }
};
