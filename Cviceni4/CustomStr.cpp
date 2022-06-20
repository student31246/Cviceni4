#pragma once
#include "CustomStr.h"

//CONSTRUCTORS
CustomStr::CustomStr(const CustomStr& x)
{
	this->value = new char[strlen(x.value)+1];

	for (int i = 0; i < strlen(x.value); i++)
		this->value[i] = x.value[i];

	this->value[strlen(x.value)] = '\0';
}

//OPERATOR OVERLOAD
CustomStr& CustomStr::operator=(const CustomStr& s)
{	
	delete[] this->value;
	this->value = new char[strlen(s.value)+ 1];

	for (int i = 0; i < strlen(s.value); i++)
		this->value[i] = s.value[i];

	this->value[strlen(s.value)] = '\0';
	
	return *this;
}

CustomStr& CustomStr::operator=(const char* s)
{
	delete[] this->value;
	this->value = new char[strlen(s) + 1];

	for (int i = 0; i < strlen(s); i++)
		this->value[i] = s[i];

	this->value[strlen(s)] = '\0';

	return *this;
}