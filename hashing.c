#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"
#define SIZE 100

//struct of a HASHCELL with fields: word, next
typedef struct hashcell {
    char *word;
    struct hashcell *next;
}HASHCELL;

//declares the hashtable
HASHCELL *hashtable [SIZE];

//produces an integer by hashing a string 
unsigned int hash_string(char *s){
    unsigned int hash = 1;
    while (*s != '\0') {
        hash = (hash * 7) + *s;
        s++;
    }
    return hash % SIZE;
}

//insert the cell containing the inputed string into the hashtable
void insert_hash_cell (char *s){
    unsigned int index = hash_string(s);
    //allocate new memory to copy the input string
    char *s2 = (char *) malloc(strlen(s) + 1);
    strcpy(s2, s);
    //allocate memory to create a HASHCELL and set word to the new copied string
    HASHCELL *c = (HASHCELL *) malloc(sizeof(HASHCELL));
    c -> word = s2;
    c -> next = NULL;
    //allocate HASHCELL to the specified index and check if the linked list is empty
    if (hashtable[index] == NULL){
        hashtable[index] = c;
    }
    //else, iterate through the linked list and insert cell to the end of the list
    else{
        HASHCELL *current = hashtable[index];
        while (current != NULL){
            //check for duplication
            if (strcmp(c -> word, current -> word) == 0){
                return;
            }
            //insert to the end of the Linked List
            if (current -> next == NULL){
                current -> next = c;
                return;
            }
            current = current -> next;
        }
    }
}

//output the hashtable 
void print_hash_table(){
    for (int i = 0; i <= SIZE - 1; i++){
        printf("%d:", i);
        HASHCELL *current = hashtable[i];
        while (current != NULL){
            printf ("%s ", current -> word);
            current = current -> next;
        }
        printf("\n");
    }
}

int main (){
    //initalize every element of hashtable to point to null
    for (int index = 0; index <= SIZE - 1; index++){
        hashtable[index] = NULL;
    }
    //read each lines of string inputs and inerts into the hash table
    char str[100];
    while (scanf("%s", str) != EOF){
        insert_hash_cell(str);
    }
   //print_hash_table();
   //insert every words inside the hash table into the bianry search tree
    for (int i = 0; i <= SIZE - 1; i++){
        //looping through each linked list
        HASHCELL *current = hashtable[i];
        while (current != NULL){
            insert_node (current -> word);
            current = current -> next;
        }
    }
    print_tree(root);
}
