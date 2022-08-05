#ifndef ITEM_H
#define ITEM_H

#include <string>

using namespace std;

class Item
{
protected:
	int length;
	string title;
public:
	string getTitle() { return title; };
	Item(int length,string title);
	~Item();
	virtual void display() = 0;
	virtual void save(ostream &os);
};

#endif