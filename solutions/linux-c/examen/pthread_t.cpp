#include<stdio.h>
#include<pthread.h>
#include<unistd.h>


void *print_hola(void *args){
printf("Hola tio estas en el hilo 1");
return NULL;
}

void *print_mundo(void *args){
printf("mundo");
return NULL;
}

void *print_que(void *args){
printf("que");
return NULL;
}

void *print_tal(void *args){
printf("tal?");
return NULL;
}


int main(){
pthread_t hilo1;
pthread_t hilo2;
pthread_t hilo3;
pthread_t hilo4;

pthread_create(&hilo1 , NULL, print_hola , NULL);
pthread_create(&hilo2 , NULL, print_mundo , NULL);
pthread_create(&hilo3 , NULL, print_que , NULL);
pthread_create(&hilo4 , NULL, print_tal , NULL);

pthread_join(hilo1,NULL);
pthread_join(hilo2,NULL);
pthread_join(hilo3,NULL);
pthread_join(hilo4,NULL);

printf("He acababo");
}
