#include <iostream>
#include<string>
#include"Book.h"
#include"Magzines.h"
#include"Newspaper.h"
#include"Stationary.h"
#include"Prizebond.h"
using namespace std;

class Admin {
private:
    string username;
    int pin;
    
    static Admin* obj;
    Admin();
  
public:
    Book book;
    Magzines magzine;
    Newspaper newspaper;
    Stationary stationary;
    Prizebond prizebond;

    static   Admin* getInstance();
    void setUsername(string username);

    void setPin(int pin);
    bool registration();
    bool login();

    void showitems();
    void addnewitems();
    void deleteitems();
    
   
};




