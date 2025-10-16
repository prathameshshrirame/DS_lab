#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *tree = NULL;

// Function declarations
void create_tree(struct node **);
struct node *insertElement(struct node *, int);
void preorderTraversal(struct node *);
void inorderTraversal(struct node *);
void postorderTraversal(struct node *);
struct node *findSmallestElement(struct node *);
struct node *findLargestElement(struct node *);
struct node *deleteElement(struct node *, int);
int totalNodes(struct node *);
int totalExternalNodes(struct node *);
int totalInternalNodes(struct node *);
int height(struct node *);
struct node *deleteTree(struct node *);

int main() {
    int option, val;
    struct node *ptr;

    create_tree(&tree);

    do {
        printf("\n******MAIN MENU******\n");
        printf("\n 1. Insert Element");
        printf("\n 2. Inorder Traversal");
        printf("\n 3. Preorder Traversal");
        printf("\n 4. Postorder Traversal");
        printf("\n 5. Find the smallest element");
        printf("\n 6. Find the largest element");
        printf("\n 7. Delete an element");
        printf("\n 8. Count the total number of nodes");
        printf("\n 9. Count the total number of external nodes");
        printf("\n 10. Count the total number of internal nodes");
        printf("\n 11. Determine the height of the tree");
        printf("\n 12. Delete the tree");
        printf("\n 13. Exit");
        printf("\n\n Enter your option : ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                printf("\n Enter the value of new node: ");
                scanf("%d", &val);
                tree = insertElement(tree, val);
                break;
            case 2:
                printf("\n Inorder Traversal: ");
                inorderTraversal(tree);
                break;
            case 3:
                printf("\n Preorder Traversal: ");
                preorderTraversal(tree);
                break;
            case 4:
                printf("\n Postorder Traversal: ");
                postorderTraversal(tree);
                break;
            case 5:
                ptr = findSmallestElement(tree);
                if (ptr)
                    printf("\n Smallest Element is: %d", ptr->data);
                else
                    printf("\n Tree is empty.");
                break;
            case 6:
                ptr = findLargestElement(tree);
                if (ptr)
                    printf("\n Largest Element is: %d", ptr->data);
                else
                    printf("\n Tree is empty.");
                break;
            case 7:
                printf("\n Enter the element to be deleted: ");
                scanf("%d", &val);
                tree = deleteElement(tree, val);
                break;
            case 8:
                printf("\n Total number of nodes = %d", totalNodes(tree));
                break;
            case 9:
                printf("\n Total number of external nodes = %d", totalExternalNodes(tree));
                break;
            case 10:
                printf("\n Total number of internal nodes = %d", totalInternalNodes(tree));
                break;
            case 11:
                printf("\n Height of the tree = %d", height(tree));
                break;
            case 12:
                tree = deleteTree(tree);
                printf("\n Tree deleted.");
                break;
            case 13:
                printf("\n Exiting...");
                break;
            default:
                printf("\n Invalid option.");
        }
    } while(option != 13);

    return 0;
}

void create_tree(struct node **tree) {
    *tree = NULL;
}

struct node *insertElement(struct node *tree, int val) {
    if (tree == NULL) {
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = val;
        newNode->left = newNode->right = NULL;
        return newNode;
    }
    if (val < tree->data)
        tree->left = insertElement(tree->left, val);
    else
        tree->right = insertElement(tree->right, val);
    return tree;
}

void preorderTraversal(struct node *tree) {
    if (tree != NULL) {
        printf("%d ", tree->data);
        preorderTraversal(tree->left);
        preorderTraversal(tree->right);
    }
}

void inorderTraversal(struct node *tree) {
    if (tree != NULL) {
        inorderTraversal(tree->left);
        printf("%d ", tree->data);
        inorderTraversal(tree->right);
    }
}

void postorderTraversal(struct node *tree) {
    if (tree != NULL) {
        postorderTraversal(tree->left);
        postorderTraversal(tree->right);
        printf("%d ", tree->data);
    }
}

struct node *findSmallestElement(struct node *tree) {
    if (tree == NULL)
        return NULL;
    while (tree->left != NULL)
        tree = tree->left;
    return tree;
}

struct node *findLargestElement(struct node *tree) {
    if (tree == NULL)
        return NULL;
    while (tree->right != NULL)
        tree = tree->right;
    return tree;
}

struct node *deleteElement(struct node *tree, int val) {
    if (tree == NULL) {
        printf("\nElement not found.");
        return NULL;
    }

    if (val < tree->data)
        tree->left = deleteElement(tree->left, val);
    else if (val > tree->data)
        tree->right = deleteElement(tree->right, val);
    else {
        // Node found
        if (tree->left == NULL && tree->right == NULL) {
            free(tree);
            return NULL;
        } else if (tree->left == NULL) {
            struct node *temp = tree->right;
            free(tree);
            return temp;
        } else if (tree->right == NULL) {
            struct node *temp = tree->left;
            free(tree);
            return temp;
        } else {
            // Two children
            struct node *succ = findSmallestElement(tree->right);
            tree->data = succ->data;
            tree->right = deleteElement(tree->right, succ->data);
        }
    }
    return tree;
}

int totalNodes(struct node *tree) {
    if (tree == NULL)
        return 0;
    return 1 + totalNodes(tree->left) + totalNodes(tree->right);
}

int totalExternalNodes(struct node *tree) {
    if (tree == NULL)
        return 0;
    if (tree->left == NULL && tree->right == NULL)
        return 1;
    return totalExternalNodes(tree->left) + totalExternalNodes(tree->right);
}

int totalInternalNodes(struct node *tree) {
    if (tree == NULL || (tree->left == NULL && tree->right == NULL))
        return 0;
    return 1 + totalInternalNodes(tree->left) + totalInternalNodes(tree->right);
}

int height(struct node *tree) {
    if (tree == NULL)
        return 0;
    int l = height(tree->left);
    int r = height(tree->right);
    return (l > r ? l : r) + 1;
}

struct node *deleteTree(struct node *tree) {
    if (tree != NULL) {
        deleteTree(tree->left);
        deleteTree(tree->right);
        free(tree);
    }
    return NULL;
}

