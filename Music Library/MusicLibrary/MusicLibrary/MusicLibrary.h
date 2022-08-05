#include<vector>

using namespace std;

#include"User.h"

class MusicLibrary :public Vector<User*>
{
private:
	vector<Item*> allItems;
public:
	void login(string userName, string password);
	bool addUser(string user_name, string password);
	//Use of searching (linear/binary)
	User *findUser(string user_name, string password);
	MusicLibrary();
	~MusicLibrary();
	virtual void save();
	virtual void load();
};
