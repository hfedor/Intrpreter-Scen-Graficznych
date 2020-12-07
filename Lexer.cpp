#include "Lexer.h"

using namespace std;

Lexer::Lexer(Source *new_source)
{
	source = new_source;
}

Token Lexer::NextToken()
{
    source->NextChar();
    SkipWhitespaces();

    string readValue;
    Position currentPosition = source->GetPosition();

    TokenType currentTokenType;

    currentTokenType = ReadEofToken();
    if (currentTokenType == TokenType::Undefined)
    {
        currentTokenType = ReadKeywordToken();
        if (currentTokenType == TokenType::Undefined)
        {
            currentTokenType = ReadSymbolToken();
            if (currentTokenType == TokenType::Undefined)
            {
                currentTokenType = ReadIdentifierToken(&readValue);
                if (currentTokenType == TokenType::Undefined)
                {
                    currentTokenType = ReadNumberToken(&readValue);
                    if (currentTokenType == TokenType::Undefined)
                    {
                        currentTokenType = ReadStringToken(&readValue);
                    }
                }
            }
        }
    }

    currentToken.SetType(currentTokenType);
    currentToken.SetPosition(currentPosition);
    currentToken.SetValue(readValue);

    return currentToken;
}

TokenType Lexer::ReadEofToken()
{
    cout << (char)source->GetCurrentChar() << endl;
    if (source->GetCurrentChar() == -52)
        return TokenType::Eof;

    return TokenType::Undefined;
}

void Lexer::SkipWhitespaces()
{
    while (IsWhiteSpace((char)source->GetCurrentChar()))
        source->NextChar();
}

void Lexer::SkipDigitsAndLetters()
{
    char curchar = source->GetCurrentChar();

    while (IsDigit(curchar) || IsLetter(curchar))
    {
        source->NextChar();
        curchar = source->GetCurrentChar();
    }

    source->Unget();
}

int Lexer::SkipSpaces()
{
    int skipped = 0;
    while (source->GetCurrentChar() == ' ' || source->GetCurrentChar() == '\t')
    {
        source->NextChar();
        skipped++;
    }

    return skipped;
}

TokenType Lexer::ReadKeywordToken()
{
    return TokenType::Undefined;
}

TokenType Lexer::ReadSymbolToken()
{
    return TokenType::Undefined;
}

