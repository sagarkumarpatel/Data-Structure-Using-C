#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *createNode(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void display(struct node *tail)
{
    if (tail == NULL)
    {
        printf("List is Empty\n");
        return;
    }
    else
    {
        struct node *temp = tail->next; // Starting from the first node, tail->next means head
        do
        {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != tail->next);
    }
}

struct node *insertAtFirst(struct node *tail, int data)
{
    struct node *newNode = createNode(data);
    if (tail == NULL)
    {
        newNode->next = newNode;
        return newNode;
    }
    newNode->next = tail->next;
    tail->next = newNode;
    return tail;
}
struct node *InsertAtLast(struct node *tail, int data)
{
    struct node *newNode = createNode(data);
    if (tail == NULL)
    {
        newNode->next = newNode;
        return newNode;
    }
    else
    {
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    }
    return tail;
}
struct node *InsertAtindex(struct node *tail, int data, int index)
{
    if (index < 0)
    {
        printf("Invalid! Index\n");
        return tail;
    }
    if (index == 0)
    {
        return insertAtFirst(tail, data);
    }
    if (tail == NULL)
    {
        printf("List is empty. Inserting at index 0.\n");
        return insertAtFirst(tail, data);
    }
    struct node *temp = tail->next; // tail->next means head node
    int i = 0;
    while (i != index - 1 && temp->next!=tail->next)
    {
        temp = temp->next;
        i++;
    }
    if(i!=index-1){
        printf("Index is out of bound! Inserting at the end\n");
        return InsertAtLast(tail,data);
    }
    struct node *newNode = createNode(data);
    newNode->next = temp->next;
    temp->next = newNode;
    if (tail == temp)
    {
        tail = newNode;
    }
    return tail;
}

struct node* deleteAtFirst(struct node* tail){
    if(tail==NULL){
        printf("List is empty! Nothing to delete\n");
        return NULL;
    }
    if(tail->next==tail){
        free(tail);
        return NULL;
    }
    struct node* head=tail->next;
    tail->next=tail->next->next;
    free(head);
    return tail;
}
struct node* deleteAtLast(struct node* tail){
    if(tail==NULL){
        printf("List is already empty!, Nothing to delete\n");
        return NULL;
    }
    if(tail->next==tail){
        free(tail);
        return NULL;
    }
    struct node* temp1=tail->next;
    struct node* temp2=tail->next;

    while(temp2->next!=tail->next){
        temp1=temp2;
        temp2=temp2->next;
    }
    temp1->next=tail->next;
    tail=temp1;
    free(temp2);
    return tail;
}

struct node* deleteAtIndex(struct node* tail,int index){
    if(index<0){
        printf("Invalid Index!\n");
        return tail;
    }
    if(tail==NULL){
        printf("List is already empty!, Nothing to delete\n");
        return NULL;
    }
    if(tail->next==tail){
        if(index==0){
        free(tail);
        return NULL;
        }
        else{
            printf("position is out of bound\n");
            return tail;
        }
    }
    struct node* temp1=tail;
    struct node* temp2=tail->next;
    int i=0;
while(i != index && temp2!=tail){
    temp1=temp2; 
    temp2=temp2->next;
    i++;
}
if(i!=index){
    printf("Position is out of bound\n");
    return tail;
}
temp1->next=temp2->next;
if(temp2==tail){
    tail=temp1; 
}
free(temp2);
return tail;
}


int main()
{
    struct node *tail = NULL;
    int data, choice, index;
    do
    {
        printf("1) Display the data of List\n");
        printf("2) InsertAtFirst \n");
        printf("3) InserAtLast\n");
        printf("4) InsertAtIndex\n");
        printf("5)DeletaAtFirst\n");
        printf("6)DeletaAtLast\n");
        printf("7)deleteAtIndex\n");
        printf("8) Exiting from the program\n");
        printf("Enter your choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            display(tail);
            break;
        case 2:
            printf("Enter your data for inserting at first: \n");
            scanf("%d", &data);
            printf("your data after inserting at first: ");
            tail = insertAtFirst(tail, data);
            display(tail);
            printf("\n-----------------------------------------------\n");
            break;
        case 3:
            printf("enter your data for inserting at Last: \n");
            scanf("%d", &data);
            tail = InsertAtLast(tail, data);
            printf("Your data after inserting at Last: ");
            display(tail);
            printf("\n-----------------------------------------------\n");
            break;
        case 4:
            printf("enter your data for inserting at index: \n");
            scanf("%d", &data);
            printf("enter your index for inserting: \n");
            scanf("%d", &index);
            tail = InsertAtindex(tail, data, index);
            printf("Your data after inserting at index: ");
            display(tail);
            printf("\n-----------------------------------------------\n");
            break;
            case 5:
            tail=deleteAtFirst(tail);
            printf("After deleting the first node, My list are: ");
            display(tail);
            printf("\n===================================================\n");
            break;
            case 6:
            tail=deleteAtLast(tail);
            printf("After deleting the Last node, My list are: ");
            display(tail);
            printf("\n===================================================\n");
            break;
            case 7:
            printf("Enter your index for delete\n");
            scanf("%d",&index);
            tail=deleteAtIndex(tail,index);
            printf("After deleting at index, My list are: ");
            display(tail);
            printf("\n===================================================\n");
            
        case 8:
            printf("Exited from the program\n");
            break;
        default:
            printf("Invalid! Choice\n");
        }
    } while (choice != 8);

    return 0;
}