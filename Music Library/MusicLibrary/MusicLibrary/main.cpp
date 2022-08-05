#include<iostream>
#include<string>

using namespace std;

#include "MusicLibrary.h"
void openingScreen()
{
	cout << "Welcome to my Music library system \n";
	cout <<  "With the following features.  \n";
	cout << "Opening screen with a description of the application and instructions \n";
	cout << "Menu for the user to choose options \n";
	cout << " user menu and main menu \n";
	cout << "4 classes DONE\n";
	cout << "Innheritance OnlineItem and Mp3File and others\n";
	cout << "Polymorphism OnlineItem and Mp3File polymorphic\n";
	cout << "Encapsulation used in all classes\n";
	cout << "File input and output processing  program save/load db into library.txt\n";
	cout << "Minimum of one search and one sort not from the STL \n";
	cout << "Templates Used for vector class\n";
	cout << "Vectors  NOT USED\n";
	cout << "Iterators NOT USED\n";
	cout << "Exception handling(void MusicLibrary::login\n";
	cout << "Design Pattern(s) Factory pattern as singleton\n";
	cout << "Boost Library NOT USED\n";
	system("pause");
	system("cls");
}
int main()
{
	openingScreen();
	string userName, password;
	int option;
	MusicLibrary library;
	library.load();
	do
	{
		cout << "1) Add Customer\n";
		cout << "2) Login\n";
		cout << "3) Exit\n\n";
		cout << "Option: ";
		cin >> option;
		getline(cin, userName);
		switch (option)
		{
		case 1:
			cout << "Enter user name: ";
			getline(cin, userName);
			cout << "Enter password: ";
			getline(cin, password);
			if (!library.addUser(userName, password))
			{
				cout << "Invalid username!\n";
			}
			break;
		case 2:
			cout << "Enter user name: ";
			getline(cin, userName);
			cout << "Enter password: ";
			getline(cin, password);
			library.login(userName, password);			
			break;
		case 3:
			break;

		}
	} while (option != 3);
	library.save();
	return 0;
}
