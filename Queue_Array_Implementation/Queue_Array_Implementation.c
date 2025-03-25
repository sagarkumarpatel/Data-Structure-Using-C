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


int main(){

}