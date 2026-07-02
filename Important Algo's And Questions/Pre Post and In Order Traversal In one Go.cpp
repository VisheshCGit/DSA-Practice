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

vector<vector<int>> treeTraversal(TreeNode *root){

    vector<int> inorder;
    vector<int> preorder;
    vector<int> postorder;

    if(root==nullptr)
        return {inorder, preorder, postorder};

    stack<pair<TreeNode*, int>> st;
    st.push({root, 1});

    while(!st.empty()){

        auto curr=st.top();
        st.pop();

        if(curr.second==1){

            preorder.push_back(curr.first->data);

            st.push({curr.first, 2});

            if(curr.first->left)
                st.push({curr.first->left, 1});
        }
        else if(curr.second==2){

            inorder.push_back(curr.first->data);

            st.push({curr.first, 3});

            if(curr.first->right)
                st.push({curr.first->right, 1});
        }
        else{

            postorder.push_back(curr.first->data);
        }
    }

    return {inorder, preorder, postorder};
}

int main(){

    TreeNode *root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);

    vector<vector<int>> ans=treeTraversal(root);

    cout<<"Inorder: ";
    for(int x: ans[0])
        cout<<x<<" ";

    cout<<"\nPreorder: ";
    for(int x: ans[1])
        cout<<x<<" ";

    cout<<"\nPostorder: ";
    for(int x: ans[2])
        cout<<x<<" ";

    return 0;
}