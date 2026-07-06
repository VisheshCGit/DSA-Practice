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

TreeNode* findKthSmallest(TreeNode *root, int &k){

    if(root==nullptr)
        return nullptr;

    // Search in left subtree
    TreeNode *left=findKthSmallest(root->left, k);

    if(left)
        return left;

    // Current node
    k--;

    if(k==0)
        return root;

    // Search in right subtree
    return findKthSmallest(root->right, k);
}

int kthSmallest(TreeNode *root, int k){

    return findKthSmallest(root, k)->val;
}

int main(){

    TreeNode *root=new TreeNode(5);
    root->left=new TreeNode(3);
    root->right=new TreeNode(6);
    root->left->left=new TreeNode(2);
    root->left->right=new TreeNode(4);
    root->left->left->left=new TreeNode(1);

    int k=3;

    cout<<"Kth Smallest = "<<kthSmallest(root, k);

    return 0;
}