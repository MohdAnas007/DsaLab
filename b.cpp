#include<iostream>
#include<fstream>
#include<queue>
using namespace std;

struct Node{
    int data;
    Node*left;
    Node*right;
    Node*parent;
    Node(int val){
        data=val;
        left=right=NULL;
        parent=NULL;


    }
};


Node*findPos(Node*root){
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

    return root;

}

void bubbleUp(Node*curr){
    if(!curr)return ;
    Node*prev=curr->parent;

    while(prev && prev->data<curr->data){
        swap(prev->data,curr->data);

        curr=prev;
        prev=prev->parent;

    }

}
Node*insert(Node*root,int val){
    if(!root)return new Node(val);

    Node*temp=findPos(root);
    Node*newNode=new Node(val);
    newNode->parent=temp;

    if(!temp->left )
    temp->left=newNode;
    else temp->right=newNode;

    bubbleUp(newNode);


    return root;



}
Node*rightmostLeafNode(Node*root){
    if(!root)return NULL;
    queue<Node*>q;
    q.push(root);
    Node*last=NULL;


    while(!q.empty()){
        Node*curr=q.front();

        q.pop();
        last=curr;
        if(curr->left){
            q.push(curr->left);

        }
        if(curr->right){
            q.push(curr->right);

        }


    }

    return last;

}
void fix(Node*root){
    if(!root)return ;
    Node*curr=root;

    while(curr){
       Node*largest=curr;
       if(curr->left && curr->left->data>largest->data){
        largest=curr->left;

       }

       if(curr->right && curr->right->data>largest->data){
        largest=curr->right;

       }

       if(largest==curr)break;

       swap(curr->data,largest->data);
       curr=largest;


    }
}
void deleteNode(Node*root){
    if(!root)return ;

    Node*temp=rightmostLeafNode(root);
   // if only one node
    if(temp==root){
            delete root;
            root=NULL;
            return;

    }
    swap(temp->data,root->data);

    Node*p=temp->parent;
    if(p->left==temp)p->left=NULL;
    else p->right=NULL;

    fix(root);




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
    ifstream file("input.txt");

    Node*root=NULL;
    int x;


    while(file>>x){
        root=insert(root,x);


    }
    print(root);
    cout<<endl;
    deleteNode(root);
    print(root);
    deleteNode(root);
    cout<<endl;
    
    print(root);




    




return 0;
}