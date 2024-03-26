#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

// Struct Binary Tree
struct Node
{
    int data;
    struct Node *right;
    struct Node *left;
};

// Membuat Node baru
void newNode(struct Node **ptr, int data)
{
    *ptr = (struct Node *)malloc(sizeof(struct Node));
    (*ptr)->data = data;
    (*ptr)->left = NULL;
    (*ptr)->right = NULL;
}

// Menyisipkan data baru ke dalam Binary Tree
void insert(struct Node **root, int data)
{
    if (*root == NULL)
    {
        newNode(root, data);
    }
    else if (data > (*root)->data)
    {
        insert(&((*root)->right), data);
    }
    else if (data < (*root)->data)
    {
        insert(&((*root)->left), data);
    }
    else
    {
        printf("Data %d sudah ada dalam tree.\n", data);
    }
}

// Mencari node minimum pada sub-pohon
struct Node *find_minimum(struct Node *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    else if (root->left != NULL)
    {
        return find_minimum(root->left);
    }
    return root;
}

// Menghapus data dari pohon biner
void delete(struct Node **root, int data)
{
    if (*root == NULL)
    {
        printf("Data %d tidak ada dalam tree.\n", data);
        return;
    }
    else if (data > (*root)->data)
    {
        delete(&((*root)->right), data);
    }
    else if (data < (*root)->data)
    {
        delete(&((*root)->left), data);
    }
    else
    {
        if ((*root)->left == NULL && (*root)->right == NULL)
        {
            free(*root);
            *root = NULL;
        }
        else if ((*root)->left == NULL || (*root)->right == NULL)
        {
            struct Node *ptr;
            if ((*root)->left == NULL)
            {
                ptr = (*root)->right;
            }
            else
            {
                ptr = (*root)->left;
            }
            free(*root);
            *root = ptr;
        }
        else
        {
            struct Node *ptr = find_minimum((*root)->right);
            (*root)->data = ptr->data;
            delete(&((*root)->right), ptr->data);
        }
    }
}

// Traversal in-order
void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf(" %d |", root->data);
        inorder(root->right);
    }
}

int main()
{
    struct Node *root = NULL;
    int input, data;
    do
    {
        system("cls");
        printf("Menu Binary Tree\n");
        printf("================\n");
        printf("1. View Data (In-Order)\n");
        printf("2. Insert Data\n");
        printf("3. Delete Data\n");
        printf("4. Exit\n");
        printf("Input >> ");
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            system("cls");
            printf("Data View In-Order Traversal :\n");
            inorder(root);
            printf("\n");
            printf("Press any button to continue...\n");
            getch();
            break;
        case 2:
            printf("Input data : ");
            scanf("%d", &data);
            if (root == NULL)
            {
                newNode(&root, data);
            }
            else
            {
                insert(&root, data);
            }
            printf("Press any button to continue...\n");
            getch();
            break;
        case 3:
            printf("Delete data : ");
            scanf("%d", &data);
            delete(&root, data);
            printf("Press any button to continue...\n");
            getch();
            break;
        case 4:
            printf("Thanks for using this program!\n");
            getch();
            break;
        default:
            printf("Invalid input..!\n");
            getch();
            break;
        }
    } while (input != 4);
    return 0;
}
