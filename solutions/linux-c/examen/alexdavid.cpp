#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>
#include <wait.h>




void spawn(char* programa,char** arg_list){
	pid_t child_pid;
	child_pid = fork ();

	if(child_pid != 0){
	return;
	}
	else{
	execvp(programa, arg_list);
	sleep(1);
	}
}

void insulto(){
printf("Alex es gilipollas, padre\n");
 int child_status;

        char* arg_list[] = {
         "sleep",
         "5",
        NULL
         };
 
 spawn(arg_list[0], arg_list);
 
 wait (&child_status);

if(WIFEXITED (child_status))
printf("Ha terminado ya \n ");
insulto();

}




int main(){
insulto();
return 0;
}
