#ifndef PRODUCER_C					
#define PRODUCER_C

#include "product.cpp"
#include <pthread.h>

class Producer{
public:
	string producer_name;
	string product_name;
	Product *product;
	vector<Product> products;
	Producer(string producer_name, string product_name){
		this->producer_name = producer_name;
		this->product_name = product_name;
		this->product = NULL;
	}

	string getName(){
		return this->producer_name;
	}

	Product *produce(){
		Product *aux = new Product(this->product_name);
		this->products.push_back(*aux);
		return aux;
	}	
};

#endif