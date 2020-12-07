#pragma once

#include <iostream>

#include "Position.h"

enum class TokenType
{
    Undefined,

    TextContent,            // zwyk³y tekst
    StringLiteral,          // tekst w ""
    Int,                    // int
    Float,                  // float
    LogicLiteral,           // false, true, null
    Identifier,             // nazwy funkcji, argumenty funkcji, w³aœciwoœci obiektów

    ParenthesisOpen,        // (
    ParenthesisClose,       // )
    SquareBracketOpen,      // [
    SquareBracketClose,     // ]
    GreaterThan,            // >
    LessThan,               // <

    ExpressionStart,        // {{
    ExpressionEnd,          // }}
    BlockStart,             // {%
    BlockEnd,               // %}

    Comma,                  // ,
    Dot,                    // .
    Colon,                  // :
    GreaterEqualThan,       // >=
    LessEqualThan,          // <=
    Equal,                  // ==
    NotEqual,               // !=
    AndOperator,            // &&
    OrOperator,             // ||

    Foreach,                // foteach
    If,                     // if
    Else,                   // else
    For,                    // for
    Collection,             // collection
    Return,                 // Return

    Eof,                    // znak koñca pliku
};


class Token
{
private:
    TokenType type;         // typ tokena
    std::string value;      // wartosc tokena
    Position position;    // pozycja tokena
public:
    Token();
    Token(TokenType, std::string, Position);
    TokenType GetType() { return type; }
    std::string GetValue() { return value; }
    Position GetPosition() { return position; }
    void SetType(TokenType newType) { type = newType; }
    void SetValue(std::string newValue) { value = newValue; }
    void SetPosition(Position newPosition) { position = newPosition; }
    std::string ToString();
};

