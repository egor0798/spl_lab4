#include <stdio.h>
#include <stdlib.h>
#include "lab.h"
#include <limits.h>
int main(){
    int32_t val;
    struct node* list = NULL;


    //PART 1
    while (scanf("%d", &val) == 1) {
        if (list == NULL)
            list = list_create(val);
        else
            list_add_front(val, &list);
    }

    printf("Sum is: ");
    printf("%d\n", list_sum(list));
    printf("List length is: %d\n", list_lenght(list));

    int pos = 3;
    int get = list_get(pos, list);
    if(get==0)
        printf("Out of range!\n");
    else
        printf("Element on position %d = %d \n", pos, get);

    //PART 2
    list = map(list, &absol);
    printf("Print with spaces: ");
    foreach(list, &print_space);
    printf("\nPrint reverse: ");
    foreach(reverse(list), &print_space);
    replace(1, 7, list);
    insert_front(1,8,list);
    printf("\nPrint with newline\n");
    foreach(list, &print_newline);
    printf("ABS: ");


    printf("Squares: ");
    struct node* squares = map(list, &square);
    foreach(squares, &print_space);
    printf("\n");
    list_free(squares);
    printf("Cubes: ");
    struct node* cubes = map(list, &cube);
    foreach(cubes, &print_space);
    list_free(cubes);
    printf("\n");


    printf("min = %d\n", foldl(INT32_MAX, &find_min, list));
    printf("max = %d\n", foldl(INT32_MIN, &find_max, list));

    printf("Testing map_mut");
    map_mut(list, &abs);
    printf("\n");

    struct node* list1 = iterate(1, 10, &mul2);
    printf("Testing iterate ");
    foreach(list1, &print_space);
    free(list1);
    printf("\n");

    if (save(list, "input.txt"))
        printf("Saved\n");
    else
        printf("Cannot save\n");

    if (load(&list, "input.txt"))
        printf("Loaded\n");
    else
        printf("Cannot load\n");

    if (serialize(list, "input.txt"))
        printf("Serialized\n");
    else
        printf("Error while serializing\n");

    if (deserialize(&list, "input.txt")){
        printf("Deserialized\n");
    }
    else {
        printf("Error while deserializing\n");
    }

    list_free(list);

    return 0;
}