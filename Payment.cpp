#include"Payment.h"
#include<iostream>
using namespace std;

Payment::Payment() {
	customerId = 0;
	customerName = { '\0' };
	cardName = { '\0' };
	amount = 0.0f;
}
Payment::Payment(int customerId, string customerName, string cardName, float amount) {
	this->customerId = customerId;
	this->customerName = customerName;
	this->cardName = cardName;
	this->amount = amount;
}
void Payment::setCustomerId(int customerId) {
	this->customerId = customerId;
}
void Payment::setCustomerName(string customerName) {
	this->customerName = customerName;
}
void Payment::setCardName(string cardName) {
	this->cardName = cardName;
}
void Payment::setAmount(float amount) {
	this->amount = amount;

}

int Payment::getCustomerId() {
	return customerId;
}
string Payment::getCustomerName() {
	return customerName;
}
string Payment::getCardName() {
	return cardName;
}
float Payment::getAmount() {
	return amount;
}

void Payment::disp() {
	cout << "                     ***Payment Sucessfull***" << endl;
	cout << "Customer  ID: " << customerId << endl;
	cout << "Customer Name: " << customerName << endl;
	cout << "Card name: " << cardName << endl;
	cout << "Amount paid: " << amount << endl;


}
Payment::~Payment() {

}