#include <iostream>
#include <thread>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <pthread.h>
#include <unistd.h>
#include <fstream>

#include "data.cpp"

using namespace std;

/************************************
Dan Quenaz Magdyam Silva Pimentel - 27286
Gabriel Campos Cerqueira Oliveira - 27208
Karen Gonçalves Campos - 28880
Reld Uiler Nascimento Benfica - 32076
*************************************/

#define TIME_PROD 5 /*TEMPO PARA PRODUZIR*/
#define TIME_TRANSP 3 /*TEMPO PARA TRANSPORTAR*/
#define TIME_CONS 1 /*TEMPO PARA CONSUMIR*/

const int N_MAX = 100;

pthread_cond_t condp, condt, condc;

void *consumer_function(void *ptr){
	Data *param = (Data*)ptr;
	while(true){
		sleep(TIME_CONS);
		param->cons->consume(param->buffer2->withdraw(param->cons, condc, condt));
	}
	pthread_exit(0);
}

void *transporter_function(void *ptr){
	Data *param = (Data*)ptr;
	while(true){
		param->transp->load(param->buffer1->withdraw(condt, condp));

		sleep(TIME_TRANSP);

		param->buffer2->insert(param->transp->unload(), param->transp, condt, condc);
	}
	pthread_exit(0);
}

void *producer_function(void *ptr){
	Data *param = (Data*)ptr;
	while(true){
		sleep(TIME_PROD);
		param->buffer1->insert(param->prod->produce(), param->prod, condp, condt);
	}
	pthread_exit(0);
}

int main(){
	/*INICIALIZAÇÂO DAS CONDIÇÕES*/
	pthread_cond_init(&condp, 0);
	pthread_cond_init(&condt, 0);
	pthread_cond_init(&condc, 0);

	/*ALOCAÇÃO DOS PRODUTORES, TRANSPORTADORES E CONSUMIDORES*/
	Producer *prod1 = new Producer("Tiago", "Melancia");
	Producer *prod2 = new Producer("Joao", "Uva");
	Producer *prod3 = new Producer("Alice", "Morango");

	Transporter *transp1 = new Transporter("Bino");
	Transporter *transp2 = new Transporter("Pedro");

	Buffer* buf1 = new Buffer(N_MAX, "Manuel");
	Buffer* buf2 = new Buffer(N_MAX, "Ragnar");

	/*ALOCAÇÂO DAS THREADS*/
	pthread_t threadp[50];
	pthread_t threadt[50];
	pthread_t threadc[50];

	const int np = 3; /*QUANTIDADE DE PRODUTORES*/
	const int nt = 2; /*QUANTIDADE DE TRANSPORTADORES*/
	int nc = 5; /*QUANTIDADE DE CONSUMIDORES*/
	
	/*CRIAÇÂO DAS THREADS PARA CADA TIPO*/
	pthread_create(&threadp[0], NULL, producer_function, (void*)(new Data(prod1, buf1)));
	pthread_create(&threadp[1], NULL, producer_function, (void*)(new Data(prod2, buf1)));
	pthread_create(&threadp[2], NULL, producer_function, (void*)(new Data(prod3, buf1)));

	pthread_create(&threadt[0], NULL, transporter_function, (void*)(new Data(transp1, buf1, buf2)));
	pthread_create(&threadt[1], NULL, transporter_function, (void*)(new Data(transp2, buf1, buf2)));

	for(int i=0; i<nc; ++i){
		pthread_create(&threadc[i], NULL, consumer_function, (void*)(new Data(new Consumer("Consumidor"+to_string(i)), buf2)));
	}

	system("clear");
	cout<<"-----SISTEMA DE PRODUTOR CONSUMIDOR-----"<<endl<<endl;
	cout<<"Iniciando..."<<endl;

	/*EXECUÇÃO DAS THREADS*/
	for(int i=0; i<np;++i){
		pthread_join(threadp[i], NULL);
	}

	/*for(int i=0; i<nt;++i){
		pthread_join(threadt[i], NULL);
	}*/
	pthread_join(threadt[1], NULL);
	pthread_join(threadt[0], NULL);

	for(int i=0; i<nc;++i){
		pthread_join(threadc[i], NULL);
	}

	return 0;
}