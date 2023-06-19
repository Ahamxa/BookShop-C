

#include"Book.h"
#include"Magzines.h"
#include"Newspaper.h"
#include"Stationary.h"
#include<iostream>
#include<fstream>
#include <string>
#include<cstring>
#include"admin.h"
using namespace std;

   Admin:: Admin()
    {
        username = {'\0'};
        pin = 0;
    }

      Admin* Admin::getInstance()
    {
        if (obj == NULL)
        {
            obj = new Admin();
        }

        return obj;
    }
    void Admin::setUsername(string username)
    {
        this->username = username;
    }
    void Admin::setPin(int pin)
    {
        this->pin = pin;
    }

    bool Admin::registration() {
        system("CLS");
        cout << " \n\t\t\t\t\t\t   Make new admin\n";
        cout << "\t\t\t\t\t\t *******************\n";
        string un = { '\0' };
        int pin = 0;
        int pin1 = 0;
        bool found = false;
        cout << "Enter current pin: ";
        cin >> pin1;
        ifstream fin("admin.txt");
        if (fin.is_open()) {
            fin >> un;
            fin >> pin;
            if (pin1 == pin) {
                found = true;
                cout << "Pin matched\n";
            }

        }
        if (found == true) {
            un = { '\0' };
            pin = 0;
            pin1 = 0;
            found = false;
            cout << "Enter a username for new admin: ";

            cin >> un;
            cout << "Enter a pin for new admin: ";
            cin >> pin;
            cout << "Enter pin again for confirmation : ";
            cin >> pin1;
            while (pin != pin1) {
                cerr << "Pin does not match!\n";
                cout << "Enter a pin for new admin: ";
                cin >> pin;
                cout << "Enter pin again for confirmation : ";
                cin >> pin1;
            }

            if (pin == pin1) {
                ofstream out("admin.txt");
                if (out.is_open()) {
                    out << un << endl;
                    out << pin;
                    cout << "New admin registered\n";
                    found = true;
                }

            }
        }

        return found;
     
    }
    bool Admin::login() {
        system("CLS");
        cout << " \n\t\t\t\t\t\t  Login as admin\n";
        cout << "\t\t\t\t\t\t *******************\n";
        string un = { '\0' };
        int pi = 0;
        bool found = false;
        cout << "Enter  username for  admin: ";
        cin >> un;
        cout << "Enter  pin for admin: ";
        cin >> pi;
        ifstream fin("admin.txt");
        if (fin.is_open()) {
         
            fin >> username;
            fin >> pin;
            while (un != username && pin != pi) {
                cerr << "Wrong pin or username entered!\n";
                cout << "Enter  username for  admin: ";
                cin >> un;
                cout << "Enter  pin for admin: ";
                cin >> pi;
            }
            if (un == username && pin == pi) {

                cout << "Login sucessfull\n";
                system("pause");
                found = true;
       
            }
           
        }
        fin.close();
        if (found == true) {
            system("CLS");
            int c = 0;
        here:
            cout << "\n\t\t\t\t\t\t Welcome to admin portal\n";
            cout << "\t\t\t\t\t\t ****************************\n";
            cout << "Enter 1 for show items\n";
            cout << "Enter 2 for add new items\n";
            cout << "Enter 3 for delete items\n";
            cout << "Enter 4 for  logout\n";
            cout << "Enter your choice: ";
            cin >> c;

            if (c == 1) {
                showitems();
                system("CLS");
                goto here;
            }
            if (c == 2) {
                addnewitems();
                system("CLS");
                goto here;
            }
            if (c == 3) {
                deleteitems();
                system("CLS");
                goto here;
            }
            if (c == 4) {
                return 0;
            }
        }

        return found;


    }
    void Admin::showitems() {
    here:
        system("CLS");
        cout << " \n\t\t\t\t\t\t  Show Items\n";
        cout << "\t\t\t\t\t\t ************\n";
        int c = 0;
        cout << "1: Books" << endl;
        cout << "2: Magzines" << endl;
        cout << "3: Newspapers" << endl;
        cout << "4: Stationary" << endl;
        cout << "5: Prize Bonds" << endl;
        cout << "6: Go back" << endl;
        cout << "Enter your choice: ";
        cin >> c;
        if (c == 1) {

            cout << "                    ***Books***" << endl;
            cin.ignore();
            ifstream file("books.txt", ios::in);

            cout << "Id" << "\t\t" << "Name" << "\t\t" << "Author" << "\t\t" << "Price" << endl;
            while (file >> book.id) {
                file.ignore();
                getline(file, book.name);
                getline(file, book.author);
                file >> book.price;


                cout << book.id << "\t\t" << book.name << "\t\t" << book.author << "\t\t" << book.price << endl;


            }
            file.close();
            system("pause");
            goto here;
        }

        if (c == 2) {
           
            cout << "                    ***Magzines***" << endl;
            cin.ignore();
            ifstream file("magzine.txt", ios::in);

            cout << "Id" << "\t\t" << "Name" << "\t\t" << "Price" << endl;
            while (file >> magzine.id) {
                file.ignore();
                getline(file, magzine.name);
                file >> magzine.price;
                cout << magzine.id << "\t\t" << magzine.name << "\t\t" << magzine.price << endl;

            }
            file.close();
            system("pause");
            goto here;
        }
        if (c == 3) {
            cout << "                    ***Newspaper***" << endl;
            cin.ignore();
            ifstream file("newspaper.txt", ios::in);

            cout << "Name" << "\t\t\t" << "Price" << endl;
            while (getline(file,newspaper.name)) {
                file >> newspaper.price;
                file.ignore();
                cout << newspaper.name << "\t\t\t" << newspaper.price << endl;

            }
            file.close();
            system("pause");
            goto here;

        }
        if (c == 4) {
            cout << "                    ***Stationary***" << endl;
            cin.ignore();
            ifstream file("stationary.txt", ios::in);

            cout << "Id" << "\t\t" << "Name" << "\t\t" << "Price" << endl;
            while (file >> stationary.id) {
                file.ignore();
                getline(file, stationary.name);

                file >> stationary.price;


                cout << stationary.id << "\t\t" << stationary.name << "\t\t" << "\t\t" << stationary.price << endl;


            }
            file.close();
            system("pause");
            goto here;
        }
        if (c == 5) {
            cout << "                    ***Prize Bonds***" << endl;
            cin.ignore();
            ifstream file("prizebond.txt", ios::in);

            cout << "Id" << "\t\t" << "Price" << endl;
            while (file >> prizebond.id) {

                file >> prizebond.price;


                cout << prizebond.id << "\t\t" << prizebond.price << endl;


            }
            file.close();
            system("pause");
            goto here;
            
        }
        if (c == 6) {
           
        }

    }

    void Admin::addnewitems() {
    here:
        system("CLS");
        cout << " \n\t\t\t\t\t\t  AddItems\n";
        cout << "\t\t\t\t\t\t **********\n";
        int c = 0;
        cout << "1: Books" << endl;
        cout << "2: Magzines" << endl;
        cout << "3: Newspapers" << endl;
        cout << "4: Stationary" << endl;
        cout << "5: Prize Bonds" << endl;
        cout << "6: Go back" << endl;
        cout << "Enter your choice: ";
        cin >> c;

        if (c == 1) {
          
            cout << "                    ***Add Books***" << endl;
            cin.ignore();
           
            int cho = 0;
            system("CLS");
            while (1) {
                int i = 0;
                string bn = { '\0' };
                string an = { '\0' };
                float p = 0.0f;
                bool found = false;
                cout << " Enter the id  for new book to add : ";
         
                cin >> i;
                cin.ignore();
                cout << "Enter the name for the new book to add: ";
                getline(cin, bn);
                cout << "Enter the Author name for the new book to add: ";
                getline(cin, an);
                cout << "Enter the price for new book to add: ";
                cin >> p;
                ofstream fout("books.txt", ios::app);
                if (fout.is_open()) {

                    fout << i << endl;
                    fout << bn << endl;
                    fout << an << endl;
                    fout << p <<endl;
                    found =true;
                    cout << "item added\n";
                    fout.close();
                }
             
             

                cout << "Enter 1 to continue or 2 to go back: ";
                cin >> cho;
                if (cho == 1) {
                    cin.ignore();
                    continue;
                }
                else if (cho == 2) {
                    system("CLS");
                    goto here;
                }

                
            }




        }
        if (c == 2) {

            cout << "                    ***Magzines***" << endl;
            cin.ignore();
           
            int cho = 0;
            system("CLS");
            while (1) {
                int i = 0;
                string mn = { '\0' };
       
                float p = 0.0f;
                bool found = false;
                cout << " Enter the id  for new magzine to add : ";

                cin >> i;
                cin.ignore();
                cout << "Enter the name for the new magzine to add: ";
                getline(cin, mn);
   
                cout << "Enter the price for new magzine to add: ";
                cin >> p;
                ofstream fout("magzine.txt", ios::app);
                if (fout.is_open()) {

                    fout << i << endl;
                    fout << mn << endl;
                    fout << p <<endl;
                  
                    found = true;
                    cout << "item added\n";
                    fout.close();
                }
            

                cout << "Enter 1 to continue or 2 to go back: ";
                cin >> cho;
                if (cho == 1) {
                    cin.ignore();
                    continue;
                }
                else if (cho == 2) {
                    system("CLS");
                    goto here;
        
                }


            }

        }
        if (c == 3) {
            cout << "                    ***Newspaper***" << endl;
            cin.ignore();
            
            int cho = 0;
            system("CLS");
            while (1) {
                string n = { '\0' };
                
                float p = 0.0f;
                bool found = false;
               
                cout << "Enter the name for the newspaper to add: ";
                cin.ignore();
                getline(cin, n);
                cout << "Enter the price for new newspaper to add: ";
                cin >> p;
                ofstream fout("newspaper.txt", ios::app);
                if (fout.is_open()) {
                    fout << n << endl;
                    fout << p <<endl;
                    found = true;
                    cout << "item added\n";
                    fout.close();
                }
            

                cout << "Enter 1 to continue or 2 to go back: ";
                cin >> cho;
                if (cho == 1) {
                    cin.ignore();
                    continue;
                }
                else if (cho == 2) {
                    system("CLS");
                    goto here;
                }


            }
        }
        if (c == 4) {
            cout << "                    ***Stationary***" << endl;
            cin.ignore();
           
            int cho = 0;
            system("CLS");
            while (1) {
                int i = 0;
                string n = { '\0' };
                float p = 0.0f;
                bool found = false;
                cout << " Enter the id  for new item to add :  ";

                cin >> i;
                cin.ignore();
                cout << "Enter the name for the new item to add:  ";
                getline(cin, n);
            
                cout << "Enter the price for new item to add:  ";
                cin >> p;
                ofstream fout("stationary.txt", ios::app);
                if (fout.is_open()) {

                    fout<< i << endl;
                    fout << n << endl;
                    fout << p<<endl;
                    found = true;
                    cout << "item added\n";
                    fout.close();
                }



                cout << "Enter 1 to continue or 2 to go back: ";
                cin >> cho;
                if (cho == 1) {
                    cin.ignore();
                    continue;
                }
                else if (cho == 2) {
                    system("CLS");
                    goto here;
                }


            }

        }
        if (c == 5) {
            cout << "                    ***Prize Bonds***" << endl;
            cin.ignore();
            ifstream file("prizebond.txt", ios::in);

            cout << "Id" << "\t\t" << "Price" << endl;
            while (file >> prizebond.id) {

                file >> prizebond.price;


                cout << prizebond.id << "\t\t"  << prizebond.price << endl;


            }
            file.close();
            int cho = 0;
            system("CLS");
            while (1) {
                int i = 0;
            
                float p = 0.0f;
                bool found = false;
                cout << " Enter the id  for new item to add : ";
                cin >> i;
                cout << "Enter the price for new item to add: ";
                cin >> p;
                ofstream fout("prizebond.txt", ios::app);
                if (fout.is_open()) {

                    fout << i << endl;
                    fout << p <<endl;
                    found = true;
                    cout << "item added\n";
                    fout.close();
                }
              

                cout << "Enter 1 to continue or 2 to go back: ";
                cin >> cho;
                if (cho == 1) {
                    continue;
                }
                else if (cho == 2) {
                    system("CLS");
                    goto here;
                }


            }
        }
        if (c == 6) {


        }

    }
    
    void Admin::deleteitems() {
        system("CLS");
        cout << " \n\t\t\t\t\t\t  Delete Items\n";
        cout << "\t\t\t\t\t\t **********\n";
        int c = 0;
    here:
        cout << "1: Books" << endl;
        cout << "2: Magzines" << endl;
        cout << "3: Newspapers" << endl;
        cout << "4: Stationary" << endl;
        cout << "5: Prize Bonds" << endl;
        cout << "6: Go back" << endl;
        cout << "Enter your choice: ";
        cin >> c;
        if (c == 1) {

            cout << "                    ***Books***" << endl;
            cin.ignore();
            ifstream file("books.txt", ios::in);

            cout << "Id" << "\t\t" << "Name" << "\t\t" << "Author" << "\t\t" << "Price" << endl;
            while (file >> book.id) {
                file.ignore();
                getline(file, book.name);
                getline(file, book.author);
                file >> book.price;


                cout << book.id << "\t\t" << book.name << "\t\t" << book.author << "\t\t" << book.price << endl;


            }
            file.close();
            int cho = 0;
           
            while (1) {
                int i = 0;
                bool found = false;
                cout << " Enter the id of book to delete : ";
                cin >> i;
             
                ifstream fin;
                ofstream temp;
                fin.open("books.txt",ios::in);
                temp.open("temp.txt",ios::app);
                while (fin >> book.id) {
                    fin.ignore();
                    getline(fin, book.name);
                    getline(fin, book.author);
                    fin >> book.price;
                    if (i!= book.id) {
                        temp << book.id << endl;
                        temp << book.name << endl;
                        temp << book.author << endl;
                        temp << book.price << endl;
                    }

                }


                cout << "The record with the id" << i << " has been deleted if it exsisted" << endl;
                fin.close();
                temp.close();
                remove("books.txt");
                rename("temp.txt", "books.txt");
                found = true;
                cout << "Enter 1 to continue or 2 to go back: ";
                cin >> cho;
                if (cho == 1) {
                    continue;
                }
                else if (cho == 2) {
                    system("CLS");
                    goto here;
                }


            }

        }

        if (c == 2) {

            cout << "                    ***Magzines***" << endl;
            cin.ignore();
            ifstream file("magzine.txt", ios::in);

            cout << "Id" << "\t\t" << "Name" << "\t\t" << "Price" << endl;
            while (file >> magzine.id) {
                file.ignore();
                getline(file, magzine.name);
                file >> magzine.price;
                cout << magzine.id << "\t\t" << magzine.name << "\t\t" << magzine.price << endl;

            }
            file.close();
            int cho = 0;
           
            while (1) {
                int i = 0;
                bool found = false;
                cout << " Enter the id  of magzine to delete : ";
                cin >> i;

                ifstream fin;
                ofstream temp;
                fin.open("magzine.txt", ios::in);
                temp.open("temp.txt", ios::app);
                while (fin >> magzine.id) {
                    fin.ignore();
                    getline(fin, magzine.name);
                    fin >> magzine.price;
                    if (i != magzine.id) {
                        temp << magzine.id << endl;
                        temp << magzine.name << endl;
                        temp << magzine.price << endl;
                    }

                }


                cout << "The record with the id" << i << " has been deleted if it exsisted" << endl;
                fin.close();
                temp.close();
                remove("magzine.txt");
                rename("temp.txt", "magzine.txt");

                cout << "Enter 1 to continue or 2 to go back: ";
                cin >> cho;
                if (cho == 1) {
                    continue;
                }
                else if (cho == 2) {
                    system("CLS");
                    goto here;
                }


            }






        }
        if (c == 3) {
            cout << "                    ***Newspaper***" << endl;
            cin.ignore();
            ifstream file("newspaper.txt", ios::in);

            cout << "Name" << "\t\t\t" << "Price" << endl;
            while (getline(file,newspaper.name)) {
                file >> newspaper.price;
                file.ignore();
                cout << newspaper.name << "\t\t\t" << newspaper.price << endl;

            }
            file.close();
            int cho = 0;
           
            while (1) {
                string n = { '\0' };
                bool found = false;
                cout << " Enter the name of  item to delete : ";
                getline(cin, n);

                ifstream fin;
                ofstream temp;
                fin.open("newspaper.txt", ios::in);
                temp.open("temp.txt", ios::app);
                while (getline(fin,newspaper.name) ){
 
                    fin >> newspaper.price;
                    fin.ignore();
                    if (n != newspaper.name) {
                        temp << newspaper.name << endl;
                        temp << newspaper.price << endl;
                    }

                }


                cout << "The record with the name " << n << "  has been deleted if it exsisted" << endl;
                fin.close();
                temp.close();
                remove("newspaper.txt");
                rename("temp.txt", "newspaper.txt");

                cout << "Enter 1 to continue or 2 to go back: ";
                cin >> cho;
                if (cho == 1) {
                    cin.ignore();
                    continue;
                }
                else if (cho == 2) {
                    system("CLS");
                    goto here;
                }


            }

        }
        if (c == 4) {
            cout << "                    ***Stationary***" << endl;
            cin.ignore();
            ifstream file("stationary.txt", ios::in);

            cout << "Id" << "\t\t" << "Name" << "\t\t" << "Price" << endl;
            while (file >> stationary.id) {
                file.ignore();
                getline(file, stationary.name);
                file >> stationary.price;
                cout << stationary.id << "\t\t" << stationary.name << "\t\t" << "\t\t" << stationary.price << endl;
            }
            file.close();
            int cho = 0;
           
            while (1) {
                int i = 0;
                bool found = false;
                cout << " Enter the id  of  item to delete : ";
                cin >> i;

                ifstream fin;
                ofstream temp;
                fin.open("stationary.txt", ios::in);
                temp.open("temp.txt", ios::app);
                while (fin >> stationary.id) {
                    fin.ignore();
                    getline(fin, stationary.name);
                    fin >> stationary.price;
                    if (i != stationary.id) {
                        temp << stationary.id << endl;
                        temp << stationary.name << endl;
                        temp << stationary.price << endl;
                    }

                }


                cout << "The record with the id " << i << "  has been deleted if it exsisted" << endl;
                fin.close();
                temp.close();
                remove("stationary.txt");
                rename("temp.txt", "stationary.txt");

                cout << "Enter 1 to continue or 2 to go back: ";
                cin >> cho;
                if (cho == 1) {
                    continue;
                }
                else if (cho == 2) {
                    system("CLS");
                    goto here;
                }


            }
        }
        if (c == 5) {
            cout << "                    ***Prize Bonds***" << endl;
            cin.ignore();
            ifstream file("prizebond.txt", ios::in);

            cout << "Id" << "\t\t" << "Price" << endl;
            while (file >> prizebond.id) {

                file >> prizebond.price;
                cout << prizebond.id << "\t\t" << prizebond.price << endl;
            }
            file.close();
            int cho = 0;
           
            while (1) {
                int i = 0;
                bool found = false;
                cout << " Enter the id of  item to delete : ";
                cin >> i;

                ifstream fin;
                ofstream temp;
                fin.open("prizebond.txt", ios::in);
                temp.open("temp.txt", ios::app);
                while (fin >> prizebond.id) {

                    fin >> prizebond.price;
                    if (i!=prizebond.id) {
                        temp << prizebond.id << endl;
                        temp << prizebond.price<< endl;
                    }

                }


                cout << "The record with the id " << i<< "  has been deleted if it exsisted" << endl;
                fin.close();
                temp.close();
                remove("prizebond.txt");
                rename("temp.txt", "prizebond.txt");

                cout << "Enter 1 to continue or 2 to go back: ";
                cin >> cho;
                if (cho == 1) {
                    continue;
                }
                else if (cho == 2) {
                    system("CLS");
                    goto here;
                }


            }
        }
        if (c == 6) {

        }

    }

  
    Admin* Admin::obj = NULL;

