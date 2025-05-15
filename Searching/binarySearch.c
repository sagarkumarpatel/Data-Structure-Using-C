#include<stdio.h>
int binaryS(int arr[],int low, int high, int key){
    if(low>high){
        return -1;
    }
    int mid=(low+high)/2;
if(arr[mid]==key){
    return mid;
}
else if(key<arr[mid]){
    return binaryS(arr,low,mid-1,key);
}
else{
    return binaryS(arr,mid+1,high,key);
}

}

int main(){
int arr[]={10,20,30,40,50};
int size=sizeof(arr)/sizeof(arr[0]);
int key=50;
int result=binaryS(arr,0,size-1,key);
if(result==-1){
    printf("Value is not Found");
}
else{
    printf("The value is found at index: %d",result);
}
    return 0;
}