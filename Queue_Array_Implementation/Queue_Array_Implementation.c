#include<stdio.h>
#include<stdlib.h>

struct Queue{
    int size;
    int front;
    int rear;
    int * arr;
};
struct Queue* createQueue(int size){
    struct Queue* q=(struct Queue*)malloc(sizeof(struct Queue));
    q->size=size;
    q->front=q->rear=-1;
    q->arr=(int*)malloc(size*sizeof(int));
    return q;
}

int isFull(struct Queue *q){
    if(q->rear==q->size-1){
        return 1;
    }
    else{
        return 0;
    }
}

int isEmpty(struct Queue *q){
    if(q->front==-1){
        return 1;
    }
    else{
        return 0;
    }
}

void enqueue(struct Queue* q, int data){
    if(isFull(q)){
        printf("Queue is full\n");
        return;
    }
    else{
        if(q->rear==-1){
            q->front=0;
            q->rear=0;
            q->arr[q->rear]=data;
        }
        else{
            q->rear++;
            q->arr[q->rear]=data;
        }
    }
}

int dequeue(struct Queue* q){
    if(isEmpty(q)){
        printf("Queue is empty\n");
        return -99999;
    }
    else{
        int value=q->arr[q->front];
        if(q->front==q->rear){
            q->front=q->rear=-1;
        }
        else{
            q->front++;
        }
        return value;
    }
}

int getRear(struct Queue* q){
    if(isEmpty(q)){
        printf("Queue is Empty\n");
        return -99999;
    }
    return q->arr[q->rear];
}

int getFront(struct Queue* q){
    if(isEmpty(q)){
        printf("Queue is Empty\n");
        return -99999; 
    }
    return q->arr[q->front];
}

void display(struct Queue* q){
    if(isEmpty(q)){
      printf("Queue is Empty\n");
      return;
    }
    for(int i=q->front;i<=q->rear;i++){
        printf("%d ",q->arr[i]);
    }
}

int main(){
struct Queue* q=NULL;
int size,choice,data;
printf("Enter the size of the Queue: ");
scanf("%d",&size);
q=createQueue(size);
do{
    printf("\n1)Display\n");
    printf("2)isEmpty\n");
    printf("3)isFull\n");
    printf("4)enQueue\n");
    printf("5)deQueue\n");
    printf("6)getRear\n");
    printf("7)getFront\n");
    printf("----8)Exit from the program----\n");
    printf("Enter your choice: ");
    scanf("%d",&choice);
    switch(choice){
        case 1:
        printf("\nThe data of the Queue: ");
        display(q);
        printf("\n==================================\n");
        break;
        case 2:
         if(isEmpty(q)==1){
            printf("Queue is Empty\n");
         }else{
            printf("Queue is not Empty\n");
         }
      
        printf("\n===================================\n");
        break;
        case 3:
        if(isFull(q)==1){
            printf("Queue is Full\n");
        }
        else{
            printf("Queue is not Full\n");
        }
        printf("\n===================================\n");
        break;
        case 4:
        printf("Enter your Data: ");
        scanf("%d",&data);
        enqueue(q,data);
        printf("\nThe data of the Queue after enQueue: ");
        display(q);
        printf("\n=========================================\n");
        break;
        case 5:
        data=dequeue(q);
        if(data!=-99999){
            printf("The deQueue data is: %d",data);
        }
        printf("\nThe data of the Queue after deQueue: ");
        display(q);
        printf("\n=========================================\n");
        break;
        case 6:
        data=getRear(q);
        if(data!=-99999){
        printf("The Rare of the Queue is: %d ",data);
        }
        printf("\n=======================================\n");
        break;
        case 7:
        data=getFront(q);
        if(data!=-99){
        printf("The Front of the Queue is: %d",data);
        }
        printf("\n======================================\n");
        break;
        case 8:
        printf("You are Out of the Program\n");
        printf("\n=======================================\n");
        break;
        default:
        printf("Invalid Choice!\n");
    }
}while(choice>=1 &&choice<=8);
return 0;
}