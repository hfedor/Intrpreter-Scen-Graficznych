#include "Position.h"

using namespace std;

Position::Position()
{
    column = -1;
    line = 0;
}

Position::Position(int column, int line)
{
    column = column;
    line = line;
}

void Position::NextColumn()
{
    column++;
}

void Position::NextLine()
{
    line++;
}

void Position::BackLine()
{
    line--;
}

void Position::BackColumn()
{
    column--;
}

string Position::ToString()
{
    return "{" + to_string(column) + "}:{" + to_string(line) + "}";
}
