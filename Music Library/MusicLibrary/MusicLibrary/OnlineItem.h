#include "Item.h"
class OnlineItem :public Item
{
private:
	string url;
public:
	OnlineItem(string url, int length, string title);
	~OnlineItem();
	virtual void display();
	virtual void save(ostream &os);
};

