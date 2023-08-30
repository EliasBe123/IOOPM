#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
  int number = atoi(argv[1]);
  bool isprime = true;
  for(int i = 2; i < number; i++){
    for(int j = 2; j < number; j++){
        if(j*i == number){
            isprime = false;
        }
    }
  }
   if(isprime == false){
    printf("Not a prime\n");
   }else{
    printf("Is prime\n");
   }
}