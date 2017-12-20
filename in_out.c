#include <stdio.h>
#include <stdlib.h>
#include "lab.h"
#include <stdbool.h>

bool save(struct node* list, const char* filename) {
    struct node *itr = list;
    FILE *out = fopen(filename, "w");
    if (!out)
        return false;
    else {
        while (itr) {
            fprintf(out, "%d ", itr->cell);
            itr = itr->next_node;
        }
    }
    fclose(out);
    return true;
}

bool load(struct node** list, const char* filename){
    FILE* in = fopen(filename, "r");
    struct node* new_list;
    if(!in)
        return false;
    int32_t val;
    fscanf(in, "%d", &val);
    new_list = list_create(val);
    while(fscanf(in, "%d", &val) != EOF)
        list_add_back(val, &new_list);
    fclose(in);
    list_free(*list);
    *list = new_list;
    return true;
}


bool serialize(struct node* lst, const char* filename){
    FILE* file=fopen(filename,"wb");
    if(!file) {
        return false;
    }
    struct node* counter=lst;
    while(counter){
        (fwrite(&(counter->cell), sizeof(int), 1, file));
        counter = counter->next_node;
    }
    fclose(file);

    return true;
}

bool deserialize(struct node** lst, const char* filename){
    int num;
    list_free(*lst);
    FILE* file = fopen(filename, "r");
    if (file){
        *lst = list_create(fscanf(file, "%d", &num));
    }
    else{
        return false;
    }
    while(fread(&num, sizeof(int),(size_t)1, file) != 0){
        list_add_back(num, lst);
    }
    fclose(file);

    return true;
}

