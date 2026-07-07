#include <iostream>
#include <climits>
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

struct NodeInfo{
    bool isBST;
    int mini;
    int maxi;
    int sum;
};

NodeInfo solve(TreeNode *root, int &maxSum){

    // Empty subtree is a valid BST
    if(root==nullptr)
        return {true, INT_MAX, INT_MIN, 0};

    NodeInfo left=solve(root->left, maxSum);
    NodeInfo right=solve(root->right, maxSum);

    // Current subtree forms a valid BST
    if(left.isBST &&
       right.isBST &&
       left.maxi<root->val &&
       root->val<right.mini){

        int currSum=left.sum+right.sum+root->val;

        maxSum=max(maxSum, currSum);

        return {
            true,
            min(left.mini, root->val),
            max(right.maxi, root->val),
            currSum
        };
    }

    // Current subtree is not a BST
    return {false, 0, 0, 0};
}

int maxSumBST(TreeNode *root){

    int maxSum=0;

    solve(root, maxSum);

    return maxSum;
}

int main(){

    TreeNode *root=new TreeNode(1);
    root->left=new TreeNode(4);
    root->right=new TreeNode(3);

    root->left->left=new TreeNode(2);
    root->left->right=new TreeNode(4);

    root->right->left=new TreeNode(2);
    root->right->right=new TreeNode(5);

    root->right->right->left=new TreeNode(4);
    root->right->right->right=new TreeNode(6);

    cout<<"Maximum Sum BST = "<<maxSumBST(root);

    return 0;
}