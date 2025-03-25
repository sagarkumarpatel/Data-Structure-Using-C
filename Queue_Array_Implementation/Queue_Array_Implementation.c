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
    q->font=-1;
    q->rear=-1;
    q->arr=(int*)malloc(size*sizeof(int));
    return q;
}



int main(){

}