#pragma once
#include <iostream>
using namespace std;

class Beast
{
private:
	int stomache;
	int age;
	char* name = new char[250];
	int Live() { return this->stomache > 0; }
	void GetOlder() { this->age++; }

public:
	Beast() { stomache = 1; age = 0; }
	Beast(const char* nm) :Beast() { strcpy(this->name, nm); }
	Beast(const Beast& bst) { this->stomache = bst.stomache; this->age = bst.age; strcpy(this->name, bst.name); }

	Beast& operator=(const Beast& bst);

	char* GetName() { return name; }
	void SetName(const char* nm) { strcpy(this->name, nm); }
	int Eat(int food);
	int Poop(int volume);
	void Print() { cout << "Age: " << this->age << " " << "Stomache: " << this->stomache << " Name: " << this->GetName() << endl; }

	~Beast() { delete[] name; }
};

