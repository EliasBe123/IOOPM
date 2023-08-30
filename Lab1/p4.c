#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int rows = atoi(argv[1]);
  int growth = atoi(argv[2]);
  int numberofasterisk = growth;
  int total = 0;
  for(int i = 0; i < rows; i++){
    for(int j = 0; j < numberofasterisk; j++){
        printf("*");
        total++;
    }
    printf("\n");
    numberofasterisk = growth+numberofasterisk;
  }
  printf("Totalt: %d \n", total);
}