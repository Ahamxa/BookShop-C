#pragma once
#include<iostream>
using namespace std;

class Newspaper {
public:
	string name;
	float price;
public:
	Newspaper();
	Newspaper(string name, float price);

	void setName(string name);
	void setPrice(float price);
	string getName();
	float getPrice();

	~Newspaper();

	friend istream& operator>>(istream& in, Newspaper& obj);
	friend ostream& operator<<(ostream& out, Newspaper& obj);





};
