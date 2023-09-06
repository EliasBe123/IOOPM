#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "../Lab2/utils.h"

struct item
{
    char *name;
    char *description;
    int price;
    char *shelf;
};

typedef struct item item_t;

void print_item(item_t *item)
{
    printf("Name: %s \nDesc: %s\nPrice: %d.%d SEK \nShelf: %s \n", item->name, item->description, item->price / 100, item->price % 100, item->shelf);
}

item_t make_item(char *name, char *description, int price, char *shelf)
{
    item_t item = {.name = name, .description = description, .price = price, .shelf = shelf};
    return item;
}

bool is_shelf(char *str)
{
    if (!is_number(&(*str)))
    {
        while (*str)
        {
            ++str;
            if (!is_number(&(*str)))
            {
                return false;
            }
        }
        return true;
    }
    return false;
}

char *ask_question_shelf(char *question)
{
    return ask_question(question, is_shelf, (convert_func)strdup).string_value;
}

item_t input_item()
{
    char *name = ask_question_string("Name: ");
    char *desc = ask_question_string("\nDescription: ");
    int price = ask_question_int("\nPrice: ");
    char *shelf = ask_question_shelf("Shelf: ");
    item_t item = make_item(name, desc, price, shelf);
    return item;
}

char *magick(char *arr1[], char *arr2[], char *arr3[], int lenofarr)
{

    int r1 = rand() % lenofarr;
    int r2 = rand() % lenofarr;
    int r3 = rand() % lenofarr;
    char *arr[3];
    arr[0] = arr1[r1];
    arr[1] = arr2[r2];
    arr[2] = arr3[r3];
    char buf[255];
    int index1 = 0;
    int index2 = 0;
    int length = strlen(arr[0]);
    for (index1 = 0; index1 < length; index1++)
    {
        buf[index1] = arr[0][index1];
    }

    buf[index1] = '-';
    length = strlen(arr[1]);
    index2 = 0;
    int tmp = index1;
    while (++index1 <= length + tmp)
    {
        buf[index1] = arr[1][index2];

        index2++;
    }
    buf[index1] = ' ';

    length = strlen(arr[2]);
    index2 = 0;
    tmp = index1;
    while (++index1 <= length + tmp)
    {

        buf[index1] = arr[2][index2];

        index2++;
    }
    buf[index1] = '\0';
    return strdup(buf);
}

void list_db(item_t *items, int no_items)
{
    for (int i = 0; i < no_items; i++)
    {
        printf("%d. ", i + 1);
        print_item(*(&items));
        items++;
    }
}

void edit_db(item_t *items, int db_siz)
{
    int num;
    do
    {
        list_db(items, db_siz);
        num = ask_question_int("Vilken vara ska ersättas? ");
    } while (num > 16 | num < 1);
    print_item(&items[num - 1]);
    items[num - 1] = input_item();
}

void print_menu()
{
    char *str = "[L]ägga till en vara \n"
                "[T]a bort en vara \n"
                "[R]edigera en vara \n"
                "Ån[g]ra senaste ändringen \n"
                "Lista [h]ela varukatalogen \n"
                "[A]vsluta \n";
    puts(str);
}

bool is_special_char(char c)
{
    if (c == 'L' || c == 'T' || c == 'R' || c == 'G' || c == 'H' || c == 'A')
    {
        return true;
    }
    return false;
}

char ask_question_menu()
{
    int buf_siz = 3;
    char buf[buf_siz];
    char c;
    do
    {
        print_menu();
        read_string(buf, buf_siz);
        c = toupper(buf[0]);

    } while (!is_special_char(c) || buf[1] != '\0');
    
    return c;
}

void add_item_to_db(item_t *db, int *db_siz)
{
    item_t item = input_item();
    db[*db_siz] = item;
    ++*db_siz;
}

int remove_item_from_db(item_t *db, int *db_siz)
{
    int nrdel;
    do
    {
        list_db(db, *db_siz);
        nrdel = ask_question_int("What item to delete? ");

    } while (nrdel > *db_siz || nrdel < 1);
    if (nrdel == *db_siz)
    {
        --*db_siz;
        return nrdel;
    }
    for (int i = nrdel; i < *db_siz; i++)
    {
        db[i] = db[i + 1];
    }
    --*db_siz;
    return nrdel;
}

void event_loop(item_t *db, int *db_siz)
{
    bool loop = true;
    while (loop)
    {
        char choice = ask_question_menu();
        if (choice == 'L')
        {
            add_item_to_db(db, db_siz);
        }
        else if(choice == 'T'){
            remove_item_from_db(db, db_siz);
        }
        else if(choice == 'R'){
            edit_db(db, *db_siz);
        }
        else if(choice == 'G'){
            puts("Not implemented yet");
        }
        else if(choice == 'H'){
            list_db(db, *db_siz);
        }
        else if(choice == 'A'){
            loop = false;
        }
    }
}

int main(int argc, char *argv[])
{
    char *array1[] = {"Laser", "Polka", "Extra"};
    char *array2[] = {"förnicklad", "smakande", "ordinär"};
    char *array3[] = {"skruvdragare", "kola", "uppgift"};

    if (argc < 2)
    {
        printf("Usage: %s number\n", argv[0]);
    }
    else
    {
        item_t db[100]; // Array med plats för 16 varor
        int db_siz = 0; // Antalet varor i arrayen just nu

        int items = atoi(argv[1]); // Antalet varor som skall skapas

        if (items > 0 && items <= 16)
        {
            for (int i = 0; i < items; ++i)
            {
                // Läs in en vara, lägg till den i arrayen, öka storleksräknaren
                item_t item = input_item();
                db[db_siz] = item;
                ++db_siz;
            }
        }
        else
        {
            puts("Sorry, must have [1-16] items in database.");
            return 1; // Avslutar programmet!
        }

        for (int i = db_siz; i < 16; ++i)
        {
            char *name = magick(array1, array2, array3, 3); // TODO: Lägg till storlek
            char *desc = magick(array1, array2, array3, 3); // TODO: Lägg till storlek
            int price = random() % 200000;
            char shelf[] = {random() % ('Z' - 'A') + 'A',
                            random() % 10 + '0',
                            random() % 10 + '0',
                            '\0'};
            item_t item = make_item(name, desc, price, shelf);

            db[db_siz] = item;
            ++db_siz;
        }

        // Skriv ut innehållet
        event_loop(db, &db_siz);
    }
    return 0;
}