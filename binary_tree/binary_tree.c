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

Btree* make_btree_empty(){
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
    while(n!=NULL){
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

    Node* minimum(Btree* tree){
        Node* n = tree->head;
        while(n->left!=NULL){
            n=n->left;
        }
        return n;
    }
}

Node* maximum(Btree* tree){
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

int main(){
    return 0;
}





