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

int height(TreeNode *root, int &diameter){

    if(root==nullptr)
        return 0;

    int leftHeight=height(root->left, diameter);
    int rightHeight=height(root->right, diameter);

    diameter=max(diameter, leftHeight+rightHeight);

    return 1+max(leftHeight, rightHeight);
}

int diameterOfBinaryTree(TreeNode *root){

    int diameter=0;

    height(root, diameter);

    return diameter;
}

int main(){

    TreeNode *root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);

    cout<<"Diameter: "<<diameterOfBinaryTree(root);

    return 0;
}