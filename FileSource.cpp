#include "FileSource.h"

using namespace std;

FileSource::FileSource(std::string name)
{
    Open(name);
}

void FileSource::Open(std::string name)
{
    file.open(name);
    if (file.good() == true)
    {
        std::cout << "File opened succesfully!" << std::endl;
    }
    else std::cout << "Can't open the file!" << std::endl;
}

char FileSource::LoadNextCharFromSource()
{
    char c;
    file.get(c);
    return  (char)c;
}

FileSource::~FileSource()
{
    file.close();
}
