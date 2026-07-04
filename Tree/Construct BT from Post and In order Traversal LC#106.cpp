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

TreeNode* build(int inStart, int inEnd,
                vector<int> &inorder,
                int postStart, int postEnd,
                vector<int> &postorder,
                unordered_map<int,int> &mp){

    if(inStart>inEnd || postStart>postEnd)
        return nullptr;

    // Last element of postorder is the root
    TreeNode *root=new TreeNode(postorder[postEnd]);

    int index=mp[postorder[postEnd]];

    // Number of nodes in left subtree
    int leftSize=index-inStart;

    // Construct left subtree
    root->left=build(inStart,
                     index-1,
                     inorder,
                     postStart,
                     postStart+leftSize-1,
                     postorder,
                     mp);

    // Construct right subtree
    root->right=build(index+1,
                      inEnd,
                      inorder,
                      postStart+leftSize,
                      postEnd-1,
                      postorder,
                      mp);

    return root;
}

TreeNode* buildTree(vector<int> &inorder, vector<int> &postorder){

    unordered_map<int,int> mp;

    for(int i=0;i<inorder.size();i++)
        mp[inorder[i]]=i;

    return build(0,
                 inorder.size()-1,
                 inorder,
                 0,
                 postorder.size()-1,
                 postorder,
                 mp);
}

void preorderTraversal(TreeNode *root){

    if(root==nullptr)
        return;

    cout<<root->val<<" ";

    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

int main(){

    vector<int> inorder={9,3,15,20,7};
    vector<int> postorder={9,15,7,20,3};

    TreeNode *root=buildTree(inorder, postorder);

    cout<<"Constructed Tree (Preorder): ";
    preorderTraversal(root);

    return 0;
}