#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>			
#include <string.h>
#include <fcntl.h>
#include <unistd.h>


time_t tempoFunc;
time_t unidadeT;
time_t tempoAtual;
int fifoId = 0;

void *viatura(void *arg)
{	
	int fd;
	fifoId++;
	char * viatura = "viatura";
	strcat(viatura,fifoId);
	mkfifo(viatura,0660);	
	char * fifo = "fifo";
	strcat(fifo,arg[0]); //fifoN, fifoS 
	fd = open(fifo,O_WRONLY);
	write(fd,arg[0],sizeof(arg[0])); //ponto entrada arg[0]
	write(fd,arg[1],sizeof(arg[1]));
	write(fd,fifoId,sizeof(fifoId));
	write(fd,fifo,sizeof(fifo));
	fd = open(viatura,O_RDONLY);
	
}

int main(int argc,char** argv){
	if(argc!=3){
		prinf("usage: parque <T_GERACAO> <U_RELOGIO>");
		exit(1);
	}

	tempoAtual = time();
	tempoFunc = argv[1] + time();
	unidadeT = argv[2];
	
	pthread_t tid;
	time_t tempoGerar = time();

	while(tempoAtual < tempoFunc){ 
		
		if(tempoAtual >= tempoGerar)
		{
			rand1 = rand() % 4;
			char porta;
			if(rand1 == 0)
				porta = 'N'; 
			if(rand1 == 1)
				porta = 'E';
			if(rand1 == 2)
				porta = 'O';
			if(rand1 == 3)
				porta = 'S';
		

			time_t tempoEstac; 
			rand2 = rand() % 10 + 1;
			tempoEstac = rand2 * unidadeT;	
			rand3 = rand() % 10 + 1;
			
		
		
		char args[2][250];
		strcpy(args[0],porta);
		strcpy(args[1],tempoEstac);
		pthread_create(&tid,NULL,viatura,args);
		
			if(rand3 >=1 && rand3 <= 5)
			{
				tempoGerar = time();
			}
			if(rand3 >=6 && rand3 <= 8)
			{
				tempoGerar = time() + 1*unidadeT;
			}
			if(rand3 >=9 && rand3 <= 10)
			{
				tempoGerar = time() + 2*unidadeT;
			}
		}

		tempoAtual = time();

	}


}