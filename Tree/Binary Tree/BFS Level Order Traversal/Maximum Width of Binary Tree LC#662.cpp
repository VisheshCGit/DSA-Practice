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

int widthOfBinaryTree(TreeNode *root){
    if(root==nullptr)
        return 0;

    queue<pair<TreeNode*, unsigned long long>> q;
    q.push({root, 0});

    int ans=0;

    while(!q.empty()){

        int size=q.size();

        unsigned long long first=q.front().second;
        unsigned long long leftMost=0, rightMost=0;

        for(int i=0; i<size; i++){

            auto curr=q.front();
            q.pop();

            unsigned long long index=curr.second-first;

            if(i==0)
                leftMost=index;

            if(i==size-1)
                rightMost=index;

            if(curr.first->left)
                q.push({curr.first->left, 2*index+1});

            if(curr.first->right)
                q.push({curr.first->right, 2*index+2});
        }

        ans=max(ans, (int)(rightMost-leftMost+1));
    }

    return ans;
}

int main(){

    TreeNode *root=new TreeNode(1);
    root->left=new TreeNode(3);
    root->right=new TreeNode(2);
    root->left->left=new TreeNode(5);
    root->left->right=new TreeNode(3);
    root->right->right=new TreeNode(9);

    cout<<"Maximum Width: "<<widthOfBinaryTree(root);

    return 0;
}