#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_set>
#include<unordered_map>
#include<fstream>

using namespace std;

struct Node{

    int data;   
    Node*left;
    Node*right;
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;

    }
};

Node*insert(Node*root,int val){
    if(!root)return new Node(val);
    if(val<root->data){
        root->left=insert(root->left,val);


    }
    else if(val>root->data){
        root->right=insert(root->right,val);

    }

    return root;

}

void preorder(Node*root){
    if(!root)return;


    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);

}
void level(Node*root){
    queue<Node*>q;
    q.push(root);

    while(!q.empty()){
        Node*temp=q.front();
        q.pop();

        cout<<temp->data<<endl;
        if(temp->left){
            q.push(temp->left);

        }

        if(temp->right){
            q.push(temp->right);

        }
    }
}

int fun(Node*root){
    if(!root)return 0;

    return 1+fun(root->left)+fun(root->right);

}
int size(Node*root){
    if(!root)return 0;

    return 1+(size(root->left),size(root->right));

}
int sum(Node*root){
    if(!root)return 0;
    
    return root->data+sum(root->left)+sum(root->right);

}
int leave(Node*root){
    if(!root)return 0;
    if(!root->left && !root->right)return 1;

    return leave(root->left)+leave(root->right);

}

Node*Tree(ifstream &file){
    int x;
    if(!(file>>x))return NULL;
    if(x==-1)return NULL;



    Node*temp=new Node(x);
    temp->left=Tree(file);
    temp->right=Tree(file);
    return temp;

}

int main()
{
    ifstream file("input.txt");

    Node*root=Tree(file);
    preorder(root);


return 0;
}