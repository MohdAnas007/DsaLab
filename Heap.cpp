#include<iostream>
#include<fstream>
using namespace std;

void print(int arr[],int n){
    for(int i=0;i<n;i++)cout<<arr[i]<<" ";

}
void HeapifyUp(int arr[],int index,int n){
    int largest=index;
    int left=2*index+1;
    int right=2*index+2;

    if(left<n && arr[left]>arr[index])largest=left;
    if(right<n && arr[right]>arr[largest]){
        largest=right;
        
    }


    if(largest!=index){
        swap(arr[index],arr[largest]);
        HeapifyUp(arr,largest,n);

    }
}
void BuildHeap(int arr[],int n){
    
    for(int i=n/2-1;i>=0;i--){
        HeapifyUp(arr,i,n);

    }
}
int main(){
    int n=10;

    int *arr=new int[n];
    ifstream file("input.txt");
    int x;
    int i=0;

    while(i<n && file>>x){
        arr[i]=x;
        i++;


    }

    print(arr,n);
    

    return 0;

}