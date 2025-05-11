#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *Right;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->Right = NULL;
    return newNode;
}

struct Node *inserting(struct Node *Root, int data)
{
    if (Root == NULL)
    {
        return createNode(data);
    }
    else
    {
        if (Root->data == data)
        {
            printf("Duplicate value\n");
            return Root;
        }

        else if (data < Root->data)
        {
            Root->left = inserting(Root->left, data);
        }
        else
        {
            Root->Right = inserting(Root->Right, data);
        }
    }
    return Root;
}

void displayInOrder(struct Node *Root)
{
    if (Root == NULL)
    {
        return;
    }
    else
    {
        displayInOrder(Root->left);
        printf("%d ", Root->data);
        displayInOrder(Root->Right);
    }
}

void displayPreOrder(struct Node *Root)
{
    if (Root == NULL)
    {
        return;
    }
    else
    {
        printf("%d ", Root->data);
        displayInOrder(Root->left);
        displayInOrder(Root->Right);
    }
}
void displayPostOrder(struct Node *Root)
{
    if (Root == NULL)
    {
        return;
    }
    else
    {
        displayInOrder(Root->left);
        displayInOrder(Root->Right);
        printf("%d ", Root->data);
    }
}

int getMin(struct Node *Root)
{
    if (Root->left == NULL)
    {
        return Root->data;
    }
    else
    {
        return getMin(Root->left);
    }
}

int getMax(struct Node *Root)
{
    if (Root->Right == NULL)
    {
        return Root->data;
    }
    else
    {
        return getMin(Root->Right);
    }
}

struct Node *DeleteNode(struct Node *Root, int data)
{
    if (Root == NULL)
    {
        return NULL;
    }
    else if (data < Root->data)
    {
        Root->left = DeleteNode(Root->left, data);
    }
    else if (data > Root->data)
    {
        Root->Right = DeleteNode(Root->Right, data);
    }
    else
    {
        if (Root->left == NULL && Root->Right == NULL)
        {
            return NULL;
        }
        else if (Root->left == NULL)
        {
            return Root->Right;
        }
        else if (Root->Right == NULL)
        {
            return Root->left;
        }
        else
        {
            int sucessor = getMax(Root->left);
            Root->data = sucessor;
            Root->left = DeleteNode(Root->left, sucessor);
            return Root;
        }
    }
}
int main()
{
    struct Node *Root = NULL;
    int data, choice, max, min;

    do
    {
        printf("1)Insert\n");
        printf("2)InOrder\n");
        printf("3)PreOrder\n");
        printf("4)PostOrder\n");
        printf("5)GetMin\n");
        printf("6)GetMax\n");
        printf("7)Delete Node\n");
        printf("8)Exit\n");
        printf("Enter the choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the value to insert: ");
            scanf("%d", &data);
            Root = inserting(Root, data);
            printf("\n=====================================================\n");
            break;
        case 2:
            displayInOrder(Root);
            printf("\n=====================================================\n");
            break;

        case 3:
            displayPreOrder(Root);
            printf("\n=====================================================\n");
            break;

        case 4:
            displayPostOrder(Root);
            printf("\n=====================================================\n");
            break;

        case 5:
            min = getMin(Root);
            printf("\nThe min value is: %d", min);
            break;

        case 6:
            max = getMax(Root);
            printf("\nThe max value is: %d", max);
            break;
        case 7:
            printf("Enter the data for deleting: ");
            scanf("%d", &data);
            Root = DeleteNode(Root, data);
            printf("\n=======================================================\n");
            break;

        case 8:
            printf("\n-----------Exit-------------------\n");
            break;
        default:
            printf("Invalid Choice\n");
        }
    } while (choice >= 1 && choice <= 7);
    return 0;
}