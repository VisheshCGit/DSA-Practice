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

bool isEvenOddTree(TreeNode *root){
    if(root==nullptr)
        return true;

    queue<TreeNode*> q;
    q.push(root);

    int level=0;

    while(!q.empty()){

        int size=q.size();
        int prev=(level%2==0)?INT_MIN:INT_MAX;

        while(size--){

            TreeNode *curr=q.front();
            q.pop();

            int value=curr->val;

            // Check parity
            if((level%2)^(value%2)==0)
                return false;

            // Check ordering
            if(level%2==0){
                if(value<=prev)
                    return false;
            }
            else{
                if(value>=prev)
                    return false;
            }

            prev=value;

            if(curr->left)
                q.push(curr->left);

            if(curr->right)
                q.push(curr->right);
        }

        level++;
    }

    return true;
}

int main(){
    TreeNode *root=new TreeNode(1);
    root->left=new TreeNode(10);
    root->right=new TreeNode(4);
    root->left->left=new TreeNode(3);
    root->right->left=new TreeNode(7);
    root->right->right=new TreeNode(9);

    if(isEvenOddTree(root))
        cout<<"True";
    else
        cout<<"False";

    return 0;
}