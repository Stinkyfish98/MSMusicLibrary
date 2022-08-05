#include"vector.h"
#include"Item.h"

class Playlist:public Vector<Item*>
{
private:
	string name;
public:
	Playlist(string name);
	string getName() { return name; };
	Playlist();
	void display();
	void sortItems();
	~Playlist();	
	virtual void save(ostream &os);
	virtual void load(istream &is);
};

