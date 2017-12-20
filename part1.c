#include <stdlib.h>
#include "lab.h"

struct node* list_create(int32_t val){
    struct node* ptr = malloc(sizeof(struct node));
    ptr->cell = val;
    ptr->next_node = NULL;
    return ptr;
}

struct node* list_add_front(int32_t val, struct node** head){
    struct node* new_node = malloc(sizeof(struct node));
    new_node->cell = (*head)->cell;
    new_node->next_node = (*head)->next_node;
    (*head)->cell = val;
    (*head)->next_node = new_node;
    return *head;
}

bool replace(int32_t pos, int32_t val, struct node* list){
    struct node* ptr = list_node_at(pos, list);
    if(!ptr)
        return false;
    ptr->cell = val;
    return true;
}

bool insert_front(int32_t pos, int32_t val, struct node* list){
    struct node* ptr = list_node_at(pos, list);
    if(!ptr)
        return false;
    struct node* new = malloc(sizeof(struct node));
    new->cell = val;
    new->next_node = ptr->next_node;
    ptr->next_node = new;
    return true;
 }

struct node* reverse(struct node* list){
    struct node* itr = list;
    struct node* new = list_create(itr->cell);
    itr = itr->next_node;
    while (itr){
        list_add_front(itr->cell, &new);
        itr = itr->next_node;
    }
    return new;
}

bool insert_back(int32_t pos, int32_t val, struct node* list){
    if(!list_node_at(pos, list))
        return false;
    struct node* ptr = list_node_at(pos+1, list);
    if(!ptr) {
        list_add_back(val, &list);
        return true;
    }
    struct node* new_node = malloc(sizeof(struct node));
    ptr->next_node = new_node;
    new_node->cell = val;
    new_node->next_node = list_node_at(pos, list);
    return  true;
}
// end?
struct node* list_add_back(int32_t val, struct node** head){
    struct node* new_node = malloc(sizeof(struct node));
    struct node* iter = (*head);
    while (iter->next_node)
        iter = iter->next_node;
    new_node->cell = val;
    new_node->next_node = NULL;
    iter->next_node = new_node;
    return *head;
}

struct node* list_node_at(int32_t index, struct node* list){
    struct node* iter = list;
    for (int i = 0; i < index; ++i) {
        if(!iter)
            return 0;
        iter = iter->next_node;
    }
    return iter;
}

int32_t len(int32_t a, int32_t b){
    b+=1;
    return b;
}

int32_t sum(int32_t a, int32_t b){
    return b+=a;
}

int32_t list_get(int32_t index, struct node* list){
    if(!list_node_at(index, list))
        return 0;
    return list_node_at(index, list)->cell;
}

// XXX: unused          DONE
// foldl                DONE
int32_t list_lenght(struct node* list) {
    return foldl(0, &len, list);
}

// foldl                DONE
int32_t list_sum(struct node* list) {
    return foldl(0, &sum, list);
}


// map / map_mut
void list_free(struct node* list){
    struct node* el1 = list;
    struct node* el2 = list->next_node;
    while(el2){
        free(el1);
        el1 = el2;
        el2 = el2->next_node;
    }
    free(el2);
    free(el1);
}


