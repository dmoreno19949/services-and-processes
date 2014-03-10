#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>
#include <wait.h>


int spawn(char *program, char **arg_list){

	int child_pid = fork();
	if(child_pid!=0){
		return child_pid;
	}
	else{
		printf("\n\nProceso hijo \n\n");

		execvp(program, arg_list);

		fprintf(stderr, "Algo salio mal\n");
		abort();
	}
}



void metodoPapi(){

int numero;
  
 printf("\t1. opcion1\n");
 printf("\t2. opcion2\n");
 printf("\t3. Salir\n");
 printf("Escoja una opcion: ");
 scanf("%i", &numero);

	int child_status;

	char* arg_list[] = {
		"sleep",
		"5",
		NULL
	};

 switch(numero){
 	case 1: spawn("sleep", arg_list);
 			wait(&child_status);
				if(WIFEXITED (child_status))
				printf("El proceso hijo termino normalmente, con el codigo de salida: %d\n",
				WEXITSTATUS(child_status) );


				else
				printf("\n\nEl proceso hijo acabo mal\n");
			
			metodoPapi();
 	break;


 	case 2: spawn("sleep", arg_list);
 			wait(&child_status);
				if(WIFEXITED (child_status))
				printf("El proceso hijo termino normalmente, con el codigo de salida: %d\n",
				WEXITSTATUS(child_status) );

				else
				printf("\nEl proceso hijo acabo mal\n");
			metodoPapi();


 	break;
 	case 3: 
 		printf("hola tio");
	break;
 }

}


int main(int argc, char *argv[]){

	metodoPapi();
 

 return 0;
}

