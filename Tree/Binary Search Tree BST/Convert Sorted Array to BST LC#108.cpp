#include <iostream>
#include <vector>
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

TreeNode* buildBST(int left, int right, vector<int> &nums){

    if(left>right)
        return nullptr;

    // Middle element becomes the root
    int mid=left+(right-left)/2;

    TreeNode *root=new TreeNode(nums[mid]);

    // Construct left subtree
    root->left=buildBST(left, mid-1, nums);

    // Construct right subtree
    root->right=buildBST(mid+1, right, nums);

    return root;
}

TreeNode* sortedArrayToBST(vector<int> &nums){

    return buildBST(0, nums.size()-1, nums);
}

void inorder(TreeNode *root){

    if(root==nullptr)
        return;

    inorder(root->left);

    cout<<root->val<<" ";

    inorder(root->right);
}

int main(){

    vector<int> nums={-10,-3,0,5,9};

    TreeNode *root=sortedArrayToBST(nums);

    cout<<"Inorder Traversal: ";

    inorder(root);

    return 0;
}