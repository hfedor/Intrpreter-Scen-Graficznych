#pragma once
#include <iostream>

#include "Token.h"
#include "Source.h"
#include "FileSource.h"

class Lexer
{
private:
	Token currentToken;
	Source* source;

public:
	Lexer(Source *source);
	Token GetToken() { return currentToken; }
	Token NextToken();
	TokenType ReadEofToken();
	void SkipWhitespaces();
	void SkipDigitsAndLetters();
	int SkipSpaces();
	TokenType ReadKeywordToken();
	TokenType ReadSymbolToken();
	TokenType ReadNumberToken(std::string* readValue);
	TokenType ReadStringToken(std::string* readValue);
	TokenType ReadIdentifierToken(std::string* readValue);
};

bool IsWhiteSpace(char);
bool IsDigit(int);
bool IsNonZeroDigit(int);
bool IsAritmeticOperator(int);
bool IsRelationalOperator(int);
bool IsBigLetter(int);
bool IsLetter(int);
bool IsSmallLetter(int);