#include"Customer.h"
#include"Book.h"
#include"Magzines.h"
#include"Newspaper.h"
#include"Stationary.h"
#include"Cart.h"
#include<iostream>
#include<fstream>
#include <string>
#include<cstring>
using namespace std;

Customer::Customer() {
	id = 0;
	name = { '\0' };
	password = { '\0' };
	email = { '\0' };

}

void Customer::setId(int id) {
	this->id = id;

}
void Customer::setName(string name) {
	this->name = name;
}
void Customer::setPassword(string password) {
	this->password = password;
}

void Customer::setEmail(string email) {
	this->email = email;
}
void Customer::setCart(Cart cart) {
	this->cart = cart;
}



Cart Customer::getCart() {
	return cart;
}

int Customer::getId() {
	return id;
}
string Customer::getName() {
	return name;
}

string Customer::getEmail() {
	return email;
}

bool Customer::registration() {

	cout << "                    ****Cuctomer registration***" << endl;
	cout << "Enter a unique 4 digit id (Integer value): ";
	cin >> id;
	while (id < 0 || id > 9999) {

		cout << "Wrong ID Entered! Enter  a unique 4 digit id (Integer value): ";
		cin >> id;
	}
	
	cout << "Enter a username for your account (without spaces): ";
	cin >> name;
	

	cout << "Enter a password for your account: ";
	cin >> password;

	cout << "Enter your Email address: ";
	cin >> email;

	ofstream out("users.txt",ios::app);
	out << id <<"    " << name <<"    " << password <<"    " << email << endl;

	out.close();

	cout << "You are now registered!" << endl;
	
	return true;
}

bool Customer::login() {
	system("CLS");
	cout << " \n\t\t\t\t\t\t   Login \n";
	cout << "\t\t\t\t\t\t  *******\n";
	bool found = false;
	string uname;
	string pword;
	ifstream fin("users.txt");
	cout << "Enter the username for your account: ";
	cin >> uname;
	cout << "Enter password for your account: ";
	cin >> pword;
	if (fin.is_open()) {
		

		while (fin >> id) {
			
			fin >> name;
			fin >> password;
			fin >> email;
			if (uname == name && pword == password) {
				found = true;
			}
		}

		if (found == true) {
			cout << "You are logged on" << endl;
			system("pause");
			system("CLS");
			int c = 0;
		here:
			cout << "\n\t\t\t\t\t\t Welcome to Customer portal\n";
			cout << "\t\t\t\t\t\t ****************************\n";
			cout << "Enter 1 for search items\n";
			cout << "Enter 2 for add items\n";
			cout << "Enter 3 for display cart\n";
			cout << "Enter 4 for payment\n";
			cout << "Enter 5 for  logout\n";
			cout << "Enter your choice: ";
			cin >> c;

			if (c == 1) {
				system("CLS");
				search();
				system("CLS");
				goto here;
			}

			if (c == 2) {
				system("CLS");
				additems();
				system("CLS");
				goto here;
			}

			if (c == 3) {
				system("CLS");
				dispCart();
				system("pause");
				system("CLS");
				goto here;
			}

			if (c == 4) {


				cin.ignore();
				system("CLS");
				payment();
				system("pause");
				system("CLS");
				goto here;
			}
			if (c == 5) {
				exit;
			}
		}

		else {
			cerr << "user not found" << endl;
			found = false;
		}

		fin.close();

	}
	else {
		cerr<< "user.txt not found!" << endl;
	}

	return found;
}


