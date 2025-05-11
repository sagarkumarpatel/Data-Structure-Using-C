#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct Queue
{
    struct node *front;
    struct node *rear;
};

struct node *createNode(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Queue *createQueue()
{
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

int isEmpty(struct Queue *q)
{
    if (q->front == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueue(struct Queue *q, int data)
{
    struct node *newNode = createNode(data);
    if (q->front == NULL)
    {
        q->front = newNode;
        q->rear = newNode;
    }
    else{
    q->rear->next = newNode;
    q->rear = newNode;
    }
}

int dequeue(struct Queue *q)
{
    if (isEmpty(q))
    {
        return -99999;
    }
    struct node *temp = q->front;
    int data=temp->data;
    q->front = q->front->next;
    if(q->front==NULL){
        q->rear=NULL;
    }
    free(temp);
    return data;
}

int getFront(struct Queue *q)
{
    if (isEmpty(q))
    {
        return -99999;
    }
    return q->front->data;
}

int getRear(struct Queue *q)
{
    if (isEmpty(q))
    {
        return -99999;
    }
    return q->rear->data;
}

void display(struct Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is Empty!, Nothing to display\n");
        return;
    }
    struct node *temp = q->front;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main()
{
    struct Queue *q = createQueue();
    int data, choice;
    do
    {
        printf("1)Display\n");
        printf("2)isEmpty\n");
        printf("3)enQueue\n");
        printf("4)deQueue\n");
        printf("5)getFront\n");
        printf("6)getRear\n");
        printf("7)-----Exit-----\n");
        printf("Enter the choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            display(q);
            printf("\n===================================================\n");
            break;

        case 2:
            if (isEmpty(q))
            {
                printf("\nQueue is Empty\n");
            }
            else{
                printf("Queue is not Empty\n");
            }
            printf("\n===================================================\n");
            break;

        case 3:
            printf("Enter the data: ");
            scanf("%d", &data);
            enqueue(q, data);
            printf("\nThe data of the Queue after enQueue is: ");
            display(q);
            printf("\n===================================================\n");
            break;

        case 4:
            data = dequeue(q);
            if (data != -99999)
            {
                printf("The dequeue data is: %d", data);
            }
            else
            {
                printf("Queue is Empty\n");
            }
            printf("\nThe data of the Queue after deQueue is: ");
            display(q);
            printf("\n===================================================\n");
            break;

        case 5:
            data = getFront(q);
            if (data != -99999)
            {
                printf("The front data is: %d", data);
            }
            else
            {
                printf("Queue is Empty\n");
            }
            printf("\n===================================================\n");
            break;

        case 6:
            data = getRear(q);
            if (data != -99999)
            {
                printf("The last(rear) data is: %d", data);
            }
            else
            {
                printf("Queue is Empty\n");
            }
            printf("\n===================================================\n");
            break;

        case 7:
            printf("----Exit of the program-------\n");
            printf("\n===================================================\n");
            break;
        default:
            printf("Invalid Choice!\n");
        }
    } while (choice >= 1 && choice <= 7);
    return 0;
}