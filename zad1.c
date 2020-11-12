#include <stdio.h>
#include <unistd.h>
#include <time.h>

int main(){
  int i = 0;

  struct timespec tim, tim2;

  tim.tv_sec = 0;
  tim.tv_nsec = 100L;
  while (1){
    ++i;
    printf("%d \n", i);
    nanosleep(&tim, &tim2);
  }
}
