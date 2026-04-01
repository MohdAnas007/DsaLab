#include<iostream>
#include<fstream>
using namespace std;
struct Node{
    int data;
    Node*left;
    Node*right;
    Node*parent;
    Node(int val){
        data=val;
        left=right=parent=NULL;

    }
};
void bubbleup(Node*curr){
    if(!curr)return ;
    Node*prev=curr->parent;

    while(prev && prev->data<curr->data){
        swap(curr->data,prev->data);
        curr=prev;
        prev=prev->parent;

    }
}
Node*findpos(Node*root){
    if(!root)return NULL;
    queue<Node*>q;
    q.push(root);

    while(!q.empty()){

        Node*top=q.front();
        q.pop();

        if(!top->left || !top->right)return top;
        if(top->left)q.push(top->left);
        if(top->right)q.push(top->right);

    }

    return root;

}
Node*insert(Node*root,int x){
    if(!root)return new Node(x);


    Node*temp=findpos(root);
    Node*newNode=new Node(x);
    newNode->parent=temp;

    if(!temp->left)temp->left=newNode;
    else temp->right=newNode;


    bubbleup(newNode);

    return root;

}

void level(Node*root){
    if(!root)return;

    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node*temp=q.front();
        q.pop();

        cout<<temp->data<<" ";
        if(temp->left)q.push(temp->left);
        if(temp->right)q.push(temp->right);

    }
}
Node*findrightmostLeaf(Node*root){
    if(!root)return NULL;
    queue<Node*>q;

    q.push(root);
    Node*last=NULL;

    while(!q.empty()){
        Node*curr=q.front();
        last=curr;
        q.pop();

        if(curr->left)q.push(curr->left);
        if(curr->right)q.push(curr->right);


    }

    return last;

}
void HeapSort(Node*root,int *arr,int index){

    if(!root)return ;
    Node*temp=findrightmostLeaf(root);
    if(root==temp){
        arr[index]
    }

}

int main(){
    ifstream file("input.txt");

    int x;
    Node*root=NULL;

    while(file>>x){
        root=insert(root,x);

    }
    level(root);

    int *arr=new int[100];
    fill(arr,arr+100,0);
    HeapSort(root,arr,0);
    



    return 0;

}