#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

//initializes the root of the BST
NODE *root = NULL;

//recursive method to insert node into the BST
//called by insert_node (char *s)
void rec_insert_node (NODE *n, NODE *r){
    //if the value of n's word is less than the value of r's word
    if (strcmp(n -> word, r -> word) < 0){
        if (r -> left == NULL){
            r -> left = n;
        }
        else{
            return rec_insert_node (n, r -> left);
        }
    }
    //if the value is not less than 
    else{
        if (r -> right == NULL){
            r -> right = n;
        }
        else{
            return rec_insert_node(n, r -> right);
        }
    }
}

//method to insert node to BST
void insert_node (char *s){
    //initalizes a node to be inserted into the BST
    NODE *n = (NODE *) malloc(sizeof(NODE));
    n -> word = s;
    n -> left = NULL;
    n -> right = NULL;
    if (root == NULL){
        root = n;
    }
    else{
        rec_insert_node(n, root);
    }
}

//print the BST
void print_tree (NODE *r){
    //base case: when reached to the leftmost/rightmost node of the BST
    if (r == NULL){
        return;
    }
    //recusrive case: print each node with an in-order traversal
    else{
        print_tree(r -> left);
        printf("%s\n", r -> word);
        print_tree(r -> right);
    }
}

