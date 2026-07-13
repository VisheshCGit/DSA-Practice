#include<iostream>
#include<queue>
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

TreeNode* buildTree(){

    int val;

    cin>>val;

    if(val==-1)
        return nullptr;

    TreeNode *root=new TreeNode(val);

    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()){

        TreeNode *curr=q.front();
        q.pop();

        int leftVal,rightVal;

        cin>>leftVal;

        if(leftVal!=-1){
            curr->left=new TreeNode(leftVal);
            q.push(curr->left);
        }

        cin>>rightVal;

        if(rightVal!=-1){
            curr->right=new TreeNode(rightVal);
            q.push(curr->right);
        }
    }

    return root;
}

bool dfs(TreeNode *root,int sum){

    if(root==nullptr)
        return false;

    sum-=root->val; //consume current node

    if(sum==0 && !root->left && !root->right)
        return true; //valid root to leaf path

    return dfs(root->left,sum) || dfs(root->right,sum);
}

bool hasPathSum(TreeNode *root,int targetSum){
    return dfs(root,targetSum);
}

int main(){

    cout<<"Enter tree in level order (-1 for NULL):\n";

    TreeNode *root=buildTree();

    int target;

    cout<<"Enter Target Sum : ";
    cin>>target;

    if(hasPathSum(root,target))
        cout<<"True";
    else
        cout<<"False";

    return 0;
}