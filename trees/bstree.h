//
// Created by joao on 11/10/23.
//

#ifndef BSTREE_H
#define BSTREE_H

typedef struct BSTNode{
    struct BSTNode * right;
    struct BSTNode * left;
    void *data;
} BSTNode;

typedef struct BSTree{
    BSTNode * root;
    int (*compare)(void*a,void*b);
    void (*destroy)(void*data);
    int n_elem;
} BSTree;

BSTree * bstree_init(int (*compare)(void*a,void*b), void (*destroy)(void*data));

void bstree_destroy(BSTree * tree);

BSTNode * bstree_search_dad(BSTree * tree, void * key);

int bstree_insert(BSTree * tree, void * data);

int bstree_remove(BSTree * tree, void * key);

#define node_data(node) ((node)->data)

#endif //BSTREE_H
