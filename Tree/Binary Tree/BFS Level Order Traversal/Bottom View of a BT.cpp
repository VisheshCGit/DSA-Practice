#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

struct TreeNode{
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val){
        data=val;
        left=nullptr;
        right=nullptr;
    }
};

vector<int> bottomView(TreeNode *root){

    vector<int> ans;

    if(root==nullptr)
        return ans;

    queue<pair<TreeNode*, int>> q;
    map<int, int> mp;

    q.push({root, 0});

    while(!q.empty()){

        auto curr=q.front();
        q.pop();

        TreeNode *node=curr.first;
        int hd=curr.second;

        mp[hd]=node->data;

        if(node->left)
            q.push({node->left, hd-1});

        if(node->right)
            q.push({node->right, hd+1});
    }

    for(auto &x: mp)
        ans.push_back(x.second);

    return ans;
}

int main(){

    TreeNode *root=new TreeNode(20);
    root->left=new TreeNode(8);
    root->right=new TreeNode(22);
    root->left->left=new TreeNode(5);
    root->left->right=new TreeNode(3);
    root->right->left=new TreeNode(4);
    root->right->right=new TreeNode(25);
    root->left->right->left=new TreeNode(10);
    root->left->right->right=new TreeNode(14);

    vector<int> ans=bottomView(root);

    cout<<"Bottom View: ";

    for(int x: ans)
        cout<<x<<" ";

    return 0;
}