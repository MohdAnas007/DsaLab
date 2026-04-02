#include<iostream>
#include<fstream>
using namespace std;
struct Node{
    int data;
    Node*left,*right;
    Node(int val){
        data=val;
        left=right=NULL;

    }
};


Node*insert(Node*root,int x){
    if(!root)return new Node(x);
    if(x>root->data){
       root->right= insert(root->right,x);

    }
    if(x<root->data){
        root->left=insert(root->left,x);

    }

    return root;

}

void print(Node*root){
    if(!root)return ;

    cout<<root->data<<" ";

    print(root->left);
    print(root->right);

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
int find(Node*root){
    if(!root->left)return root->data;
    Node*curr=root->left;

    while(curr->right!=NULL){
        curr=curr->right;

    }

    return curr->data;

    
}
int find2(Node*root){
    if(!root->right)return root->data;
    Node*curr=root->right;

    while(curr->left){
        curr=curr->left;

    }
    return curr->data;

}
bool check(Node*root){
    if(!root)return 1;

    int left=find(root);
    int  right=find2(root);

    if(root->data<left || root->data>right)return 0;

    return check(root->left)&&check(root->right);

}
bool check2(Node*root,long long  left,long long  right){
    if(!root)return true;
    if(root->data<=left || root->data>=right)return false;

    return check2(root->left,left,root->data)&& check2(root->right,root->data,right);


}
int main(){
    ifstream file("input.txt");
    int x;
    Node*root=NULL;

    while(file>>x){
        root=insert(root,x);

    }

    cout<<check2(root,LLONG_MIN,LLONG_MAX);




    return 0;

}