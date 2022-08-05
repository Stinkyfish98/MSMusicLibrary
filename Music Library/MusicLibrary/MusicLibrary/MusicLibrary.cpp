#include<iostream>
#include<fstream>
#include<string>

using namespace std;

#include "MusicLibrary.h"
#include "Mp3File.h"
#include "OnlineItem.h"
#include "ItemFactory.h"

MusicLibrary::MusicLibrary()
{

}

void validateUrl(string url)
{

}


void MusicLibrary::login(string user_name, string password)
{
	//find customer;
	User *customer = findUser(user_name, password);
	if (customer == nullptr)
	{
		cout << "Invalid username!\n";
		return;
	}
	if (customer->getPassword() != password)
	{
		cout << "Invalid password!\n";
		return;
	}
	int option=100;
	int length;
	string title;
	string fileName, path,url;
	int bytes,index;
	Playlist *list;
	while (option != 8)
	{
		cout << "1) Add playlist\n";
		cout << "2) Add mp3file\n";
		cout << "3) Add online media\n";		
		cout << "4) Show playlist\n";
		cout << "5) Remove playlist\n";
		cout << "6) Remove playlist item\n";
		cout << "7) Sort playlist by title\n";
		cout << "8) Logout\n";
		cin >> option;
		getline(cin,title);
		try
		{
			switch (option)
			{
			case 1:
				cout << "Enter playlist name:";
				getline(cin, title);
				list = customer->findPlaylist(title);
				if (list != NULL) throw "List already exist!";
				customer->add(new Playlist(title));
				break;
			case 2:
				cout << "Enter playlist name:";
				getline(cin, title);
				list=customer->findPlaylist(title);
				if (list == NULL) throw "Invalid list name";
				cout << "Enter item title:";
				getline(cin, title);
				cout << "Enter mp3 file name:";
				getline(cin, fileName);
				cout << "Enter path:";
				getline(cin, path);
				cout << "length in seconds :";
				cin >> length;
				cout << "Size in bytes:";
				cin >> bytes;
				list->add(new Mp3File(fileName, path, bytes, length, title));
				break;
			case 3:
				cout << "Enter playlist name:";
				getline(cin, title);
				list = customer->findPlaylist(title);
				if (list == NULL) throw "Invalid list name";
				cout << "Enter item title:";
				getline(cin, title);
				cout << "Enter url:";
				getline(cin, url);
				cout << "length in seconds :";
				cin >> length;
				list->add(new OnlineItem(url, length, title));
				break;
			case 4:
				cout << "Enter playlist name:";
				getline(cin, title);
				list = customer->findPlaylist(title);
				if (list == NULL) throw "Invalid list name";
				list->display();
				break;
			case 5:				
				cout << "Enter playlist name:";
				getline(cin, title);
				list = customer->findPlaylist(title);
				if (list == NULL) throw "Invalid list name";
				customer->remove(list);
				delete list;
				break;
			case 6:
				cout << "Enter playlist name:";
				getline(cin, title);
				list = customer->findPlaylist(title);
				if (list == NULL) throw "Invalid list name";
				list->display();
				cout << "Select item to delete 1-"<<list->get_size()<<": ";
				cin >> index;
				if (index<1 || index>list->get_size()) throw "invalid index!";
				list->remove(list->get(index-1));				
				break;
			case 7:
				cout << "Enter playlist name:";
				getline(cin, title);
				list = customer->findPlaylist(title);
				if (list == NULL) throw "Invalid list name";
				list->sortItems();
				list->display();		

				break;
			}
		}
		catch (string message)
		{
			cout << message << "\n";
		}
	}
}



bool MusicLibrary::addUser(string user_name, string password)
{
	if (findUser(user_name, password) != nullptr) {
		return false;
	}
	add(new User(user_name, password));
	return true;
}

User * MusicLibrary::findUser(string user_name, string password)
{
	for (int i = 0; i < get_size(); i++)
	{
		if (get(i)->getUserName() == user_name)
		{
			return get(i);
		}
	}
	return nullptr;
}




MusicLibrary::~MusicLibrary()
{
}

void MusicLibrary::save()
{
	ofstream output("library.txt");
	if (output.fail())
	{
		cout << "can't write to library.txt\n";
		return;
	}
	output << size << endl;
	for (int i = 0; i < get_size(); i++)
	{
		get(i)->save(output);
	}
	output.close();

}

void MusicLibrary::load()
{
	ifstream input("library.txt");
	if (input.fail())
	{
		cout << "can't open to library.txt\n";
		return;
	}
	int count;
	input >> count;
	for (int i = 0; i < count; i++)
	{
		User *user = new User("", "");
		user->load(input);
		add(user);
	}
	input.close();
}
