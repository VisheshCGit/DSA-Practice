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

TreeNode* lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q){

    if(root==nullptr)
        return nullptr;

    // Both nodes lie in the left subtree
    if(root->val>p->val && root->val>q->val)
        return lowestCommonAncestor(root->left, p, q);

    // Both nodes lie in the right subtree
    if(root->val<p->val && root->val<q->val)
        return lowestCommonAncestor(root->right, p, q);

    // Current node splits the paths (or matches one target)
    return root;
}

int main(){

    TreeNode *root=new TreeNode(6);
    root->left=new TreeNode(2);
    root->right=new TreeNode(8);
    root->left->left=new TreeNode(0);
    root->left->right=new TreeNode(4);
    root->right->left=new TreeNode(7);
    root->right->right=new TreeNode(9);

    TreeNode *p=root->left;
    TreeNode *q=root->right;

    TreeNode *lca=lowestCommonAncestor(root, p, q);

    cout<<"LCA: "<<lca->val;

    return 0;
}