#include "Source.h"

using namespace std;

Source::Source()
{

}

char Source::NextChar()
{
	if(position.IsEOF())
	{
		position.SetEOF(false);
		position.SetLastColumn(position.GetColumn());
		position.SetColumn(0);
		position.NextLine();
	}
	else
	{
		position.NextColumn();
		position.SetLastColumn(-1);
	}

	if (currentChar == 10)
		position.SetEOF(true);

	if (nextChar != NULL)
	{

		lastChar = currentChar;
		currentChar = nextChar;
		nextChar = NULL;
		return currentChar;
	}

	lastChar = currentChar;
	return currentChar = LoadNextCharFromSource();
}

void Source::Unget()
{
	if (position.GetLastColumn() != -1)
	{
		position.SetColumn(position.GetLastColumn());
		position.SetLastColumn(-1);
		position.BackLine();
		position.SetEOF(true);
	}
	else
		position.BackColumn();

	nextChar = currentChar;
	currentChar = lastChar;
	lastChar = NULL;
}
