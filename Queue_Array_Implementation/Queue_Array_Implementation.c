#include<stdio.h>
#include<stdlib.h>

struct Queue{
    int size;
    int font;
    int rear;
    int * arr;
};
struct Queue* createQueue(int size){
    struct Queue* q=(struct Queue*)malloc(sizeof(struct Queue));
    q->font=q->rear=-1;
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
    if(q->font==-1){
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
            q->font=0;
            q->rear=0;
            q->arr[q->rear]=data;
        }
        else{
            q->rear++;
            q->arr[q->rear]=data;
        }
    }
}



int main(){

}