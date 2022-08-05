#ifndef USER_H
#define USER_H

#include"Playlist.h"

class User :public Vector<Playlist*>
{
private:
	string userName;
	string password;
public:
	User(string user_name, string password);
	string getUserName() { return userName; };
	string getPassword() { return password; };
	~User();
	Playlist*findPlaylist(string name);
	void sortLists();
	virtual void save(ostream &os);
	virtual void load(istream &is);
};


#endif