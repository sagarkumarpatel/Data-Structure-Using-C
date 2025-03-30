#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* prev;
    struct node* next;
};

struct node* createNode(int data){
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    if(newNode==NULL){
        printf("Memory is not allocated!\n");
        exit(1);
    }
    newNode->data=data;
    newNode->prev=NULL;
    newNode->next=NULL;
    return newNode;
}
void display(struct node* head,struct node* tail){
    if(head==NULL){
        printf("List is Empty!, Nothing to Display\n");
        return;
    }
    struct node* temp=head;
    do{
        printf("%d ",temp->data);
        temp=temp->next;
    }
    while(temp!=head);
}

struct node* insertAtFirst(struct node* head,struct node* tail,int data){
    struct node* newNode=createNode(data);
   if(head==NULL){
    head=tail=newNode;
    newNode->prev=newNode;
    newNode->next=newNode;
   }
   newNode->next=head;
   head->prev=newNode;
   newNode->prev=tail;
   tail->next=newNode;
   head=newNode;
   return head;
   
}
struct node* inserAtLast(struct node* head, struct node* tail, int data){
    struct node* newNode=createNode(data);
    if(head==NULL){
        head=tail=newNode;
        newNode->prev=newNode;
        newNode->next=newNode;
       }
    newNode->prev=tail;
    tail->next=newNode;
    newNode->next=head;
    head->prev=newNode;
    tail=newNode;
    return tail;
}

struct node* inserAtPosition(struct node* head,struct node* tail,int data, int position){
    struct node* newNode=createNode(data);
    if(head==NULL){
        head=tail=newNode;
        newNode->prev=tail;
        newNode->next=head;
    }
    if(position<1 ){    //If the loop exits and i is still less than position - 1
        printf("Invalid position!\n");
        return head;
    }
    if(position==1){
        return insertAtFirst(head,tail,data);
    }
    struct node* temp=head;
    int i=1;
    while(i<position-1 && temp->next!=head){
        temp=temp->next;
        i++;
    }
    if (i < position - 1) {                                 
        printf("Position is out of bound\n");
        return head;
    }
    newNode->next=temp->next;
    newNode->prev=temp;
    temp->next->prev=newNode;
    temp->next=newNode;
    return head;
}
struct node* deleteAtFirst(struct node* head, struct node* tail){
    if(head==NULL){
        printf("List is already empty! Nothing to delete\n");
        return NULL;
    }
    struct node* temp=head;
    if(temp->next==head){
        free(temp);
        head=tail=NULL;
        return NULL;
    }
    head=head->next;
    head->prev=tail;
    tail->next=head;
    free(temp);
    return head;
}

struct node* deleteAtLast(struct node* head, struct node* tail){
    if(head==NULL){
        printf("List is already empty! Nothing to delete\n");
        return NULL;
    }
   
    if(head->next==head){
        head=tail=NULL;
        free(head);
        return NULL;
    }
    struct node* temp=tail;
    tail=tail->prev;
    tail->next=head;
    head->prev=tail;
      free(temp);
      return head;
}

struct node* deleteAtPosition(struct node* head,struct node* tail,int position){
    if(head==NULL){
        printf("List is already empty! Nothing to delete\n");
        return NULL;
    }
   
    if(head->next==head){
        free(head);
        return NULL;
    }
    if(position<1){
        printf("Invalid Position!\n");
        return head;
    }
    if(position==1){
        return deleteAtFirst(head,tail);
    }
    struct node* temp=head;
    int i=1;
    while(i<position && temp->next!=head){
        temp=temp->next;
        i++;
    }
    if(i<position){
        printf("Position is out of Bound!\n");
        return head;
    }
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    if(temp->next==head){
        tail=temp->prev;
    }
    free(temp);
    return head;
}

int main(){
    struct node* head=NULL;
    struct node* tail=NULL;
    int data,position,choice;
    do{
        printf("1)display\n");
        printf("2)insertAtFirst\n");
        printf("3)insertAtLast\n");
        printf("4)inserAtPosition\n");
        printf("5)DeleteAtFirst\n");
        printf("6)DeleteAtLast\n");
        printf("7)DeleteAt position\n");
        printf("8)Exit----------------\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("\nCurrent List: ");
            display(head,tail);
            printf("\n===============================================\n");
            break;
            case 2:
                printf("Enter the data for insertAtFirst: ");
                scanf("%d",&data);
                head=insertAtFirst(head,tail,data);
                if(tail==NULL){
                    tail=head;
                }
                printf("\nAfter inserting my list are: ");
                display(head,tail);
                printf("\n==============================================\n");
                break;
                case 3:
                printf("Enter the data for insertAtLast: ");
                scanf("%d",&data);
                tail=inserAtLast(head,tail,data);
                if(head==NULL){
                    head=tail;
                }
                printf("\nAfter inserting my list are: ");
                display(head,tail);
                printf("\n==============================================\n");
                break;
                case 4:
                printf("Enter the data for insertAtLast: ");
                scanf("%d",&data);
                printf("\nEnter the position: ");
                scanf("%d",&position);
                head=inserAtPosition(head,tail,data,position);
                printf("\nAfter inserting my list are: ");
                display(head,tail);
                printf("\n==============================================\n");
                break;
                case 5:
                head=deleteAtFirst(head,tail);
                printf("After delete at first my list are: ");
                display(head,tail);
                printf("\n==================================================\n");
                break;
                case 6:
                head=deleteAtLast(head,tail);
                printf("After delete at Last node, my list are: ");
                display(head,tail);
                printf("\n==================================================\n");
                break;
                case 7:
                printf("Enter your position for delete: ");
                scanf("%d",&position);
                head=deleteAtPosition(head,tail,position);
                printf("\nAfter delete at specific position, my list are: ");
                display(head,tail);
                printf("\n==================================================\n");
                break;
                case 8:
                printf("\n-----------Exit from the program--------------\n");
                break;
                default:
                printf("Invalid choice!\n");
        }

    }while(choice!=8);

    return 0;
}