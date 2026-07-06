#include <iostream>
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

bool solve(TreeNode *root, int target, unordered_map<int, TreeNode*> &mp){

    if(root==nullptr)
        return false;

    // Check if complement already exists
    auto it=mp.find(target-root->val);

    if(it!=mp.end() && it->second!=root)
        return true;

    // Store current node
    mp[root->val]=root;

    return solve(root->left, target, mp) ||
           solve(root->right, target, mp);
}

bool findTarget(TreeNode *root, int k){

    unordered_map<int, TreeNode*> mp;

    return solve(root, k, mp);
}

int main(){

    TreeNode *root=new TreeNode(5);
    root->left=new TreeNode(3);
    root->right=new TreeNode(6);
    root->left->left=new TreeNode(2);
    root->left->right=new TreeNode(4);
    root->right->right=new TreeNode(7);

    if(findTarget(root, 9))
        cout<<"Pair Exists";
    else
        cout<<"Pair Does Not Exist";

    return 0;
}