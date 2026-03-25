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
Node* createNode(int val){
    Node*temp=new Node(val);

    return temp;

}

Node* findlastleaf(Node*root){
    if(!root)return NULL;

    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node*temp=q.front();
        q.pop();

        if(!temp->left || !temp->right)return temp;

        q.push(temp->left);
        q.push(temp->right);

    }

    return nullptr;
}
void bubbleUp(Node*newNode){
        Node*curr=newNode;
        if(!curr)return ;
        Node*prev=curr->parent;

        while(prev && prev->parent && prev->data<curr->data){
            swap(curr->data,prev->data);
            curr=prev;
            prev=prev->parent;

        }
}
Node*insert(Node*root,int val){
    if(!root)return new Node(val);


    Node*p=findlastleaf(root);
    Node*newNode=new Node(val);
    if(!p->left ){
        p->left=newNode;

    }
    else p->right=newNode;

    bubbleUp(newNode);
    return root;

}

void print(Node*root){
    if(!root)return ;
    queue<Node*>q;
    q.push(root);
    
    while(!q.empty()){
        Node*temp=q.front();
        q.pop();

        cout<<temp->data<<" ";

        if(temp->left){
            q.push(temp->left);

        }
        if(temp->right){
            q.push(temp->right);
            
        }
    }

}
int main()
{

    Node*root=NULL;
    ifstream file("input.txt");
    int x;

    while(file>>x){
        root=insert(root,x);

    }

    print(root);
return 0;
}