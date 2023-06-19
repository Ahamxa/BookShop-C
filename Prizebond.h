#pragma once
#include<iostream>
using namespace std;

class Prizebond{
public:
	int id;
	float price;
public:
	Prizebond();
	Prizebond(int id, float price);

	void setId(int id);
	void setPrice(float price);
	int getId();
	float getPrice();

	~Prizebond();

	friend istream& operator>>(istream& in, Prizebond& obj);
	friend ostream& operator<<(ostream& out, Prizebond& obj);





};
