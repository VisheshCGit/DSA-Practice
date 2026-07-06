#include <iostream>
#include <stack>
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

class BSTIterator{

    stack<TreeNode*> st;

    void pushAllLeft(TreeNode *node){
        while(node){
            st.push(node);
            node=node->left;
        }
    }

public:

    BSTIterator(TreeNode *root){
        pushAllLeft(root); //Initially push all left elements.. Maintaining Recursion Call Stack Manually
    }

    int next(){
        TreeNode *curr=st.top();
        st.pop();
        pushAllLeft(curr->right); // Process the leftmost path of the right subtree
        return curr->val;     // After The above line... the stack will contain the leftmost element of right subtree
    }

    bool hasNext(){
        return !st.empty();
    }
};

int main(){

    TreeNode *root=new TreeNode(7);
    root->left=new TreeNode(3);
    root->right=new TreeNode(15);
    root->right->left=new TreeNode(9);
    root->right->right=new TreeNode(20);

    BSTIterator it(root);

    while(it.hasNext())
        cout<<it.next()<<" ";

    return 0;
}