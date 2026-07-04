#include <iostream>
#include <vector>
#include <stack>
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

bool isLeaf(TreeNode *root){
    return root->left==nullptr && root->right==nullptr;
}

void addLeftBoundary(TreeNode *root, vector<int> &ans){

    TreeNode *curr=root->left;

    while(curr){

        if(!isLeaf(curr))
            ans.push_back(curr->data);

        if(curr->left)
            curr=curr->left;
        else
            curr=curr->right;
    }
}

void addLeaves(TreeNode *root, vector<int> &ans){

    if(root==nullptr)
        return;

    if(isLeaf(root)){
        ans.push_back(root->data);
        return;
    }

    addLeaves(root->left, ans);
    addLeaves(root->right, ans);
}

void addRightBoundary(TreeNode *root, vector<int> &ans){

    TreeNode *curr=root->right;
    stack<int> st;

    while(curr){

        if(!isLeaf(curr))
            st.push(curr->data);

        if(curr->right)
            curr=curr->right;
        else
            curr=curr->left;
    }

    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
}

vector<int> boundaryTraversal(TreeNode *root){

    vector<int> ans;

    if(root==nullptr)
        return ans;

    if(!isLeaf(root))
        ans.push_back(root->data);

    addLeftBoundary(root, ans);

    addLeaves(root, ans);

    addRightBoundary(root, ans);

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

    vector<int> ans=boundaryTraversal(root);

    cout<<"Boundary Traversal: ";

    for(int x: ans)
        cout<<x<<" ";

    return 0;
}