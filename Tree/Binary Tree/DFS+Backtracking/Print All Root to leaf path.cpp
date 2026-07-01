#include <iostream>
#include <vector>
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

void dfs(TreeNode *root, vector<vector<int>> &paths, vector<int> &path){

    if(root==nullptr)
        return;

    path.push_back(root->data);

    if(root->left==nullptr && root->right==nullptr){
        paths.push_back(path);
        path.pop_back();
        return;
    }

    if(root->left)
        dfs(root->left, paths, path);

    if(root->right)
        dfs(root->right, paths, path);

    path.pop_back();
}

vector<vector<int>> allRootToLeaf(TreeNode *root){

    vector<vector<int>> paths;
    vector<int> path;

    dfs(root, paths, path);

    return paths;
}

int main(){

    TreeNode *root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);

    vector<vector<int>> paths=allRootToLeaf(root);

    cout<<"Root to Leaf Paths:\n";

    for(auto &path: paths){
        for(int node: path)
            cout<<node<<" ";
        cout<<endl;
    }

    return 0;
}