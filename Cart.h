#pragma once
#include<iostream>
using namespace std;

class Cart {

	int id;
    int itemCount;
	float totalPrice;
public:
	Cart();
	Cart(int id,int itemCount,float totalPrice);
	void setId(int id);
	void setItemCount(int itemCount);
	int getItemCount();
	int getId();
	void setTotalPrice(float totalPrice);

	float getTotalPrice();
	void disp();
	~Cart();




};
