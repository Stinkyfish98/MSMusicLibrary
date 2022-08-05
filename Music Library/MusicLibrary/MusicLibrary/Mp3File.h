#pragma once
#include "Item.h"
class Mp3File :	public Item
{
private:
	string fileName,path;
	int bytes;
public:
	Mp3File();
	~Mp3File();
	Mp3File(string fileName, string path, int bytes, int length, string title);
	virtual void display();
	virtual void save(ostream &os);
};

