#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "utils.h"

void clear_input_buffer()
{
    int x;
    do
    {
        x = getchar();
    } while (x != '\n' && x != EOF);
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
    } while (conversions < 1);
    return result;
}

int read_string(char *buf, int buf_siz)
{
    char c;
    for (int i = 0; i < buf_siz - 1; i++)
    {
        c = getchar();
        if (c == '\n')
        {
            buf[i] = '\0';
            return i;
        }
        buf[i] = c;
    }
    buf[buf_siz - 1] = '\0';
    clear_input_buffer();
    return buf_siz - 1;
}

char *ask_question_string(char *question, char *buf, int buf_siz)
{
    printf("%s\n", question);
    while (read_string(buf, buf_siz) < 1)
    {
    }
    printf("%s\n", buf);

    return buf;
}

