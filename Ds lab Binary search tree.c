#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int id;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode *root = NULL;

TreeNode *createNode(int id) {
    TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
    newNode->id = id;
    newNode->left = newNode->right = NULL;
    return newNode;
}

TreeNode *insert(TreeNode *node, int id) {
    if (node == NULL) {
        return createNode(id);
    }

    if (id < node->id) {
        node->left = insert(node->left, id);
    } else if (id > node->id) {
        node->right = insert(node->right, id);
    }

    return node;
}

TreeNode *search(TreeNode *node, int id) {
    if (node == NULL || node->id == id) {
        return node;
    }

    if (id < node->id) {
        return search(node->left, id);
    }

    return search(node->right, id);
}

void inorderTraversal(TreeNode *node) {
    if (node != NULL) {
        inorderTraversal(node->left);
        printf("%d ", node->id);
        inorderTraversal(node->right);
    }
}

int main() {
    int choice, id;

    while (1) {
        printf("\nStudent ID Management System\n");
        printf("1. Insert Student ID\n");
        printf("2. Search ID\n");
        printf("3. Display All IDs (Inorder)\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter ID: ");
                scanf("%d", &id);
                root = insert(root, id);
                printf("ID inserted.\n");
                break;
            case 2:
                printf("Enter ID to search: ");
                scanf("%d", &id);
                TreeNode *result = search(root, id);
                if (result != NULL) {
                    printf("ID %d found in the system.\n", id);
                } else {
                    printf("ID %d not found.\n", id);
                }
                break;
            case 3:
                printf("Student IDs in order: ");
                inorderTraversal(root);
                printf("\n");
                break;
            case 4:
                printf("Exiting system.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
