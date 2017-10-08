#include <vector>
#include <pthread.h>

#include "producer.cpp"
#include "consumer.cpp"
#include "product.cpp"
#include "transporter.cpp"


using namespace std;

class Buffer{
public:
	vector<Product *> buffer;
	int N_MAX;
	int full;
	pthread_mutex_t mutex;
	string buffer_name;

	Buffer(int N_MAX, string name){
		this->full=0;
		this->N_MAX = N_MAX;
		this->buffer_name = name;
	}

	int getNmax(){
		return this->N_MAX;
	}

	void insert(Product *product, Producer *prod, pthread_cond_t &cond1, pthread_cond_t &cond2){
		pthread_mutex_lock(&mutex);
		while(this->full == this->N_MAX){
			pthread_cond_wait(&cond1, &mutex);
		}
		this->buffer.insert(this->buffer.begin()+this->full, product);
		this->full++;
		cout<<prod->producer_name<<" produziu: "<< product->getName()<<endl;
		if(this->full <= 1) pthread_cond_signal(&cond2);
		pthread_mutex_unlock(&mutex);
	}

	void insert(Product *product, Transporter *transp, pthread_cond_t &cond1, pthread_cond_t &cond2){
		pthread_mutex_lock(&mutex);
		while(this->full == this->N_MAX){
			pthread_cond_wait(&cond1, &mutex);
		}
		this->buffer.insert(this->buffer.begin()+this->full, product);
		this->full++;
		cout<<transp->transporter_name<<" transportou: "<<product->getName()<<endl;
		if(this->full <= 1) pthread_cond_signal(&cond2);
		pthread_mutex_unlock(&mutex);
	}

	Product* withdraw(pthread_cond_t &cond1, pthread_cond_t &cond2){
		pthread_mutex_lock(&mutex);
		while(this->full == 0){
			pthread_cond_wait(&cond1, &mutex);
		}
		if(this->full == this->N_MAX) pthread_cond_signal(&cond2);
		pthread_mutex_unlock(&mutex);
		return this->buffer[--full];
	}

	Product* withdraw(Consumer *cons, pthread_cond_t &cond1, pthread_cond_t &cond2){
		pthread_mutex_lock(&mutex);
		while(this->full == 0){
			pthread_cond_wait(&cond1, &mutex);
		}
		cout<<cons->consumer_name<<" consumiu: "<<this->buffer[full-1]->getName()<<endl;
		if(this->full == this->N_MAX) pthread_cond_signal(&cond2);
		pthread_mutex_unlock(&mutex);
		return this->buffer[--full];
	}
	
};