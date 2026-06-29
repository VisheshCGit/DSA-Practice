#include <iostream>
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

bool isCousins(TreeNode *root, int x, int y){
    if(root==nullptr)
        return false;

    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()){

        int size=q.size();

        bool foundX=false;
        bool foundY=false;

        while(size--){

            TreeNode *curr=q.front();
            q.pop();

            // Check if x and y are siblings
            if(curr->left && curr->right){

                if((curr->left->val==x && curr->right->val==y) ||
                   (curr->left->val==y && curr->right->val==x))
                    return false;
            }

            if(curr->left){

                if(curr->left->val==x)
                    foundX=true;

                if(curr->left->val==y)
                    foundY=true;

                q.push(curr->left);
            }

            if(curr->right){

                if(curr->right->val==x)
                    foundX=true;

                if(curr->right->val==y)
                    foundY=true;

                q.push(curr->right);
            }
        }

        if(foundX && foundY)
            return true;

        if(foundX || foundY)
            return false;
    }

    return false;
}

int main(){

    TreeNode *root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->right->right=new TreeNode(5);

    if(isCousins(root,4,5))
        cout<<"True";
    else
        cout<<"False";

    return 0;
}