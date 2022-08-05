#include <iostream>

using namespace std;

#include "OnlineItem.h"




OnlineItem::OnlineItem(string url, int length, string title)
	:url(url), Item(length, title)
{
}

OnlineItem::~OnlineItem()
{
}

void OnlineItem::display()
{
	cout << "Online media:" << title << ", url" << url << ", length: " << length;

}

void OnlineItem::save(ostream & os)
{
	os << "online" << endl << length << endl << title << endl << url << endl;
}
