#pragma once
#include<iostream>
using namespace std;

class Stationary {
public:
	int id;
	string name;
	float price;
public:
	Stationary();
    Stationary(int id, string name, float price);

	void setId(int id);
	void setName(string name);
	void setPrice();

	int getId();
	string getName();
	float getPrice();
	~Stationary();

	friend istream& operator>>(istream& in, Stationary& obj);
	friend ostream& operator<<(ostream& out, Stationary& obj);







};

