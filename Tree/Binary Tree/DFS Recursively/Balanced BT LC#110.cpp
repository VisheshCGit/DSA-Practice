#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x){
        val=x;
        left=nullptr;
        right=nullptr;
    }
};

int height(TreeNode *root){

    if(root==nullptr)
        return 0;

    int leftHeight=height(root->left);

    if(leftHeight==-1)
        return -1;

    int rightHeight=height(root->right);

    if(rightHeight==-1)
        return -1;

    if(abs(leftHeight-rightHeight)>1)
        return -1;

    return 1+max(leftHeight, rightHeight);
}

bool isBalanced(TreeNode *root){
    return height(root)!=-1;
}

int main(){

    TreeNode *root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->left->left=new TreeNode(3);
    root->left->left->left=new TreeNode(4);

    if(isBalanced(root))
        cout<<"Balanced";
    else
        cout<<"Not Balanced";

    return 0;
}