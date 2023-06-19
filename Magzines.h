#pragma once
#include<iostream>
using namespace std;

class Magzines {
public:
	int id;
	string name;
	float price;
public:
	Magzines();
	Magzines(int id, string name, float price);

	void setId(int id);
	void setName(string name);
	void setPrice();

	int getId();
	string getName();
	float getPrice();
	~Magzines();

	friend istream& operator>>(istream& in, Magzines& obj);
	friend ostream& operator<<(ostream& out, Magzines& obj);







};
