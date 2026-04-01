#include<iostream>
#include<fstream>

using namespace std;
struct Node{
    int data;
    Node*left;
    Node*right;

    Node(int val){
        data=val;
        left=right=NULL;

    }
};


Node*insert(ifstream &file){
    int x;

    if(!(file>>x))return NULL;
    if(x==-1)return NULL;

    Node*temp=new Node(x);
    temp->left=insert(file);
    temp->right=insert(file);
    return temp;

}

void print(Node*root){
    if(!root)return ;
    cout<<root->data<<" ";
    print(root->left);
    print(root->right);

}

Node*fun(Node*r1,Node*r2){
    if(!r1 || !r2)return NULL;

    Node*temp=new Node(r1->data+r2->data);
    temp->left=fun(r1->left,r2->left);
    temp->right=fun(r1->right,r2->right);

    return temp;

}
int main(){
    ifstream file("input.txt");
    ifstream file2("input2.txt");

    Node*root1=insert(file);
    Node*root2=insert(file2);
    print(root1);
    cout<<endl;

    print(root2);

    Node*temp=fun(root1,root2);
    cout<<endl;
    
    print(temp);



    

    return 0;

}