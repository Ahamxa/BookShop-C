#include<iostream>
#include"Customer.h"
#include"admin.h"
#include"Book.h"
#include"Cart.h"
#include"Magzines.h"
#include"Newspaper.h"
#include"Stationary.h"
#include"Prizebond.h"
#include<string>
#include<stdlib.h>
#include<fstream>
using namespace std;

istream& operator>>(istream& in, Book& obj) {

	cout << "Book ID: ";
	in >> obj.id;
	cout << "Book name : ";
	in >> obj.name;
	
	cout << "Author: ";
	in >> obj.author;
	cout << "Price: ";
	in >> obj.price;
	
	return in;
}
ostream& operator<<(ostream& out, Book& obj) {
	out << obj.id<<endl;
	out << obj.name<<endl;
	out << obj.author<<endl;
	out << obj.price<<endl;
	return out;
}

istream& operator>>(istream& in, Magzines& obj) {
	cout << "Id: ";
	in >> obj.id;
	cout << "Name: ";
	in >> obj.name;
	cout << "Price: ";
	in >> obj.price;
	return in;
}
ostream& operator<<(ostream& out, Magzines& obj) {
	out << obj.id << endl;
	out << obj.name << endl;
	out << obj.price << endl;
	return out;
}

istream& operator>>(istream& in, Newspaper& obj) {
	cout << "Name: ";
	in >> obj.name;
	cout << "Price: ";
	in >> obj.price;

	return in;
}
ostream& operator<<(ostream& out, Newspaper& obj) {
	out << obj.name << endl;
	out << obj.price << endl;
	return out;
}

istream& operator>>(istream& in, Stationary& obj) {
	cout << "Id: ";
	in >> obj.id;
	cout << "Name: ";
	in >> obj.name;
	cout << "Price: ";
	in >> obj.price;
	return in;
}
ostream& operator<<(ostream& out, Stationary& obj) {
	out << obj.id << endl;
	out << obj.name << endl;
	out << obj.price << endl;
	return out;
}

istream& operator>>(istream& in, Prizebond& obj) {
	cout << "Id: ";
	in >> obj.id;
	cout << "Price: ";
	in >> obj.price;

	return in;
}
ostream& operator<<(ostream& out, Prizebond& obj) {
	out << obj.id << endl;
	out << obj.price << endl;
	return out;
}




int main() {

	here:
	int choice = 0;
	cout << " \n\t\t\t\t\t\t  Hamxa's Book Shop \n";
	cout << "\t\t\t\t\t\t *******************\n";

	cout << "\n\n\n\n\n\t\t\t\t\t\tEnter 1 for Customer Portal\n";
	cout << "\t\t\t\t\t\tEnter 2 for Admin Portal\n";
	cout << "\t\t\t\t\t\tEnter your choice:";
	cin >> choice;
	while (choice != 1 && choice != 2) {
		system("CLS");
		cerr << "Wrong input!\n";
		cout << "\n\n\n\n\n\t\t\t\t\t\tEnter 1 for Customer Portal\n";
		cout << "\t\t\t\t\t\tEnter 2 for Admin Portal\n";
		cout << "\t\t\t\t\t\tEnter your choice:";
		cin >> choice;
		
	}
	system("CLS");
	if (choice == 1) {
	
		Customer customer;
		cout << " \n\t\t\t\t\t\t   Customer Portal \n";
		cout << "\t\t\t\t\t\t *******************\n";
		int choi = 0;
		cout << "\n\n\n\n\n\t\t\t\t\t\tEnter 1 for Registration\n";
		cout << "\t\t\t\t\t\tEnter 2 for login\n";
		cout << "\t\t\t\t\t\tEnter your choice:";
		cin >> choi;
		system("CLS");
		if (choi == 1) {

			bool log = false;
			log = customer.registration();
			if (log == true) {
               customer.login();
			   system("CLS");
			   goto here;
			}
		}
		if (choi == 2) {
				customer.login();
				system("CLS");
				goto here;
			}

		else {
			cerr << "Wrong input!\n";
		}

		
	}

	if (choice == 2) {
		Admin* a = Admin::getInstance();
		int ch = 0;

		cout << " \n\t\t\t\t\t\t   Admin Portal \n";
		cout << "\t\t\t\t\t\t ****************\n";

		cout << "\n\n\n\n\n\t\t\t\t\t\tEnter 1 for New Admin\n";
		cout << "\t\t\t\t\t\tEnter 2 for login\n";
		cout << "\t\t\t\t\t\tEnter your choice:";
		
		cin >> ch;
		bool lo= false;
		if (ch == 1) {
			lo= a->registration();
			if (lo == true) {
				a->login();
				system("CLS");
				goto here;
			}
		}


		if (ch == 2) {
			a->login();
			system("CLS");
			goto here;

		}
		else {
			cerr << "Wrong input!\n";
			return 0;

		}



	}
		
	return 0;
	}
