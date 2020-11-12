#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <signal.h>
#include <stdlib.h>

int i = 0;

void sigA(){
  printf("Komunikat o zakonczeniu pracy programu.\n");
  exit(0);
}

void sigB(){
  printf("Kontynuacja wykonywania programu.\n");
}

void sigC(){
  if (i <= 250){
    ;
  }
  else{
    printf("Wznowienie odbioru sygnalu.\n");
  }
}

void sigD(){
  ;
}

int main(){

  struct timespec tim, tim2;

  tim.tv_sec = 0;
  tim.tv_nsec = 100000000L;

  signal (SIGTERM, sigA);
  signal (SIGALRM, sigB);
  signal (SIGUSR1, sigC);
  signal (SIGUSR2, sigD);
  
  while(i < 1000000){
    ++i;
    printf("%d \n", i);
    nanosleep(&tim, &tim2);
  }
}
