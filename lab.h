#include <stdint.h>
#include <stdbool.h>

struct node{
    int32_t  cell;
    struct node* next_node;
};

//PART 1
struct node* reverse(struct node*);
bool replace(int32_t pos, int32_t val, struct node* list);
bool insert_front(int32_t pos, int32_t val, struct node* list);
bool insert_back(int32_t pos, int32_t val, struct node* list);
struct node* list_create(int32_t);
struct node* list_add_front(int32_t, struct node** );
struct node* list_add_back(int32_t, struct node** );
int32_t list_get(int32_t, struct node*);
int32_t list_lenght(struct node*);
struct node* list_node_at(int32_t, struct node*);
int32_t list_sum(struct node*);
void list_free(struct node *);

//PART 2
void foreach(struct node*, void(*)(int32_t));
struct node* map(struct node*, int32_t(*)(int32_t));
void map_mut(struct node*, int32_t(*)(int32_t));
int32_t foldl(int32_t, int32_t (*)(int32_t,int32_t), struct node*);
int32_t foldr(int32_t, int32_t (*)(int32_t,int32_t), struct node*);
struct node* iterate(int32_t, int32_t, int32_t (*)(int32_t));

bool save(struct node*, const char*);
bool load(struct node**, const char*);
bool serialize(struct node*, const char*);
bool deserialize(struct node**, const char*);

//ADDITIONAL
void print_space(int32_t);
void print_newline(int32_t);
int32_t square(int32_t);
int32_t cube(int32_t);
int32_t find_min(int32_t, int32_t);
int32_t find_max(int32_t, int32_t);
int32_t absol(int32_t);
int32_t mul2(int32_t);
