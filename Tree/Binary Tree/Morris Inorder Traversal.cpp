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

vector<int> inorderTraversal(TreeNode *root){
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
                prev=prev->right; //find inorder predecessor

            if(prev->right==nullptr){
                prev->right=curr; //create temporary thread
                curr=curr->left;
            }
            else{
                prev->right=nullptr; //remove temporary thread
                ans.push_back(curr->data); //visit current node
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

    vector<int> inorder=inorderTraversal(root);

    cout<<"Inorder Traversal: ";
    for(int x: inorder)
        cout<<x<<" ";

    return 0;
}