#pragma once

#include <iostream>
#include <string>
#include <map>

class Position
{
private:
    int line = -1;	// numer wiersza pozycji
	int column = 0;	// numer kolumny pozycji

    bool eof = false;

    int lastLine = -1;
    int lastColumn = -1;

    int nextLine = -1;
    int nextColumn = -1;

public:
    Position();
    Position(int line, int column);
    void BackLine();    // Cofniêcie na poprzedni¹ liniê
    void BackColumn();  // Cofniêcie na poprzedni¹ kolumknê
    int GetLine() { return line; }
    int GetColumn() { return column; }
    int GetLastLine() { return lastLine; }
    int GetLastColumn() { return lastColumn; }
    int GetNextLine() { return nextLine; }
    int GetNextColumn() { return nextColumn; }
    void NextLine();    // Ustawia nastêpn¹ liniê
    void NextColumn();  // Ustawia nastêpn¹ kolumnê
    void SetLine(int newLine) { line = newLine; }
    void SetColumn(int newColumn) { column = newColumn; }
    void SetLastLine(int newLastLine) { lastLine = newLastLine; }
    void SetLastColumn(int newLastColumn) { lastColumn = newLastColumn; }
    void SetNextLine(int newNextLine) { nextLine = newNextLine; }
    void SetNextColumn(int newNextColumn) { nextColumn = newNextColumn; }
    void SetEOF(bool newEOF) { eof = newEOF; }
    std::string ToString();
    bool IsEOF() { return eof; }
};

