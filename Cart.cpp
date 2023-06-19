#include"Cart.h"
#include<iostream>
using namespace std;

Cart::Cart() {
	itemCount = 0;
	id = 0;
	totalPrice = 0.0f;
}
Cart::Cart(int id,  int itemCount, float totalPrice) {
	this -> itemCount = itemCount;
	this->id = id;
	this->totalPrice = totalPrice;
}

void Cart::setId(int id) {
	this->id = id;
}
void Cart::setTotalPrice(float totalPrice) {
	this->totalPrice = totalPrice;
}
float Cart::getTotalPrice() {
	return totalPrice;
}

void Cart::setItemCount(int itemCount) {
	this->itemCount = itemCount;
}
int Cart::getItemCount() {
	return itemCount;
}
int Cart::getId() {
	return id;
}

void Cart::disp() {
	cout << "                          ***Your Cart***" << endl;
	cout << "Cart id: " << id << endl;
	cout << "Total items: " << itemCount << endl;
	cout << "Total Price: " << totalPrice << endl;
}

Cart::~Cart() {

}