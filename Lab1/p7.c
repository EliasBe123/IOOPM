#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool is_number(char *str){
    int length = strlen(str);
    for(int i = 0; i < length; i++){
        if(i == 0 && str[0] == '-'){
            continue;
        }
        if(!isdigit(str[i])){
            return false;
        }
    }
    return true;
}

int main(int argc, char *argv[])
{
  if (argc > 1 && is_number(argv[1]))
{
  printf("%s is a number\n", argv[1]);
}
else
{
  if (argc > 1)
  {
    printf("%s is not a number\n", argv[1]);
  }
  else
  {
    printf("Please provide a command line argument!\n");
  }
}
}
