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

TreeNode* solve(TreeNode *root, TreeNode *p, TreeNode *q){

    if(root==nullptr)
        return nullptr;

    if(root==p || root==q)
        return root;

    TreeNode *left=solve(root->left, p, q);
    TreeNode *right=solve(root->right, p, q);

    if(left && right)
        return root;

    if(left)
        return left;

    return right;
}

TreeNode* lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q){
    return solve(root, p, q);
}

int main(){

    TreeNode *root=new TreeNode(3);
    root->left=new TreeNode(5);
    root->right=new TreeNode(1);
    root->left->left=new TreeNode(6);
    root->left->right=new TreeNode(2);
    root->right->left=new TreeNode(0);
    root->right->right=new TreeNode(8);
    root->left->right->left=new TreeNode(7);
    root->left->right->right=new TreeNode(4);

    TreeNode *p=root->left;
    TreeNode *q=root->left->right->right;

    TreeNode *lca=lowestCommonAncestor(root, p, q);

    cout<<"Lowest Common Ancestor: "<<lca->val;

    return 0;
}