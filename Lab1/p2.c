#include <stdio.h>

int main(void)
{
  int x[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int length = sizeof(x)/sizeof(x[0]);
  for(int i = length; i >= 0; i--){
    printf("%d \n", x[i]);
  }
}