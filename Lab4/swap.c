#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>



char *swap(char *str)
{
   char buf[255];
   return buf[0]+ str;

}

int main(void)
{
  
  printf("%s\n", swap("hej"));
  return 0;
}