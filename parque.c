#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>			
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

time_t tempoAtual, tempoFim; 
int numLugares;


void *controlador(void *arg)
{
	int fd;
	char * fifo = "fifo";
	strcat(fifo,arg[0]);
	mkfifo(fifo,0660);
	fd = open(fifo,O_RDONLY);
	while(tempoAtual < tempoFim)
		{
			tempoAtual = time();
		}
}

int main(int argc,char** argv){
	if(argc!=3){
		prinf("usage: parque <N_LUGARES> <T_ABERTURA>");
		exit(1);
	}
	tempoAtual = time();
	tempoFim = time() + argv[2];
	numLugares = argv[1];
	pthread_t tidN, tidE, tidO, tidS;
	pthread_create(&tidN, NULL,controlador,"N");
	pthread_create(&itdE, NULL,controlador,"E");
	pthread_create(&tidO, NULL,controlador,"O");
	pthread_create(&itdS, NULL,controlador,"S");

 

}