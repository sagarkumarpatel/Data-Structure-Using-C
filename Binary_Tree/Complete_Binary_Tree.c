#include<stdio.h>
#include<stdlib.h>
int main(){
    int size,choice,index;
    printf("Enter the Size of complete binary tree: ");
    scanf("%d",&size);
    int* arr=(int*)malloc((size+1)*sizeof(int));
    arr[0]=0;
    for(int i=1;i<=size;i++){
        printf("Enter Value at index %d: ",i);
        scanf("%d",&arr[i]);
    }
    do{
printf("\n1) Left child\n");
printf("2) Right child\n");
printf("3) Left & right child\n");
printf("5) Exit\n");
printf("Enter your choice: ");
scanf("%d",&choice);
switch(choice){
    case 1:
    printf("Enter the parent index: ");
    scanf("%d",&index);
    printf("\nLeft child index: %d: ",index*2);
    printf("\nLeft child value: %d: ",arr[index*2]);
    printf("\n=================================================\n");
    break;

    case 2:
    printf("\nEnter the parent index: ");
    scanf("%d",&index);
    printf("\nRight child index: %d",(index*2)+1);
    printf("\nRight child value: %d",arr[(index*2)+1]);
    printf("\n=================================================\n");
    break;

    case 3:
    printf("Enter the parent index: ");
    scanf("%d",&index);
    printf("\nLeft child index: %d: ",index*2);
    printf("\nLeft child value: %d: ",arr[index*2]);
    printf("\nRight child index: %d",(index*2)+1);
    printf("\nRight child value: %d",arr[(index*2)+1]);
    printf("\n=================================================\n");
    break;
    case 4:
    printf("Enter the Child index: ");
    scanf("%d",&index);
    printf("\nParent index: %d",index/2);
    printf("\nParent value: %d",arr[index/2]);
    printf("\n=================================================\n");
    break;
    case 5:
    printf("\n--------------------Exit------------\n");
    break;
}
    }while(choice>=1 && choice<=5);
    return 0;
}