TokenType Lexer::ReadNumberToken(string *readValue)
{
    string numberString = "";
    int curchar;
    curchar = source->GetCurrentChar();
    if (curchar != '-' && ( curchar < 45 || curchar > 57 ))
        return TokenType::Undefined;

    if (source->GetCurrentChar() == '0')
    {
        numberString += '0';
        source->NextChar();
        curchar = source->GetCurrentChar();
        if(IsWhiteSpace(curchar) || IsAritmeticOperator(curchar) || curchar == ';' || curchar == '=' || curchar == -52)
        {
            source->Unget();
            *readValue = numberString;
            return TokenType::Int;
        }
        else if (curchar == '.')
        {
            numberString += '.';

            source->NextChar();
            curchar = source->GetCurrentChar();
            if (IsDigit(curchar))
                numberString += curchar;
            else
            {
                source->Unget();
                return TokenType::Undefined;
            }

            for (int i = 1; i < 7; i++)
            {
                source->NextChar();
                curchar = source->GetCurrentChar();
                if (IsDigit(curchar))
                    numberString += curchar;
                else if (IsWhiteSpace(curchar) || IsAritmeticOperator(curchar) || curchar == ';' || curchar == '=' || curchar == -52)
                {
                    source->Unget();
                    *readValue = numberString;
                    return TokenType::Float;
                }
                else
                {
                    SkipDigitsAndLetters();
                    return TokenType::Undefined;
                }
            }

            SkipDigitsAndLetters();
            return TokenType::Undefined;
        }
    }

    if (source->GetCurrentChar() == '-')
    {
        numberString += '-';
        source->NextChar();
        curchar = source->GetCurrentChar();
        
        if (curchar == '0')
        {
            numberString += curchar;
            source->NextChar();
            curchar = source->GetCurrentChar();

            if (curchar == '.')
            {
                numberString += curchar;

                for (int i = 0; i < 8; i++)
                {
                    source->NextChar();
                    curchar = source->GetCurrentChar();
                    if (IsDigit(curchar))
                        numberString += curchar;
                    else if (IsWhiteSpace(curchar) || IsAritmeticOperator(curchar) || curchar == ';' || curchar == '=' || curchar == -52)
                    {
                        source->Unget();
                        *readValue = numberString;
                        return TokenType::Float;
                    }
                    else
                    {
                        SkipDigitsAndLetters();
                        return TokenType::Undefined;
                    }
                }
            }
            else if (IsWhiteSpace(curchar) || IsAritmeticOperator(curchar) || curchar == ';' || curchar == '=' || curchar == -52)
            {
                source->Unget();
                *readValue = numberString;
                return TokenType::Int;
            }
            else
            {
                SkipDigitsAndLetters();
                return TokenType::Undefined;
            }
        }
        else
        {
            SkipDigitsAndLetters();
            return TokenType::Undefined;
        }
    }

    if (IsNonZeroDigit(curchar))
    {
        numberString += curchar;
        for (int i = 1; i < 11; i++)
        {
            source->NextChar();
            curchar = source->GetCurrentChar();
            if (IsDigit(curchar))
                numberString += curchar;
            else if (IsWhiteSpace(curchar) || IsAritmeticOperator(curchar) || curchar == ';' || curchar == '=' || curchar == -52)
            {
                source->Unget();
                *readValue = numberString;
                return TokenType::Int;
            }
            else if (curchar == '.')
                for (int j = i; j < 7; j++)
                {
                    source->NextChar();
                    curchar = source->GetCurrentChar();
                    if (IsDigit(curchar))
                        numberString += curchar;
                    else if (IsWhiteSpace(curchar) || IsAritmeticOperator(curchar) || curchar == ';' || curchar == '=' || curchar == -52)
                    {
                        source->Unget();
                        *readValue = numberString;
                        return TokenType::Float;
                    }
                    else
                    {
                        SkipDigitsAndLetters();
                        return TokenType::Undefined;
                    }
                }
            else
            {
                SkipDigitsAndLetters();
                return TokenType::Undefined;
            }
        }
    }
    
    return TokenType::Undefined;
}

TokenType Lexer::ReadStringToken(std::string* readValue)
{
    return TokenType();
}

TokenType Lexer::ReadIdentifierToken(std::string* readValue)
{
    string identifierString = "";
    int curchar;
    curchar = source->GetCurrentChar();

    if (IsLetter(curchar))
    {
        while (IsLetter(curchar) || IsDigit(curchar) || curchar == '_')
        {
            identifierString += curchar;
            source->NextChar();
            curchar = source->GetCurrentChar();
        }
        if (!IsWhiteSpace(curchar))
            source->Unget();

        *readValue = identifierString;
        return TokenType::Identifier;
    }

    return TokenType::Undefined;
}

bool IsWhiteSpace(char c)
{
    return (c == ' ' || c == '\t' || c == 10);
}

bool IsDigit(int c)
{
    return IsNonZeroDigit(c) || c == '0';
}

bool IsNonZeroDigit(int c)
{
    return (c >= 49 && c <= 57 );
}

bool IsAritmeticOperator(int c)
{
    return (c == '+'|| c == '-' || c == '/' || c == '*' );
}

bool IsRelationalOperator(int c)
{
    return (c == '<' || c == '>');
}

bool IsBigLetter(int c)
{
    return (c >= 65 && c<= 90);
}

bool IsLetter(int c)
{
    return IsBigLetter(c) || IsSmallLetter(c);
}

bool IsSmallLetter(int c)
{
    return (c >= 97 && c <= 122);
}