#include <iostream>
#include <algorithm>
#include<climits>
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

int dfs(TreeNode *root, int &maxSum){

    if(root==nullptr)
        return 0;

    // Maximum contribution coming from left subtree
    int left=dfs(root->left, maxSum);

    // Ignore negative contribution
    left=max(0, left);

    // Maximum contribution coming from right subtree
    int right=dfs(root->right, maxSum);

    // Ignore negative contribution
    right=max(0, right);

    // Best path passing through current node
    maxSum=max(maxSum, root->val+left+right);

    // Return maximum contribution to parent
    return root->val+max(left, right);
}

int maxPathSum(TreeNode *root){

    int maxSum=INT_MIN;

    dfs(root, maxSum);

    return maxSum;
}

int main(){

    TreeNode *root=new TreeNode(-10);
    root->left=new TreeNode(9);
    root->right=new TreeNode(20);
    root->right->left=new TreeNode(15);
    root->right->right=new TreeNode(7);

    cout<<"Maximum Path Sum = "<<maxPathSum(root);

    return 0;
}