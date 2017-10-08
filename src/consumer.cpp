#ifndef CONSUMER_C					
#define CONSUMER_C

#include "product.cpp"
#include <pthread.h>

class Consumer{
public:
	string consumer_name;
	Product *product;

	vector<Product> products;
	Consumer(string name){
		this->consumer_name = name;
		this->product = NULL;
	}

	string getName(){
		return this->consumer_name;
	}

	void consume(Product *product){
		this->products.push_back(*product);
		delete this->product;
	}


};

#endif

