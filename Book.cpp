#include"Book.h"
#include<iostream>
using namespace std;


Book::Book() {
	id = 0;
	name = { '\0' };
	author = { '\0' };
	price = 0.0f;
}
Book::Book(int id, string name, string author, float price) {
	this->id = id;
	this->name = name;
	this->author = author;
	this->price = price;
}
void Book::setId(int id) {
	this->id = id;
	
}
void Book::setName(string name) {
	this->name = name;
}
void Book::setAuthor(string author) {
	this->author = author;
}
void Book::setPrice(float price) {
	this->price = price;
}

int Book::getId() {
	return id;
}
string Book::getName() {
	return name;
}
string Book::getAuthor() {
	return author;
}
float Book::getPrice() {
	return price;
}

Book::~Book() {

}