#include"Item.h"

class ItemFactory
{
private:
	ItemFactory();
	static ItemFactory *instance;
public:
	static ItemFactory *getInstance();
	Item *getItem(istream &is);
	~ItemFactory();
};

