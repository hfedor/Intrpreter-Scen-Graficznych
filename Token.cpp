#include "Token.h"

using namespace std;

Token::Token()
{
	type = TokenType::Undefined;
	value = "";
}

Token::Token(TokenType newType, std::string newValue, Position newPosition)
{
	type = newType;
	value = newValue;
	position = newPosition;
}

std::string Token::ToString()
{
    string typeString;
    switch (type)
    {
        case TokenType::TextContent: typeString = "tekst"; break;
        case TokenType::StringLiteral: typeString = " tekst w \"\""; break;
        case TokenType::Int: typeString = " int"; break;
        case TokenType::Float: typeString = " float"; break;
        case TokenType::LogicLiteral: typeString = " false, true, null"; break;
        case TokenType::Identifier: typeString = " identyfikator"; break;
        case TokenType::ParenthesisOpen: typeString = " ("; break;
        case TokenType::ParenthesisClose: typeString = " )"; break;
        case TokenType::SquareBracketOpen: typeString = " ["; break;
        case TokenType::SquareBracketClose: typeString = " ]"; break;
        case TokenType::GreaterThan: typeString = " >"; break;
        case TokenType::LessThan: typeString = " <"; break;
        case TokenType::ExpressionStart: typeString = " {{"; break;
        case TokenType::ExpressionEnd: typeString = " }}"; break;
        case TokenType::BlockStart: typeString = " {%"; break;
        case TokenType::BlockEnd: typeString = " %}"; break;
        case TokenType::Comma: typeString = " ,"; break;
        case TokenType::Dot: typeString = " ."; break;
        case TokenType::Colon: typeString = " :"; break;
        case TokenType::GreaterEqualThan: typeString = " >="; break;
        case TokenType::LessEqualThan: typeString = " <="; break;
        case TokenType::Equal: typeString = " =="; break;
        case TokenType::NotEqual: typeString = " !="; break;
        case TokenType::AndOperator: typeString = " &&"; break;
        case TokenType::OrOperator: typeString = " ||"; break;
        case TokenType::Foreach: typeString = " foreach"; break;
        case TokenType::If: typeString = " if"; break;
        case TokenType::Else: typeString = " else"; break;
        case TokenType::For: typeString = " for"; break;
        case TokenType::Collection: typeString = " collection"; break;
        case TokenType::Return: typeString = " return"; break;
        case TokenType::Eof: typeString = "End of File"; break;
        default: typeString = "Undefined";
    }

	return "type:" + typeString + "; value:" + value + "; position:" +  position.ToString();
}
