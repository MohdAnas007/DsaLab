#include<iostream>
#include<vector>
using namespace std;

struct TreeNode{

    TreeNode*left;
    TreeNode*right;
    int val;

    TreeNode(int data){
        this->val=data;

    }
};

TreeNode*tree(){
    int x;
    cin>>x;
    if(x==-1)return NULL;
    TreeNode*temp=new TreeNode(x);

    temp->left=tree();
    temp->right=tree();


    return temp;

}

TreeNode*insert(TreeNode*root,int x){

    if(!root){
        return new TreeNode(x);

    }

    if(x<root->val){
        root->left=insert(root->left,x);

    }
    if(x>root->val){
        root->right=insert(root->right,x);

    }

    return root;
}

void print(TreeNode*root){
    if(!root)return;


    print(root->left);
    cout<<root->val<<" ";

    print(root->right);

}

bool search(TreeNode*root,int x){
    if(!root)return 0;
    if(root->val==x)return 1;

    if(x<root->val){
        return search(root->left,x);

    }
    else return search(root->right,x);

    return 0;


}
int main(){
    vector<int>arr={1,2,3,4,-1};
    TreeNode*root=NULL;

    for(int i=0;i<arr.size();i++){
        root=insert(root,arr[i]);

    }
    cout<<search(root,-1);

    return 0;

}