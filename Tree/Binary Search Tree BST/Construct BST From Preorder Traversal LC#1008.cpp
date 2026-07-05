#include <iostream>
#include <vector>
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

TreeNode* buildBST(vector<int> &preorder, int &idx, int bound){

    // Stop if all nodes are processed or current value exceeds the allowed bound
    if(idx>=preorder.size() || preorder[idx]>bound)
        return nullptr;

    TreeNode *root=new TreeNode(preorder[idx]);
    idx++;

    // Construct left subtree
    root->left=buildBST(preorder, idx, root->val);

    // Construct right subtree
    root->right=buildBST(preorder, idx, bound);

    return root;
}

TreeNode* bstFromPreorder(vector<int> &preorder){

    int idx=0;

    return buildBST(preorder, idx, INT_MAX);
}

void inorder(TreeNode *root){

    if(root==nullptr)
        return;

    inorder(root->left);

    cout<<root->val<<" ";

    inorder(root->right);
}

int main(){

    vector<int> preorder={8,5,1,7,10,12};

    TreeNode *root=bstFromPreorder(preorder);

    cout<<"Inorder Traversal: ";

    inorder(root);

    return 0;
}