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

bool validateBST(TreeNode *root, long long minAllowed, long long maxAllowed){

    if(root==nullptr)
        return true;

    // Current node must lie within the allowed range
    if(root->val<=minAllowed || root->val>=maxAllowed)
        return false;

    // Left subtree: values must be smaller than current node
    bool left=validateBST(root->left, minAllowed, root->val);

    // Right subtree: values must be greater than current node
    bool right=validateBST(root->right, root->val, maxAllowed);

    return left && right;
}

bool isValidBST(TreeNode *root){

    return validateBST(root, LLONG_MIN, LLONG_MAX);
}

int main(){

    TreeNode *root=new TreeNode(5);
    root->left=new TreeNode(3);
    root->right=new TreeNode(7);
    root->left->left=new TreeNode(2);
    root->left->right=new TreeNode(4);
    root->right->left=new TreeNode(6);
    root->right->right=new TreeNode(8);

    if(isValidBST(root))
        cout<<"Valid BST";
    else
        cout<<"Invalid BST";

    return 0;
}