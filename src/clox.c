#include <stdio.h>
#include <stdlib.h>

struct Cons
{
    char *value;
    struct Cons *next;
    struct Cons *prev;
};

typedef struct Cons Cons;

Cons *makeCons(char *value)
{
    Cons *cons = malloc(sizeof(Cons));
    *cons = (Cons){value, NULL, NULL};
    return cons;
}

Cons *last(Cons *cons)
{
    Cons *next = cons->next;
    if (next == NULL)
    {
        return cons;
    }
    while (next->next != NULL)
    {
        next = next->next;
    }

    return next;
}

Cons *first(Cons *cons)
{
    Cons *prev = cons->prev;
    if (prev == NULL)
    {
        return cons;
    }
    while (prev->prev != NULL)
    {
        prev = prev->prev;
    }
    {
        return prev;
    }
}

Cons *push_back(Cons *cons, char *value)
{
    Cons *final_occupied = last(cons);
    Cons *next = malloc(sizeof(Cons));
    final_occupied->next = next;
    next->prev = final_occupied;
    next->value = value;
    next->next = NULL;
    return next;
}
Cons *push_front(Cons *cons, char *value)
{
    Cons *first_occupied = first(cons);
    Cons *prev = malloc(sizeof(Cons));
    first_occupied->prev = prev;
    prev->next = first_occupied;
    prev->value = value;
    prev->prev = NULL;
    return prev;
}

void printcons(Cons *cons)
{
    cons = first(cons);
    while (cons != NULL)
    {
        printf("%s, ", cons->value);
        cons = cons->next;
    }
    printf("\n");
}

void freeCons(Cons *cons)
{
    if (cons->next != NULL)
    {
        freeCons(cons->next);
    }
    free(cons);
}

int main()
{
    printf("meow\n");
    Cons *mycons = makeCons("0");
    push_back(mycons, "1");
    push_front(mycons, "-1");
    push_back(mycons, "2");
    push_front(mycons, "-2");
    printcons(mycons);
    freeCons(first(mycons));
}