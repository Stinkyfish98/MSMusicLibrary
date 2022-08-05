#include<iostream>
#include<string>

using namespace std;

#include "Mp3File.h"





Mp3File::~Mp3File()
{
}

Mp3File::Mp3File(string fileName, string path, int bytes, int length, string title)
	:fileName(fileName),path(path),bytes(bytes),Item(length,title)
{
	
}

void Mp3File::display()
{
	cout << "Mp3:" << title << ", file: " <<path<<"\\"<< fileName << ", length: " << length<<" sec";
}

void Mp3File::save(ostream & os)
{
	os << "mp3" << endl << title << endl << path << endl <<
		fileName << endl << length << endl << bytes<<endl;
}
