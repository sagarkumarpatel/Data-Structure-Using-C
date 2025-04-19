#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    int height;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->height=1;
    newNode->left=newNode->right=NULL;
    return newNode;
}

int height(struct Node* N){

    if(N==NULL){
        return 0;
    }
    return N->height;
}

int max(int a, int b){
    return (a>b)?a:b;
}

struct Node* rightRotation(struct Node* unBalancedNode){
    struct Node* x=unBalancedNode->left;
    struct Node* y=x->right;

   x->right=unBalancedNode;
   unBalancedNode->left=y;

   unBalancedNode->height=1+max(height(unBalancedNode->left),height(unBalancedNode->right));

   x->height=1+max(height(x->left),height(x->right));

   return x;
}

struct Node* leftRotation(struct Node* unBalancedNode){
    struct Node* x=unBalancedNode->right;
    struct Node* y=x->left;

    x->left=unBalancedNode;
    unBalancedNode->right=y;

    unBalancedNode->height=1+max(height(unBalancedNode->left),height(unBalancedNode->right));

    x->height=1+max(height(x->left),height(x->right));

    return x;
}

int getBalance(struct Node* N){
    if(N==NULL){
        return 0;
    }
    return height(N->left)-height(N->right);
}

struct Node* insertion(struct Node* node,int data){
    // Perform the normal BST insertion
    if(node==NULL){

        return createNode(data);
    }
    if(data<node->data){
        node->left=insertion(node->left,data);
    }
    else if(data>node->data){
        node->right=insertion(node->right,data);
    }
    else{    // Equal keys are not allowed in BST
        return node;
    }
    //Update height of this ancestor node(an ancestor is any node that lies above another node)
node->height=1+max(height(node->left),height(node->right));

int balance=getBalance(node);
// Left Left Case
if(balance>1 && data <node->left->data){
    return rightRotation(node);
}
// Right Right Case
if(balance<-1 && data>node->right->data){
return leftRotation(node);
}
// Left Right Case
if(balance>1 && data>node->left->data){
    node->left=leftRotation(node->left);
    return rightRotation(node);
}

  // Right Left Case
if(balance<-1 && data<node->right->data){
    node->right=rightRotation(node->right);
  return leftRotation(node);
}
return node;
}

void preOrder(struct Node* Root){
    if(Root!=NULL){
   printf("%d ",Root->data);
   preOrder(Root->left);
   preOrder(Root->right);
        
    }
}

int main(){
struct Node* Root=NULL;
int data, choice;
do{
    printf("1)Insetion\n");
    printf("2)----exit------\n");
    printf("Enter the choice: ");
    scanf("%d",&choice);
    switch(choice){
        case 1:
        printf("\nEnter the data: ");
        scanf("%d",&data);
        Root=insertion(Root,data);
        printf("\n The data after insertion: ");
        preOrder(Root);
        printf("\n========================================\n");
        break;
    case 2:
    printf("\n-----------------------Exit-------------");
    break;
    default:
    printf("Invalid choice\n");
    }
}while(choice>=1 && choice<=2);
return 0;
}