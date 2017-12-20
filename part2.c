#include <stdlib.h>
#include <stdio.h>
#include "lab.h"

// foreach via map              DONE
void foreach(struct node* list, void(*func)(int32_t arg)){
    struct node* itr = list;
    map(list, func);
}

// map/map_mut via foreach      DONE
struct node* map(struct node* list, int32_t(*func)(int32_t)){
    struct node* itr = list;
    struct node* new_list = list_create(func(itr->cell));
    itr = itr->next_node;
    while(itr){
        list_add_back(func(itr->cell), &new_list);
        itr = itr->next_node;
    }
    return new_list;
}

void map_mut(struct node* list, int32_t(*func)(int32_t)){
    struct node* itr = list;
    while(itr){
        itr->cell = func(itr->cell);
        itr = itr->next_node;
    }
}


int32_t foldl(int32_t ac, int32_t (*func)(int32_t a,int32_t b), struct node* list){
    struct node* itr = list;
    while(itr){
        ac = func(itr->cell, ac);
        itr = itr->next_node;
    }
    return ac;
}

int32_t foldr(int32_t ac, int32_t (*func)(int32_t a,int32_t b), struct node* list){
   list = reverse(list);
    return foldl(ac,func, list);
}

struct node* iterate(int32_t s, int32_t n, int32_t (*func)(int32_t val)){
    struct node* list = list_create(s);
    for (int i = 1; i < n; ++i) {
        s = func(s);
        list_add_back(s, &list);
    }
    return list;
}

// ADDITIONAL
void print_space(int32_t val){
    printf("%d ", val);
}

void print_newline(int32_t val){
    printf("%d\n", val);
}

int32_t find_min(int32_t a, int32_t b){
    int min;
    if (b > a)
        min = a;
    return min;
}

int32_t find_max(int32_t a, int32_t b){
    int max;
    if (b < a)
        max = a;
    return max;
}

int32_t square(int32_t a){
    a *= a;
    return a;
}

int32_t cube(int32_t a){
    a *= a;
    a *= a;
    return a;
}

// XXX: unused      DONE
int32_t absol(int32_t a){
    a = (int32_t)abs(a);
    return a;
}

int32_t mul2(int32_t a){
    a *= 2;
    return a;
}


