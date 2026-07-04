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

TreeNode* searchBST(TreeNode *root, int val){

    if(root==nullptr || root->val==val)
        return root;

    if(val<root->val)
        return searchBST(root->left, val);

    return searchBST(root->right, val);
}

int main(){

    TreeNode *root=new TreeNode(4);
    root->left=new TreeNode(2);
    root->right=new TreeNode(7);
    root->left->left=new TreeNode(1);
    root->left->right=new TreeNode(3);

    int target=2;

    TreeNode *ans=searchBST(root, target);

    if(ans)
        cout<<"Found: "<<ans->val;
    else
        cout<<"Not Found";

    return 0;
}