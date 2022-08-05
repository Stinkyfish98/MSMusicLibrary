#include<iostream>
#include<fstream>
#include<string>

using namespace std;

#include "MusicLibrary.h"
#include "Mp3File.h"
#include "OnlineItem.h"
#include "ItemFactory.h"


ItemFactory* ItemFactory::instance = NULL;

ItemFactory * ItemFactory::getInstance()
{
	if (instance == NULL)
	{
		instance = new ItemFactory();
	}
	return instance;
}

Item * ItemFactory::getItem(istream & is)
{
	string type,temp;
	int length;
	string title;
	string fileName, path, url;
	int bytes;
	getline(is, type);
	if (type == "mp3")
	{
		getline(is, title);
		getline(is, path);
		getline(is, fileName);
		is >> length;
		is >> bytes;
		getline(is, temp);
		return new Mp3File(fileName, path, bytes, length, title);
	}
	else if(type == "online")
	{
		is >> length;
		getline(is, title);
		getline(is, title);
		getline(is, url);
		return new OnlineItem(url, length, title);
	}
	return nullptr;
}

ItemFactory::ItemFactory()
{
	instance = NULL;
}


ItemFactory::~ItemFactory()
{
}
