#include <iostream>
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

TreeNode* flattenTree(TreeNode *root){

    if(root==nullptr)
        return nullptr;

    // Flatten left and right subtrees
    TreeNode *leftTail=flattenTree(root->left);
    TreeNode *rightTail=flattenTree(root->right);

    // If left subtree exists, insert it between root and right subtree
    if(leftTail){

        leftTail->right=root->right;

        root->right=root->left;

        root->left=nullptr;
    }

    // Return the tail of the flattened subtree
    if(rightTail)
        return rightTail;

    if(leftTail)
        return leftTail;

    return root;
}

void flatten(TreeNode *root){
    flattenTree(root);
}

void printList(TreeNode *root){

    while(root){
        cout<<root->val<<" ";
        root=root->right;
    }
}

int main(){

    TreeNode *root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(5);
    root->left->left=new TreeNode(3);
    root->left->right=new TreeNode(4);
    root->right->right=new TreeNode(6);

    flatten(root);

    cout<<"Flattened Tree: ";
    printList(root);

    return 0;
}