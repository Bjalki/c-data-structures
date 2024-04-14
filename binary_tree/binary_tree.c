#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    void* key;
    struct node* prev;
    struct node* left;
    struct node* right;
}Node;

typedef struct btree {
    struct node* head;
}Btree;

Node* make_node(void* key){
    Node* n = malloc(sizeof(Node));
    n->key = key;
    n->prev = NULL;
    n->left = NULL;
    n->right = NULL;
    return n;
}

Btree* make_empty_tree(){
    Btree* tree= malloc(sizeof(Btree));
    tree->head=NULL;
    return tree;
}

Btree* make_btree(void* key) {
    Btree* tree = malloc(sizeof(Btree));
    tree-> head = make_node(key);
    return tree;
}


void print_node_int(Node* n){
    if(n!=NULL){
        print_node_int(n->left);
        printf("%d",(int*) n->key);
        print_node_int(n->right);
    }
}


void print_tree_int(Btree* tree){
    Node* n = tree->head;
    print_node_int(n);
}

void print_node_float(Node* n){
    while(n!=NULL){
        print_node_float(n->left);
        printf("%f",(float*) n->key);
        print_node_float(n->right);
    }
}

void print_tree_float(Btree* tree){
    Node* n = tree->head;
    print_node_float(n);
}

void print_node_char(Node* n){
    while(n!=NULL){
        print_node_char(n->left);
        printf("%c",(char*) n->key);
        print_node_char(n->right);
    }
}

void print_tree_char(Btree* tree){
    Node* n = tree->head;
    print_node_char(n);
}

Node* search_tree(Btree* tree, void* data){
    Node* n= tree->head;
    while (n != NULL && n->key != data){
        if (data < n->key){
            n = n->left;
        }else{
            n = n ->right;
        }
        return n;
    }
}

Node* minimum(Node* n){
    while(n->left!=NULL){
        n=n->left;
    }
    return n;
}

Node* tree_minimum(Btree* T){
    minimum(T->head);
}

Node* tree_maximum(Btree* tree){
    Node* n = tree->head;
    while(n->right!=NULL){
        n=n->right;
    }
    return n;
}

Node* find_successor_node(Node* n){
    Node* node = n;
    if (n->right!= NULL){
        return find_successor_node(node);
    }
    Node* y = n->prev;
    while(y!=NULL && n == y->right){
        n=y;
        y=y->prev;
    }
    return y;
}

void tree_insert(Btree* T, void* p){
    Node* z = make_node(p);
    Node* y = NULL;
    Node* x = T->head;
    while (x != NULL){
        y=x;
        if (z->key < x->key){
            x= x->left;
        }else{
            x = x-> right;
        }
        z->prev = y;
        if (y==NULL){
            T->head = z;
        }else if ( z->key < y->key ) {
            y->left = z;
        }else {
            y->right = z;
        }
    }
}

void transplant(Btree* T, Node* u, Node* v){
    if (u->prev==NULL){
        T->head = v;
    }else if ( u == u->prev->left ){
        u->prev->left = v;
    }else {
        u->prev->right = v;
    }
    if (v != NULL){
        v->prev = u->prev;
    }
}

void delete_node(Btree* T, void* data){
    Node* z = search_tree(T, data);
    if (z==NULL){
        return;
    }else if (z->left == NULL){
        transplant(T, z, z->right);
    }else if (z->right == NULL){
        transplant(T,z,z->left);
    }else {
        Node* y = minimum(z->right);
        transplant(T, y, y->right);
        y->right = z->right;
        y->right->prev = y;
        transplant(T,y,y->right);
        y->left = z->left;
        y->left->prev =y;
    }
    free(z);
}

void free_node(Node* n){
    free(n);
}

void free_tree(Btree* T){
    Node* n = T->head;
    while(n!=NULL){
        print_node_int(n->left);
        print_node_int(n->right);
        free(n);
    }
}


