#pragma once

#include <iostream>

#include "Position.h"

class Source
{
protected:
	Position position;
	int currentChar = NULL;
	int lastChar = NULL;
	int nextChar = NULL;

public:
	Source();
	char NextChar();
	virtual char LoadNextCharFromSource()=0;
	int GetCurrentChar() { return currentChar; }
	Position GetPosition() { return position; }
	void SetCurrentChar(int newCurrentChar) { currentChar = newCurrentChar; }
	void Unget();
};

