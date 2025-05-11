#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int front;
    int rear;
    int *arr;
};
struct Queue *createQueue(int size)
{
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    q->front = -1;
    q->rear = -1;
    q->arr = (int *)malloc(size * sizeof(int));
    return q;
}

int isFull(struct Queue *q)
{
    if ((q->rear + 1) % q->size == q->front)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty(struct Queue *q)
{
    if (q->front == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enQueue(struct Queue *q, int data)
{
    if (isFull(q))
    {
        printf("Queue is Full!\n");
        return;
    }
    if (q->rear == -1 && q->front == -1)
    {
        q->front = 0;
        q->rear = 0;
        q->arr[q->rear] = data;
    }
    else
    {
        q->rear = (q->rear + 1) % q->size;
        q->arr[q->rear] = data;
    }
}

int deQueue(struct Queue *q)
{
    if (isEmpty(q))
    {
        return -99999;
    }
    int data = q->arr[q->front];
    if (q->front == q->rear)
    {
        q->front = q->rear = -1;
    }
    else
    {
        q->front = (q->front + 1) % q->size;
    }
    return data;
}
int getFront(struct Queue *q)
{
    if (isEmpty(q))
    {
        return -99999;
    }
    return q->arr[q->front];
}

int getRear(struct Queue *q)
{
    if (isEmpty(q))
    {
        return -99999;
    }
    return q->arr[q->rear];
}
void display(struct Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is Empty!\n");
        return;
    }
    int i = q->front;
    // do
    // {
    //     printf("%d ", q->arr[i]);
    //     i=(i + 1) % q->size;
    // } while (i != q->rear);
    while(i!=q->rear){
        printf("%d ",q->arr[i]);
        i=(i + 1) % q->size;
    }
    printf("%d",q->arr[q->rear]);
}

int main()
{
    int data, size, choice;
    printf("Enter your size: ");
    scanf("%d", &size);
    struct Queue *q = createQueue(size);

    do
    {
        printf("1)isEmpty\n");
        printf("2)isFull\n");
        printf("3)enQueue\n");
        printf("4)deQueue\n");
        printf("5)getFront\n");
        printf("6)getRear\n");
        printf("7)Display\n");
        printf("8)----Exit-----\n");
        printf("Enter the Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            if (isEmpty(q))
            {
                printf("Queue is Empty\n");
            }
            else
            {
                printf("Queue is not Empty\n");
            }
            printf("\n==============================================\n");
            break;
        case 2:
            if (isFull(q))
            {
                printf("Queue is Full\n");
            }
            else
            {
                printf("Queue is not Full\n");
            }
            printf("\n==============================================\n");
            break;

        case 3:
            printf("Enter the data: ");
            scanf("%d", &data);
            enQueue(q, data);
            printf("\nThe data of the after enQueue: ");
            display(q);
            printf("\n==============================================\n");
            break;

        case 4:
            data = deQueue(q);
            if (data != -99999)
            {
                printf("The deQueue data is %d:", data);
            }
            printf("\nThe data of the after deQueue: ");
            display(q);
            printf("\n==============================================\n");
            break;
        case 5:
            data = getFront(q);
            if (data != -99999)
            {
                printf("The front data is %d:", data);
            }
            else
            {
                printf("Queue is Empty\n");
            }
            printf("\n==============================================\n");
            break;
        case 6:
            data = getRear(q);
            if (data != -99999)
            {
                printf("The Last data is %d:", data);
            }
            else
            {
                printf("\nQueue is Empty\n");
            }
            break;
            printf("\n==============================================\n");

        case 7:
            printf("---------Exit---------\n");
            break;
            printf("\n==============================================\n");
        default:
            printf("Invalid choice!\n");
        }
    } while (choice >= 1 && choice <= 7);
    return 0;
}
