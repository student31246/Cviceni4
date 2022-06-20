#pragma once
#include "CustomLInt.h"
#include <iostream>

//CONSTRUCTORS
CustomLInt::CustomLInt(const CustomLInt& x)
{
	this->value = new char[strlen(x.value) + 1];

	for (int i = 0; i < strlen(x.value); i++)
		this->value[i] = x.value[i];

	this->value[strlen(x.value)] = '\0';
}

CustomLInt::CustomLInt(int n)
{
	int length = log10(n) + 2;
	this->value = new char[length];

	sprintf_s(this->value, length, "%d", n);
}

//OPERATOR OVERLOAD
CustomLInt& CustomLInt::operator=(const CustomLInt& s)
{
	delete[] this->value;
	this->value = new char[strlen(s.value) + 1];

	for (int i = 0; i < strlen(s.value); i++)
		this->value[i] = s.value[i];

	this->value[strlen(s.value)] = '\0';

	return *this;
}

CustomLInt& CustomLInt::operator=(const char* s)
{
	delete[] this->value;
	this->value = new char[strlen(s) + 1];

	for (int i = 0; i < strlen(s); i++)
		this->value[i] = s[i];

	this->value[strlen(s)] = '\0';

	return *this;
}

CustomLInt& CustomLInt::operator=(int n)
{
	int length = log10(n) + 2;
	delete[] this->value;
	this->value = new char[length];

	sprintf_s(this->value, length, "%d", n);

	return *this;
}