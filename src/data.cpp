#include "producer.cpp"
#include "consumer.cpp"
#include "buffer.cpp"
#include "product.cpp"
#include "transporter.cpp"

class Data{
public:
	Producer *prod;
	Transporter *transp;
	Consumer *cons;
	Buffer *buffer1, *buffer2;

	Data(){;}
	Data(Producer *prod, Buffer *buffer){
		this->cons = NULL;
		this->buffer2 = NULL;
		this->transp = NULL;
		this->prod = prod;
		this->buffer1 = buffer;
	}
	Data(Transporter *transp, Buffer *buffer1, Buffer *buffer2){
		this->cons = NULL;
		this->prod = NULL;
		this->transp = transp;
		this->buffer1 = buffer1;
		this->buffer2 = buffer2;
	}
	Data(Consumer *cons, Buffer *buffer){
		this->prod = NULL;
		this->buffer1 = NULL;
		this->transp = NULL;
		this->cons = cons;
		this->buffer2 = buffer;
	}

};