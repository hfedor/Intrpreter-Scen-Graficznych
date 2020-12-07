#pragma once
#include <iostream>
#include <fstream>

#include "Source.h""

class FileSource : public Source
{
private:
	std::ifstream file;
public:
	FileSource(std::string);
	void Open(std::string name);
	char LoadNextCharFromSource();
	~FileSource();
};

