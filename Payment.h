#pragma once
#include<iostream>
using namespace std;

class Payment {

	int  customerId;
	string customerName;
	string cardName;
	float amount;

public:
	Payment();
	Payment(int customerId, string customerName, string cardName, float amount);
	void setCustomerId(int customerId);
	void setCustomerName(string customerName);
	void setCardName(string cardName);
	void setAmount(float amount);

	int getCustomerId();
	string getCustomerName();
	string getCardName();
	float getAmount();

	void disp();
	~Payment();

};