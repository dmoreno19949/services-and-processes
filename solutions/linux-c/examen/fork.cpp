#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int spawn(char* program,char** arg_list_PROG, char** arg_list){
	pid_t child_pid;

	printf("the main program process ID %d\n", (int) getpid ());

	child_pid = fork();

	if(child_pid != 0){
		printf("------------------------\n");
		printf("Soy el proceso padre con id %d\n", (int) getpid());
		execvp(program, arg_list_PROG);
	}else{
		printf("************************\n");
		printf("Hola, soy el proceso hijo %d\n", (int) getpid());
		
		execvp(program, arg_list);
	}
}


int main(){

int child_status;

	char* arg_list_PROG[] ={
	"ls",
	"-l",
	"/",
	NULL
	};

	char* arg_list[] = {
	"ls",
	"-a",
	"/",
	NULL
	};

	spawn(arg_list[0],arg_list_PROG ,arg_list);

//	wait (&child_status);
//	printf("the child process exited normally, with exit cod %d\n", WEXITSTATUS (child_status));

	return 0;
}
