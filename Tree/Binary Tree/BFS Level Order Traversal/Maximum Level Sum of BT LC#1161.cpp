#include <iostream>
#include <queue>
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

int maxLevelSum(TreeNode *root){
    queue<TreeNode*> q;
    q.push(root);

    int level=1;
    int ans=1;
    int maxSum=INT_MIN;

    while(!q.empty()){

        int size=q.size();
        int sum=0;

        while(size--){

            TreeNode *curr=q.front();
            q.pop();

            sum+=curr->val;

            if(curr->left)
                q.push(curr->left);

            if(curr->right)
                q.push(curr->right);
        }

        if(sum>maxSum){
            maxSum=sum;
            ans=level;
        }

        level++;
    }

    return ans;
}

int main(){

    TreeNode *root=new TreeNode(1);
    root->left=new TreeNode(7);
    root->right=new TreeNode(0);
    root->left->left=new TreeNode(7);
    root->left->right=new TreeNode(-8);

    cout<<"Level with Maximum Sum: "<<maxLevelSum(root);

    return 0;
}