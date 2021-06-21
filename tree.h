//struct of a NODE with fields: word, left, right
typedef struct Node{
    char *word;
    struct Node* left;
    struct Node* right;
}NODE;

//pointer to the root of the BST
extern NODE *root;

//function to insert a node 
void insert_node (char *s);

//function to print the BST within in-order traversal
void print_tree (NODE *r);
