#ifndef PRODUCT_C					
#define PRODUCT_C

#include <cstring>
#include <vector>

using namespace std;

class Product{
private: 
	string product_name;
	static int N_id;
	int product_id;

public:
	Product(string name){
		this->product_id = N_id++;
		this->product_name = name+"_"+to_string(this->product_id);
	}

	string getName(){
		return this->product_name;
	}

	string getProductName(){
		return this->product_name;
	}

	int getProductId(){
		return this->product_id;
	}
};

int Product::N_id = 0;

#endif