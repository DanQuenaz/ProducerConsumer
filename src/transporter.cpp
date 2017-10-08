#ifndef TRANSPORTER_C					
#define TRANSPORTER_C

#include "product.cpp"
#include <pthread.h>

class Transporter{
public:
	string transporter_name;
	Product *product;

	vector<Product> products;
	Transporter(string name){
		this->transporter_name = name;
		this->product = NULL;
	}

	string getName(){
		return this->transporter_name;
	}

	void load(Product *product){
		this->product = product;
		this->products.push_back(*product);
	}
	Product* unload(){
		return this->product;
	}
	

};

#endif