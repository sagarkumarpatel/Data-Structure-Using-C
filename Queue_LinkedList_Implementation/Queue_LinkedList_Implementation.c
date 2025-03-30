#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct Queue{
    struct node* front;
    struct node* rear;
};

struct node* createNode(struct node* data){
     struct node* newNode=(struct node*)malloc(sizeof(struct node));
     newNode->data=data;
     newNode->next=NULL;
     return newNode;
}

struct Queue* createQueue(){
     struct Queue* q=(struct Queue*)malloc(sizeof(struct Queue));
     q->front=NULL;
     q->rear=NULL;
     return q;
}

int isEmpty(struct Queue* q){
    if(q->front==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

void enqueue(struct Queue* q,int data){
     struct node* newNode=createNode(data);
     if(q->front==NULL){
        q->front=newNode;
        q->rear=newNode;
     }
     q->rear->next=newNode;
     q->rear=newNode;
}

int dequeue(struct Queue* q){
    if(isEmpty(q)){
        return -99999;
    }
    struct node* temp=q->front;
    q->front=q->front->next;
    free(temp);
    return temp->data;
}

int getFront(struct Queue* q){
    if(isEmpty(q)){
        return -99999;
    }
    return q->front->data;
}

int getRear(struct Queue* q){
    if(isEmpty(q)){
        return -99999;
    }
    return q->rear->data;
}

void display(struct Queue* q){
    if(isEmpty(q)){
        printf("Queue is Empty!, Nothing to display\n");
    }
    struct node* temp=q->front;
    while(temp!=NULL){
        printf("%d ",temp->data);
       temp=temp->next;
    }
}

int main(){
    return 0;
}