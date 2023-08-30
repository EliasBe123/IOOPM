#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>


void clear_input_buffer(){
    int x;
    do
        {
          x = getchar();
        }
      while (x != '\n' && x != EOF);
}

int ask_question_int(char *question)
{

  int result = 0;
  int conversions = 0;
  do
    {
      printf("%s\n", question);
      conversions = scanf("%d", &result);
      clear_input_buffer();
      putchar('\n');
    }
  while (conversions < 1);
  return result;
}


int read_string(char *buf, int buf_siz){
    char c;
    for(int i = 0; i < buf_siz-1; i++){
        c = getchar();
        if(c == '\n'){
            buf[i] = '\0';
            return i;
        }
        buf[i] = c;
    }
    buf[buf_siz-1] = '\0';
    clear_input_buffer();
    return buf_siz-1;
}

int main(void)
{
    int buf_siz = 10;
    int read = 0;
    char buf[buf_siz];

    puts("Läs in en sträng:");
    read = read_string(buf, buf_siz);
    printf("'%s' (%d tecken)\n", buf, read);

    puts("Läs in en sträng till:");
    read = read_string(buf, buf_siz);
    printf("'%s' (%d tecken)\n", buf, read);

    return 0;
}
