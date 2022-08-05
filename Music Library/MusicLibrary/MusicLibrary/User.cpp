#include "User.h"



User::User(string userName, string password)
	:userName(userName), password(password)
{

}


User::~User()
{
}

Playlist * User::findPlaylist(string name)
{
	for (int i = 0; i < size; i++)
	{
		if (get(i)->getName() == name)
		{
			return get(i);
		}
	}
	return nullptr;
}

void User::sortLists()
{
	//bubble sort


}

void User::save(ostream & os)
{
	os << size << endl;
	os << userName << endl;
	os << password << endl;	
	for (int i = 0; i < get_size(); i++)
	{
		get(i)->save(os);
	}
}

void User::load(istream & is)
{
	int count;
	is >> count;
	getline(is, userName);
	getline(is, userName);
	getline(is, password);	
	for (int i = 0; i < count; i++)
	{
		Playlist *list = new Playlist("");
		list->load(is);
		add(list);
	}
}
