#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{

  int a = atoi(argv[1]);
  int b = atoi(argv[2]);
  int greatest;
  bool notfound = true;
    if(!isdigit(atoi(argv[1])) || !isdigit(atoi(argv[2]))){
        printf("Negative numbers not allowed\n");
        notfound = false;
    }
  while(notfound){
    if(a == b){
        notfound = false;
        greatest = a;
    }else if(a > b){
        a = a-b;
    }else{
        b = b-a;
    }
  }
  
  printf("GCD(%d, %d): %d\n", a, b, greatest);
}

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