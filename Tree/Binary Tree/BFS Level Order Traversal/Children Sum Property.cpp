#include <iostream>
#include <queue>
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

bool checkChildrenSum(TreeNode *root){

    if(root==nullptr)
        return true;

    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()){

        TreeNode *curr=q.front();
        q.pop();

        int childSum=0;

        if(curr->left){
            childSum+=curr->left->val;
            q.push(curr->left);
        }

        if(curr->right){
            childSum+=curr->right->val;
            q.push(curr->right);
        }

        // Check only for non-leaf nodes
        if((curr->left || curr->right) && childSum!=curr->val)
            return false;
    }

    return true;
}

int main(){

    TreeNode *root=new TreeNode(10);
    root->left=new TreeNode(8);
    root->right=new TreeNode(2);
    root->left->left=new TreeNode(3);
    root->left->right=new TreeNode(5);
    root->right->right=new TreeNode(2);

    if(checkChildrenSum(root))
        cout<<"Children Sum Property Satisfied";
    else
        cout<<"Children Sum Property Not Satisfied";

    return 0;
}