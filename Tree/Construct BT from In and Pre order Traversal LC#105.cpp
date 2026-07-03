#include <iostream>
#include <vector>
#include <unordered_map>
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

TreeNode* build(int preStart, int preEnd,
                vector<int> &preorder,
                int inStart, int inEnd,
                vector<int> &inorder,
                unordered_map<int,int> &mp){

    if(preStart>preEnd || inStart>inEnd)
        return nullptr;

    TreeNode *root=new TreeNode(preorder[preStart]);

    int pos=mp[preorder[preStart]];

    // Number of nodes in left subtree
    int leftSize=pos-inStart;

    // Construct left subtree
    root->left=build(preStart+1,
                     preStart+leftSize,
                     preorder,
                     inStart,
                     pos-1,
                     inorder,
                     mp);

    // Construct right subtree
    root->right=build(preStart+leftSize+1,
                      preEnd,
                      preorder,
                      pos+1,
                      inEnd,
                      inorder,
                      mp);

    return root;
}

TreeNode* buildTree(vector<int> &preorder, vector<int> &inorder){

    unordered_map<int,int> mp;

    for(int i=0;i<inorder.size();i++)
        mp[inorder[i]]=i;

    return build(0,
                 preorder.size()-1,
                 preorder,
                 0,
                 inorder.size()-1,
                 inorder,
                 mp);
}

void inorderTraversal(TreeNode *root){

    if(root==nullptr)
        return;

    inorderTraversal(root->left);
    cout<<root->val<<" ";
    inorderTraversal(root->right);
}

int main(){

    vector<int> preorder={3,9,20,15,7};
    vector<int> inorder={9,3,15,20,7};

    TreeNode *root=buildTree(preorder, inorder);

    cout<<"Constructed Tree (Inorder): ";
    inorderTraversal(root);

    return 0;
}