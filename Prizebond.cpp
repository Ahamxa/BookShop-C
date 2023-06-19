#include"Prizebond.h"
#include<iostream>
using namespace std;

Prizebond::Prizebond() {
	id = 0;
	price = 0.0f;
}
Prizebond::Prizebond(int id, float price) {
	this->id = id;
	this->price = price;

}

void Prizebond::setId(int id) {
	this->id = id;

}
void Prizebond::setPrice(float price) {
	this->price = price;
}
int Prizebond::getId() {
	return id;
}
float Prizebond::getPrice() {
	return price;
}

Prizebond::~Prizebond() {

}