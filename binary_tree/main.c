#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"
int main(){
    Btree* tree = make_btree((void*)10);
    tree_insert(tree, (void*)15);
    tree_insert(tree, (void*)5);
    print_tree_int(tree);
    delete_node(tree, (void*)5);
    print_tree_int(tree);
    return 0;
}

