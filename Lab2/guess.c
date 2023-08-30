#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utils.h"

int main(void)
{
    srandom(time(NULL));
    int r = random() % 100;
    int buf_siz = 255;
    char buf[buf_siz];
    bool found = false;
    int nrofguesses = 0;

    char *name = ask_question_string("Skriv in ditt namn:", buf, buf_siz);
    printf("Du %s, jag tänker på ett tal ... kan du gissa vilket?", name);
    int guess = ask_question_int("");
    while(!found){
        nrofguesses++;
        if(nrofguesses > 15){
            printf("Nu har du slut på gissningar! Jag tänkte på %d! \n", r);
            break;
        }
        if(guess == r){
            found = true;
            puts("Bingo!");
            printf("Det tog %s %d gissningar att komma fram till %d", name, nrofguesses, r);
        } else if(guess < r){
            puts("För litet!");
        }else{
            puts("För stort!");
        }
        guess = ask_question_int("\n");
    }
   
}