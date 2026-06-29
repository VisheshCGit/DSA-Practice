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

vector<int> preorderTraversal(TreeNode *root){
    vector<int> ans;
    TreeNode *curr=root;

    while(curr!=nullptr){

        if(curr->left==nullptr){
            ans.push_back(curr->data); //visit current node if left child doesn't exist
            curr=curr->right;
        }
        else{
            TreeNode *prev=curr->left;

            while(prev->right!=nullptr && prev->right!=curr)
                prev=prev->right; //find preorder predecessor

            if(prev->right==nullptr){
                ans.push_back(curr->data); //visit current node before going left
                prev->right=curr; //create temporary thread
                curr=curr->left;
            }
            else{
                prev->right=nullptr; //remove temporary thread
                curr=curr->right;
            }
        }
    }

    return ans;
}

int main(){
    TreeNode *root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);

    vector<int> preorder=preorderTraversal(root);

    cout<<"Preorder Traversal: ";
    for(int x: preorder)
        cout<<x<<" ";

    return 0;
}