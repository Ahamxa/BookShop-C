#include<iostream>
#include"Newspaper.h"
using namespace std;

Newspaper::Newspaper() {
	name = { '\0' };
	price = 0.0f;
}
Newspaper::Newspaper(string name, float price) {
	this->name = name;
	this->price = price;
}

void Newspaper::setName(string name) {
	this->name = name;

}
void Newspaper::setPrice(float price) {
	this->price = price;
}
string Newspaper::getName() {
	return name;
}
float Newspaper::getPrice() {
	return price;
}

Newspaper::~Newspaper() {

}