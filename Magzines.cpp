#include<iostream>
#include"Magzines.h"
using namespace std;


Magzines::Magzines() {
	id = 0;
	name = { '\0' };
	price = 0.0f;
}
Magzines::Magzines(int id, string name, float price) {
	this->id = id;
	this->name = name;
	this->price = price;

}

void Magzines::setId(int id) {
	this -> id = id;
}
void Magzines::setName(string name) {
	this->name = name;
}
void Magzines::setPrice() {
	this->price = price;
}

int Magzines::getId() {
	return id;
}
string Magzines::getName() {
	return name;
}
float Magzines::getPrice() {
	return price;
}

Magzines::~Magzines() {

}