void Customer::search() {

	int c = 0;
here:
	cout << "\n\t\t\t\t\t\tSearch Items \n";
	cout << "\t\t\t\t\t\t *************\n";
	cout << "1: Books" << endl;
	cout << "2: Magzines" << endl;
	cout << "3: Newspapers" << endl;
	cout << "4: Stationary" << endl;
	cout << "5: Prize Bonds" << endl;
	cout << "6: Go back" << endl;
	cout << "Enter your choice: ";
	cin >> c;
	cin.ignore();
	if (c == 1) {
		system("CLS");
		int choice = 0;
		while (1) {
			cout << " Enter the name of book to search/add : ";
			string namebook;
			getline(cin, namebook);

			ifstream file("books.txt", ios::in);
			if (file.is_open()) {
				float p = 0.0f;
				int count = 0;
				bool found = false;
				while (file >> book.id) {
					file.ignore();
					getline(file, book.name);
					getline(file, book.author);
					file >> book.price;


					if (namebook == book.name) {
						found = true;
						cout << "Book found" << endl;
						cout << book;
						cout << "Do you want to add this item(y/n): ";
						char ch = '\0';
						cin >> ch;
						cin.ignore();
						if (ch == 'y') {
							system("CLS");
							p = cart.getTotalPrice();
							count = cart.getItemCount();

							p = p + book.price;
							count++;
							cart.setTotalPrice(p);
							cart.setItemCount(count);

							cout << "Item added to cart\n";
							cart.disp();


						}
						if (ch == 'n') {
							system("CLS");
							goto here;
						
						}
					}

				}
				if (found == false) {
					cout << "Book not found\n";
				}
				cout << "Enter 1 to continue\n";
				cout << "Enter 2 to go back\n";
				cin >> choice;

				if (choice == 1) {
					cin.ignore();

					system("CLS");
					continue;
				}
				else if (choice == 2) {
					system("CLS");
					goto here;
				}

			}
			file.close();
		}

	}

	if (c == 2) {
		system("CLS");
		int cho = 0;
		while (1) {
			cout << " Enter the name of  Magzine to search/add : ";
			string namebook;
			getline(cin, namebook);
			ifstream file("magzine.txt", ios::in);
			float p = 0.0f;
			int count = 0;
			bool found = false;
			while (file >> magzine.id) {
				file.ignore();
				getline(file, magzine.name);
				file >> magzine.price;


				if (namebook == magzine.name) {
					found = true;
					cout << "Magzine found" << endl;
					cout << magzine;
					cout << "Do you want to add this item(y/n): ";
					char ch = '\0';
					cin >> ch;
					if (ch == 'y') {
						system("CLS");
						p = cart.getTotalPrice();
						count = cart.getItemCount();

						p = p + magzine.price;
						count++;
						cart.setTotalPrice(p);
						cart.setItemCount(count);

						cout << "Item added to cart\n";
						cart.disp();


					}
					if (ch == 'n') {
						system("CLS");
						goto here;
					}
				}

			}

			if (found == false) {
				cout << "Magzine not found\n";
			}

			cout << "Enter 1 to continue\n";
			cout << "Enter 2 to Go back\n";
			cin >> cho;

			if (cho == 1) {
				cin.ignore();
				system("CLS");
				continue;
			}
			else if (cho == 2) {
				system("CLS");
				goto here;
			}

			file.close();
		}
	}

	if (c == 3) {
		system("CLS");
		int cho = 0;
		while (1) {
			cout << " Enter the name of  newspaper to search/add : ";
			string namebook;
			getline(cin, namebook);
			ifstream file("newspaper.txt", ios::in);
			float p = 0.0f;
			int count = 0;
			bool found = false;
			while (getline(file,newspaper.name) ){
				
				file >> newspaper.price;
				file.ignore();


				if (namebook == newspaper.name) {
					found = true;
					cout << "Newspaper found" << endl;
					cout << newspaper;
					cout << "Do you want to add this item(y/n): ";
					char ch = '\0';
					cin >> ch;
					if (ch == 'y') {
						system("CLS");
						p = cart.getTotalPrice();
						count = cart.getItemCount();

						p = p + newspaper.price;
						count++;
						cart.setTotalPrice(p);
						cart.setItemCount(count);

						cout << "Item added to cart\n";
						cart.disp();


					}
					if (ch == 'n') {
						system("CLS");
						goto here;
					}
				}

			}

			if (found == false) {
				cout << "Newspaper not found\n";
			}

			cout << "Enter 1 to continue\n";
			cout << "Enter 2 to go back\n";
			cin >> cho;

			if (cho == 1) {
				cin.ignore();
				system("CLS");
				continue;
			}
			else if (cho == 2) {
				system("CLS");
				goto here;
			}

			file.close();
		}



	}

	if (c == 4) {
		system("CLS");
		int cho = 0;
		while (1) {
			cout << " Enter the name of  item to search/add : ";
			string namebook;
			getline(cin, namebook);
			ifstream file("stationary.txt", ios::in);
			float p = 0.0f;
			int count = 0;
			bool found = false;
			while (file >> stationary.id) {
				file.ignore();
				getline(file, stationary.name);
				file >> stationary.price;


				if (namebook == stationary.name) {
					found = true;
					cout << "Item found" << endl;
					cout << stationary;
					cout << "Do you want to add this item(y/n): ";
					char ch = '\0';
					cin >> ch;
					if (ch == 'y') {
						system("CLS");
						p = cart.getTotalPrice();
						count = cart.getItemCount();

						p = p + stationary.price;
						count++;
						cart.setTotalPrice(p);
						cart.setItemCount(count);

						cout << "Item added to cart\n";
						cart.disp();


					}
					if (ch == 'n') {
						system("CLS");
						goto here;
					}
				}

			}

			if (found == false) {
				cout << "Item not found\n";
			}

			cout << "Enter 1 to continue\n";
			cout << "Enter 2 to go back\n";
			cin >> cho;

			if (cho == 1) {
				cin.ignore();
				system("CLS");
				continue;
			}
			else if (cho == 2) {
				system("CLS");
				goto here;
			}

			file.close();
		}

	}

	if (c == 5) {
		system("CLS");
		int cho = 0;
		while (1) {
			cout << " Enter the Id of  Prize bond to search/add : ";
			int a = 0;
			cin >> a;
			ifstream file("prizebond.txt", ios::in);
			float p = 0.0f;
			int count = 0;
			bool found = false;
			while (file >> prizebond.id) {
				file >> prizebond.price;


				if (a == prizebond.id) {
					found = true;
					cout << "Item Found" << endl;
					cout << prizebond;
					cout << "Do you want to add this item(y/n): ";
					char ch = '\0';
					cin >> ch;
					if (ch == 'y') {
						system("CLS");
						p = cart.getTotalPrice();
						count = cart.getItemCount();

						p = p + prizebond.price;
						count++;
						cart.setTotalPrice(p);
						cart.setItemCount(count);

						cout << "Item added to cart\n";
						cart.disp();


					}
					if (ch == 'n') {
						system("CLS");
						goto here;
					}
				}

			}

			if (found == false) {
				cout << "Item not found\n";
			}

			cout << "Enter 1 to continue\n";
			cout << "Enter 2 to go back\n";
			cin >> cho;

			if (cho == 1) {
				cin.ignore();
				system("CLS");
				continue;
			}
			else if (cho == 2) {
				system("CLS");
				goto here;
			}

			file.close();
		}
	}

	
}



