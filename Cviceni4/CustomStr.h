#pragma once
#include <string.h>
class CustomStr
{
private:

	char* value;

public:
	//CONSTRUCTORS
	CustomStr(const char x) {this->value = new char[strlen(&x)+1]; this->value[0] = x; this->value[1] = '\0'; }
	CustomStr(char* x) {this->value = new char[strlen(x) + 1]; strcpy_s(this->value, strlen(x) + 1, x); }
	CustomStr(const CustomStr& x);

	//GETTERS AND SETTERS (FOR TEST ONLY)
	char* GetValue() { return this->value; }
	void SetValue(const char p[]) { delete[] this->value; this->value = new char[strlen(p) + 1]; strcpy_s(this->value,strlen(p) + 1, p); }

	//OPERATORS OVERLOAD
	CustomStr& operator = (const CustomStr& s);
	CustomStr& operator = (const char* s);


	~CustomStr() { delete[] this->value; }
};

