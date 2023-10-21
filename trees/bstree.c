//
// Created by joao on 11/10/23.
//

#include "bstree.h"
#include <stdlib.h>

/*----------------------------------Routines--------------------------------*/
/*Initializes a node, filling the node structure camps*/
BSTNode * init_node(void * data) {
    BSTNode * node = (BSTNode *) malloc(sizeof(BSTNode));
    if (node == NULL) exit(1);
    node->right = node ->left = NULL;
    node->data = data;
    return node;
}

/*Makes a recursive path over the tree to insert a new node.
 If key camp of data already in the tree, the insertion fails e return 0, else
 it does the insertion of a new node.*/
int insert(BSTNode ** root, void * data, int (*compare)(void*a,void*b)) {
    if (*root == NULL) {
        *root = init_node(data);
        return 1;
    }
    else {
        switch (compare((*root)->data, data)) {
            case 0:
                return 0;
            case 1:
                insert(&(*root)->left, data, compare);
                break;
            case -1:
                insert(&(*root)->right, data, compare);
                break;
        }
        return 1;
    }
}

/*Searches for the left successor node of pt*/
BSTNode * successor(BSTNode * pt) {
    BSTNode * suc = pt->right,
            * dad_suc = pt;

    if (suc == NULL) return dad_suc;

    else {
        while (suc->left != NULL) {
            dad_suc = suc; suc = suc->left;
        }
        return dad_suc;
    }
}

BSTNode * decide_child(BSTNode * dad, void * key, int (*compare)(void*a,void*b)) {
    if (dad == NULL) return NULL;
    switch (compare(dad->data, key)) {
        case 1:
            return dad->left;
        case -1:
            return dad->right;
        default:
            return dad;
    }
}

void destroy_tree(BSTNode * root, void (*destroy)(void*data)) {
    if (root == NULL)
        return;
    else {
        void * data = root->data;
        if (destroy) destroy(data);
        destroy_tree(root->left, destroy);
        destroy_tree(root->right, destroy);
        free(root);
    }
}

BSTree * bstree_init(int (*compare)(void*a,void*b), void (*destroy)(void*data)) {
    BSTree * tree = (BSTree *) malloc(sizeof(BSTree));
    if (tree == NULL) exit(1);
    tree->root = NULL;
    tree->n_elem = 0;
    tree->destroy = destroy;
    tree->compare = compare;
    return tree;
}

BSTNode * bstree_search_dad(BSTree * tree, void * key) {
    BSTNode  * dad = NULL
            ,* pt = tree->root;
    while (pt != NULL) {
        switch (tree->compare(pt->data, key)) {
            case 1:
                dad = pt; pt = pt->left;
                break;
            case -1:
                dad = pt; pt = pt->right;
                break;
            case 0:
                return dad;
        }
    }
    return dad;
}

int bstree_insert(BSTree * tree, void * data) {
    BSTNode * root = tree->root;
    int r;
    if (root == NULL) {
        tree->root = init_node(data);
        tree->n_elem++;
        r = 1;
    }
    else {
        r = insert(&root, data, tree->compare);
        if (r == 1) tree->n_elem++;
    }
    return r;
}

int bstree_remove(BSTree * tree, void * key) {
    if (tree->root == NULL) return 0;
    BSTNode * dad = bstree_search_dad(tree, key),
            * pt,
            * dad_suc,
            * suc,
            * old;
    void * data;

    pt = decide_child(dad, key, tree->compare);

    if (pt == NULL && dad != NULL) return 0;

    if (dad == NULL) {
        dad_suc = successor(tree->root);
        if (dad_suc == tree->root) suc = tree->root->right;
        else suc = dad_suc->left;
        if (suc == NULL) {
            old = tree->root; tree->root = tree->root->left;
            if (tree->destroy) tree->destroy(old->data);
            free(old);
        }
        else {
            data = tree->root->data;
            tree->root->data = suc->data;
            if (dad_suc ==  tree->root)
                tree->root->right = suc->right;
            else
                dad_suc->left = suc->right;
            if (tree->destroy) tree->destroy(data);
            free(suc);
        }
    }
    else {
        dad_suc = successor(pt);
        if (dad_suc == pt) suc = pt->right;
        else suc = dad_suc->left;
        if (suc == NULL) {
            if (tree->compare(dad->data, key) == 1)
                dad->left = pt->left;
            else
                dad->right = pt->left;
            data = pt->data;
            if(tree->destroy) tree->destroy(data);
            free(pt);
        }
        else {
            data = pt->data;
            pt->data = suc->data;
            if (dad_suc == pt)
                pt->right = suc->right;
            else
                dad_suc->left = suc->right;
            if (tree->destroy) tree->destroy(data);
            free(suc);
        }
    }
    tree->n_elem--;
    return 1;
}

void bstree_destroy(BSTree * tree) {
    destroy_tree(tree->root, tree->destroy);
}