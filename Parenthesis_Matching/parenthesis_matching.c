#include<stdio.h>
#include<stdlib.h>

struct stack{
    int top;
    int size;
    char *arr;

};
 
struct stack* createStack(int size){
    struct stack* s=(struct stack*)malloc(sizeof(struct stack));
    if(s==NULL){
        printf("Memory allocation failed!\n");
        exit(1);
    }
    s->top=-1;
    s->size=size;
    s->arr=(char*)malloc(size * sizeof(char));
    return s;
}
int isFull(struct stack* s){
    if(s->top==s->size-1){
        printf("Stack Overflow\n");
        return 1;
    }
    else{
        return 0;
    }
}
int isEmpty(struct stack* s){
    if(s->top==-1){
        printf("Stack Underflow!\n");
        return 1;
    }
    else{
        return 0;
    }
}

void push(struct stack* s,char ch){
    if(isFull(s)){
        printf("Stack overFlow!, Cann't push\n");
        return;
    }
    s->top++;
    s->arr[s->top]=ch;
}
 
char pop(struct stack* s){
    if(isEmpty(s)){
        printf("Stack UnderFlow!, cannot pop\n");
        return '\0';
    }
    return s->arr[s->top--];
}

int isMatching(char opening,char closing){
    if(opening=='('&& closing==')'){
        return 1;
    }
    if(opening=='{'&& closing=='}'){
        return 1;
    }
    if(opening=='['&& closing==']'){
        return 1;
    }
    return 0;
}
int isBalance(char* expresion){
    struct stack* s=createStack(100);
    for(int i=0;expresion[i]!='\0';i++){
        if(expresion[i]=='('||expresion[i]=='{'||expresion[i]=='['){
            push(s,expresion[i]);
        }
        else if(expresion[i]==')'||expresion[i]=='}'||expresion[i]==']'){
            if(isEmpty(s)||!isMatching(pop(s),expresion[i])){
                return 0;
            }
        }
    }
    return isEmpty(s);
}

int main(){
  char expresion[100];
  printf("Enter your expression: ");
  scanf("%s",expresion);
  if(isBalance(expresion)){
    printf("\nThe parenthesis is balance\n");
  }
  else{
    printf("The parenthesis is not balance\n");
  }

    return 0;
}