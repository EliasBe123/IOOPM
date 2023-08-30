#include <stdio.h>

int main(void)
{
  int x[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int length = sizeof(x)/sizeof(x[0]);
  int total = 0;
  for(int i = 0; i < length; i++){
    for(int j = 0; j < x[i]; j++){
        printf("*");
        ++total;
    }
    printf("\n");
  }
  printf("Totalt: %d \n", total);
}