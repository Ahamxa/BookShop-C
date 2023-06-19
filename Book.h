#pragma once
#include<iostream>
using namespace std;

class Book {
public:
	int id;
	string name;
	string author;
	float price;
public:
	Book();
	Book(int id, string name, string author, float price);
	void setId(int id);
	void setName(string name);
	void setAuthor(string author);
	void setPrice(float price);

	int getId();
	string getName();
	string getAuthor();
	float getPrice();

	friend istream& operator>>(istream& in, Book& obj);
	friend ostream& operator<<(ostream& out, Book& obj);
	~Book();








};