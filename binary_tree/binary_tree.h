#ifndef BINARY_TREE_H_
#define BINARY_TREE_H_

typedef struct node {
    void* key;
    struct node* prev;
    struct node* left;
    struct node* right;
}Node;

typedef struct btree {
    struct node* head;
}Btree;

Node* make_node(void* key);
Btree* make_empty_tree();
Btree* make_btree();
void print_node_int(Node* n);
void print_tree_int(Btree* tree);
void print_tree_float(Btree* tree);
void print_node_float(Node* n);
void print_tree_char(Btree* tree);
void print_node_char(Node* n);
Node* search_tree(Btree* tree , void* data);
Node* minimum(Node* n);
Node* tree_minimum(Btree* T);
Node* tree_maximum(Btree* T);
Node* find_successor_node(Node* n);
void tree_insert(Btree* T, void* p);
void transplant(Btree* T, Node* u, Node* v);
void delete_node(Btree*, void* data);
void free_node(Node* n);
void free_tree(Btree* T);

#endif
