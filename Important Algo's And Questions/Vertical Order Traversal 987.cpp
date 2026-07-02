#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
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

vector<vector<int>> verticalTraversal(TreeNode *root){

    vector<vector<int>> ans;

    if(root==nullptr)
        return ans;

    queue<pair<TreeNode*, int>> q;
    map<int, map<int, multiset<int>>> mp;

    q.push({root, 0});

    int row=0;

    while(!q.empty()){

        int size=q.size();

        while(size--){

            auto curr=q.front();
            q.pop();

            TreeNode *node=curr.first;
            int col=curr.second;

            mp[col][row].insert(node->val);

            if(node->left)
                q.push({node->left, col-1});

            if(node->right)
                q.push({node->right, col+1});
        }

        row++;
    }

    for(auto &col : mp){

        vector<int> temp;

        for(auto &r : col.second){

            for(int val : r.second)
                temp.push_back(val);
        }

        ans.push_back(temp);
    }

    return ans;
}

int main(){

    TreeNode *root=new TreeNode(3);
    root->left=new TreeNode(9);
    root->right=new TreeNode(20);
    root->right->left=new TreeNode(15);
    root->right->right=new TreeNode(7);

    vector<vector<int>> ans=verticalTraversal(root);

    for(auto &col : ans){
        for(int x : col)
            cout<<x<<" ";
        cout<<endl;
    }

    return 0;
}