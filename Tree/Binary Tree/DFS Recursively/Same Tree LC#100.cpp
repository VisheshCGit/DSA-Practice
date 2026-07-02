#include <iostream>
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

bool isSame(TreeNode *p, TreeNode *q){

    if(p==nullptr && q==nullptr)
        return true;

    if(p==nullptr || q==nullptr)
        return false;

    if(p->val!=q->val)
        return false;

    bool left=isSame(p->left, q->left);
    bool right=isSame(p->right, q->right);

    return left && right;
}

bool isSameTree(TreeNode *p, TreeNode *q){
    return isSame(p, q);
}

int main(){

    TreeNode *root1=new TreeNode(1);
    root1->left=new TreeNode(2);
    root1->right=new TreeNode(3);

    TreeNode *root2=new TreeNode(1);
    root2->left=new TreeNode(2);
    root2->right=new TreeNode(3);

    if(isSameTree(root1, root2))
        cout<<"Same Tree";
    else
        cout<<"Different Tree";

    return 0;
}