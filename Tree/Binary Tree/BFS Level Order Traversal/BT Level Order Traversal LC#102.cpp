#include <iostream>
#include <vector>
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

vector<vector<int>> levelOrder(TreeNode *root){
    vector<vector<int>> ans;

    if(root==nullptr)
        return ans;

    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()){

        int size=q.size();
        vector<int> level;

        while(size--){

            TreeNode *curr=q.front();
            q.pop();

            level.push_back(curr->val);

            if(curr->left)
                q.push(curr->left);

            if(curr->right)
                q.push(curr->right);
        }

        ans.push_back(level);
    }

    return ans;
}

int main(){

    TreeNode *root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);
    root->right->left=new TreeNode(6);
    root->right->right=new TreeNode(7);

    vector<vector<int>> ans=levelOrder(root);

    cout<<"Level Order Traversal:\n";

    for(auto &level: ans){
        for(int x: level)
            cout<<x<<" ";
        cout<<endl;
    }

    return 0;
}