#pragma once
#include <string.h>
class CustomLInt
{
private:
	char* value;
public:
	//CONSTRUCTORS
	CustomLInt(const char x) { this->value = new char[strlen(&x) + 1]; this->value[0] = x; this->value[1] = '\0'; }
	CustomLInt(char* x) { this->value = new char[strlen(x) + 1]; strcpy_s(this->value, strlen(x) + 1, x); }
	CustomLInt(const CustomLInt& x);
	CustomLInt(int n);

	//GETTERS AND SETTERS (FOR TEST ONLY)
	char* GetValue() { return this->value; }
	void SetValue(const char p[]) { delete[] this->value; this->value = new char[strlen(p) + 1]; strcpy_s(this->value, strlen(p) + 1, p); }

	//OPERATORS OVERLOAD
	CustomLInt& operator = (const CustomLInt& s);
	CustomLInt& operator = (const char* s);
	CustomLInt& operator = (int n);


	~CustomLInt() { delete[] this->value; }
};

