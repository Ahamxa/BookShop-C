#include<iostream>
#include"Stationary.h"
using namespace std;


Stationary::Stationary() {
	id = 0;
	name = { '\0' };
	price = 0.0f;
}
Stationary::Stationary(int id, string name, float price) {
	this->id = id;
	this->name = name;
	this->price = price;

}

void Stationary::setId(int id) {
	this->id = id;
}
void Stationary::setName(string name) {
	this->name = name;
}
void Stationary::setPrice() {
	this->price = price;
}

int Stationary::getId() {
	return id;
}
string Stationary::getName() {
	return name;
}
float Stationary::getPrice() {
	return price;
}

Stationary::~Stationary() {

}
