#include<iostream>
#include<fstream>
using namespace std;

class Heap{
    int *arr;
    int totalsize;
    int size;
    public:

    Heap(int n){
        arr=new int[n];
        totalsize=n;
        size=0;
    }

    void insert(int val){
       if(size>=totalsize){
        cout<<"heap is overflown\n ";
        return;
       }
         arr[size]=val;
        size++;

        checkHeap(size-1);

        return;


      

    }

    void checkHeap(int index){
        while(index>0){
            int parent=(index-1)/2;
            if(arr[index]>arr[parent]){
                swap(arr[index],arr[parent]);
                index=parent;

            }
            else break;

        }
    }

    void  print(){
        for(int i=0;i<size;i++)cout<<arr[i]<<" ";

    }
};


int main(){
 
    ifstream file("input.txt");
    int x;
    Heap h1(5);

    while((file>>x)){
         h1.insert(x);

    }
    h1.print();





    return 0;



}