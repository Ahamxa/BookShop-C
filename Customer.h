#pragma once
#include<iostream>
#include"Book.h"
#include"Magzines.h"
#include"Cart.h"
#include"Payment.h"
#include"Newspaper.h"
#include"Stationary.h"
#include"Prizebond.h"
using namespace std;

class Customer {

	int id;
	string name;
	string password;
	string email;
	Cart cart;
	Payment p;


	

public:
	Book book;
	Magzines magzine;
	Newspaper newspaper;
	Stationary stationary;
	Prizebond prizebond;

	Customer();
	void setId(int id);
	void setName(string name);
	void setPassword(string password);
	void setEmail(string email);
	void setCart(Cart cart);

	int getId();
	string getName();
	string getEmail();
	Cart getCart();
	//Payment getPayment();
	bool registration();
	bool login();
    void search();
	void additems();
	void dispCart();
	bool payment();
	

	~Customer();













};
