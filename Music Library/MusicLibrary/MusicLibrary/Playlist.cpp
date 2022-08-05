#include<iostream>
#include<fstream>
#include<string>

using namespace std;

#include "MusicLibrary.h"
#include "Mp3File.h"
#include "OnlineItem.h"

#include "ItemFactory.h"




Playlist::Playlist(string name)
	:name(name)
{
}

Playlist::Playlist()
{
}

void Playlist::display()
{
	cout << "playlist name: " << name << endl;
	for (int i = 0; i < get_size(); i++)
	{
		cout << (i + 1) << ". ";
		get(i)->display();
		cout << endl;
	}

}

//Minimum of one sort not from the STL
void Playlist::sortItems()
{
	bool swap;
	do
	{
		swap = false;
		for (int i = 0; i < size - 1; i++)
		{
			if (get(i)->getTitle() > get(i + 1)->getTitle())
			{
				Item *item = get(i);
				get(i) = get(i + 1);
				get(i + 1) = item;
				swap = true;
			}
		}
	} while (swap);
}


Playlist::~Playlist()
{
}

void Playlist::save(ostream & os)
{
	os << size << endl;
	os << name << endl;	
	for (int i = 0; i < get_size(); i++)
	{
		get(i)->save(os);
	}
}

void Playlist::load(istream & is)
{
	
	int count;
	is >> count;
	getline(is, name);
	getline(is, name);
	for (int i = 0; i < count; i++)
	{
		add(ItemFactory::getInstance()->getItem(is));
	}
}