void Customer::additems() {

	int choice = 0;
here:
	cout << "\n\t\t\t\t\t\tAdd Items \n";
	cout << "\t\t\t\t\t\t   **********\n";
	cout << "1: Books" << endl;
	cout << "2: Magzines" << endl;
	cout << "3: Newspapers" << endl;
	cout << "4: Stationary" << endl;
	cout << "5: Prize Bonds" << endl;
	cout << "6: Go back\n";
	cout << "Enter your choice: ";
	cin >> choice;
	if (choice == 1)
	{
		system("CLS");
		cout << "                    ***Books***" << endl;
		cin.ignore();
		ifstream file("books.txt", ios::in);
	
		cout << "Id" << "\t\t" << "Name" << "\t\t" << "Author" <<  "\t\t" << "Price" << endl;
		while (file>>book.id) {

			file.ignore();
			getline(file, book.name);
			//file.ignore();

			getline(file, book.author);

			file >> book.price;


			cout << book.id<< "\t\t" << book.name << "\t\t" << book.author<< "\t\t" <<book.price<< endl;
				
				
		}
		file.close();
		int cho = 0;
		while (1) {
			cout << " Enter the name of book to search/add : ";
			string namebook;
			getline(cin, namebook);
			ifstream file("books.txt", ios::in);
			float p = 0.0f;
			int count = 0;
			bool found = false;
			while (file >> book.id) {
				file.ignore();
				getline(file, book.name);
				//file.ignore();
			
				getline(file, book.author);
			
				file >> book.price;



				if (namebook == book.name) {
					found = true;
					cout << "Book found" << endl;
					cout << book;
					cout << "Do you want to add this item(y/n): ";
					char ch = '\0';
					cin >> ch;
					if (ch == 'y') {
				
						p = cart.getTotalPrice();
						count = cart.getItemCount();

						p = p + book.price;
						count++;
						cart.setTotalPrice(p);
						cart.setItemCount(count);

						cout << "Item added to cart\n";
						cart.disp();


					}
					if (ch == 'n') {
						system("CLS");
						goto here;
					}
				}

			}

			if (found == false) {
				cout << "Book not found\n";
			}

			cout << "Enter 1 to continue\n";
			cout << "Enter 2 to go back\n";
			cin >> cho;


			if (cho == 1) {
				cin.ignore();
				continue;
			}
			else if (cho == 2) {
				system("CLS");
				goto here;
			}

			file.close();
		}




	}
	else if (choice == 2) {
		system("CLS");
		cout << "                    ***Magzines***" << endl;
	
		ifstream fin("magzine.txt", ios::in);

		cout << "Id" << "\t\t" << "Name" << "\t\t\t\t" << "Price" << endl;
	
		while (fin>>magzine.id) {
			fin.ignore();
			getline(fin, magzine.name);
			fin>>magzine.price ;

			cout << magzine.id<< "\t\t" << magzine.name<< "\t\t" << magzine.price<< endl;
		}

		int cho = 0;
		cin.ignore();
		while (1) {
			cout << " Enter the name of  Magzine to search/add : ";
			string namebook;
			getline(cin, namebook);
			ifstream file("magzine.txt", ios::in);
			float p = 0.0f;
			int count = 0;
			bool found = false;
			while (file >> magzine.id) {
				file.ignore();
				getline(file, magzine.name);
				file >> magzine.price;


				if (namebook == magzine.name) {
					found = true;
					cout << "Magzine found" << endl;
					cout << magzine;
					cout << "Do you want to add this item(y/n): ";
					char ch = '\0';
					cin >> ch;
					if (ch == 'y') {
						system("CLS");
						p = cart.getTotalPrice();
						count = cart.getItemCount();

						p = p + magzine.price;
						count++;
						cart.setTotalPrice(p);
						cart.setItemCount(count);

						cout << "Item added to cart\n";
						cart.disp();


					}
					if (ch == 'n') {
						system("CLS");
						goto here;
					}
				}

			}

			if (found == false) {
				cout << "Magzine not found\n";
			}

			cout << "Enter 1 to continue\n";
			cout << "Enter 2 to Go back\n";
			cin >> cho;

			if (cho == 1) {
				cin.ignore();
				system("CLS");
				continue;
			}
			else if (cho == 2) {
				system("CLS");
				goto here;
			}

			file.close();
		}
		

	}

	if (choice == 3) {
		system("CLS");
		cout << "                    ***NewsPapers***" << endl;
		//cin.ignore();
		ifstream fin("newspaper.txt", ios::in);

		cout << "Name" << "\t\t\t\t" << "Price" << endl;

		while (getline(fin,newspaper.name)) {
			fin >>newspaper.price;
			fin.ignore();

			cout <<  newspaper.name << "\t\t" << newspaper.price << endl;
		}

		fin.close();
		int cho = 0;
		cin.ignore();
		while (1) {
			cout << " Enter the name of  newspaper to search/add : ";
			string namebook;
			getline(cin, namebook);
			ifstream file("newspaper.txt", ios::in);
			float p = 0.0f;
			int count = 0;
			bool found = false;
			while (getline(file,newspaper.name)) {
				file >> newspaper.price;
				file.ignore();


				if (namebook == newspaper.name) {
					found = true;
					cout << "Newspaper found" << endl;
					cout << newspaper;
					cout << "Do you want to add this item(y/n): ";
					char ch = '\0';
					cin >> ch;
					if (ch == 'y') {
						
						p = cart.getTotalPrice();
						count = cart.getItemCount();

						p = p + newspaper.price;
						count++;
						cart.setTotalPrice(p);
						cart.setItemCount(count);

						cout << "Item added to cart\n";
						cart.disp();


					}
					if (ch == 'n') {
						system("CLS");
						goto here;
					}
				}

			}

			if (found == false) {
				cout << "Newspaper not found\n";
			}

			cout << "Enter 1 to continue\n";
			cout << "Enter 2 to go back \n";
			cin >> cho;

			if (cho == 1) {
				cin.ignore();
				continue;
			}
			else if (cho == 2) {
				system("CLS");
				goto here;
			}

			file.close();
		}




	}

	if (choice == 4) {
		system("CLS");
		cout << "                    ***Stationary***" << endl;
		//cin.ignore();
		ifstream fin("stationary.txt", ios::in);

		cout << "Id" << "\t\t" << "Name" << "\t\t\t\t" << "Price" << endl;

		while (fin >> stationary.id) {
			fin.ignore();
			getline(fin, stationary.name);
			fin >> stationary.price;

			cout << stationary.id << "\t\t" << stationary.name << "\t\t\t" << stationary.price << endl;
		}

		fin.close();
		int cho = 0;
		cin.ignore();
		while (1) {
			cout << " Enter the name of  item to search/add : ";
			string namebook;
			getline(cin, namebook);
			ifstream file("stationary.txt", ios::in);
			float p = 0.0f;
			int count = 0;
			bool found = false;
			while (file >> stationary.id) {
				file.ignore();
				getline(file, stationary.name);
				file >> stationary.price;


				if (namebook == stationary.name) {
					found = true;
					cout << "Item found" << endl;
					cout << stationary;
					cout << "Do you want to add this item(y/n): ";
					char ch = '\0';
					cin >> ch;
					if (ch == 'y') {
					
						p = cart.getTotalPrice();
						count = cart.getItemCount();

						p = p + stationary.price;
						count++;
						cart.setTotalPrice(p);
						cart.setItemCount(count);

						cout << "Item added to cart\n";
						cart.disp();


					}
					if (ch == 'n') {
						system("CLS");
						goto here;
					}
				}

			}

			if (found == false) {
				cout << "Item not found\n";
			}

			cout << "Enter 1 to continue\n";
			cout << "Enter 2 to go back\n";
			cin >> cho;

			if (cho == 1) {
				cin.ignore();
				continue;
			}
			else if (cho == 2) {
				system("CLS");
				goto here;
			}

			file.close();
		}






	}

	if (choice == 5) {
		system("CLS");
		cout << "                    ***Prize Bonds***" << endl;
		//cin.ignore();
		ifstream fin("prizebond.txt", ios::in);

		cout << "Id" << "\t\t" << "Price" << endl;

		while (fin >> prizebond.id) {
			fin >> prizebond.price;

			cout << prizebond.id << "\t\t" << prizebond.price << endl;
		}

		fin.close();
		int cho = 0;
		while (1) {
			cout << " Enter the Id of  Prize bond to search/add : ";
			int a = 0;
			cin >> a;
			ifstream file("prizebond.txt", ios::in);
			float p = 0.0f;
			int count = 0;
			bool found = false;
			while (file >> prizebond.id) {
				file >> prizebond.price;


				if (a == prizebond.id) {
					found = true;
					cout << "Item Found" << endl;
					cout << prizebond;
					cout << "Do you want to add this item(y/n): ";
					char ch = '\0';
					cin >> ch;
					if (ch == 'y') {
		
						p = cart.getTotalPrice();
						count = cart.getItemCount();

						p = p + prizebond.price;
						count++;
						cart.setTotalPrice(p);
						cart.setItemCount(count);

						cout << "Item added to cart\n";
						cart.disp();


					}
					if (ch == 'n') {
						system("CLS");
						goto here;
					}
				}

			}

			if (found == false) {
				cout << "Item not found\n";
			}

			cout << "Enter 1 to continue\n";
			cout << "Enter 2 to go back\n";
			cin >> cho;

			if (cho == 1) {
				continue;
			}
			else if (cho == 2) {
				system("CLS");
				goto here;
			}

			file.close();
		}



	}

	if (choice == 6) {
		
	}



	
}

bool Customer::payment() {
	cout << "\n\t\t\t\t\t\tPayment \n";
	cout << "\t\t\t\t\t\t   *********\n";
	string cname;
	cout << "Enter your card name: ";
	getline(cin, cname);
	p.setCustomerId(id);
	p.setCustomerName(name);
	p.setCardName(cname);
	p.setAmount(cart.getTotalPrice());

	p.disp();
	return true;
}

void Customer::dispCart() {
	cart.disp();
}

Customer::~Customer() {

}