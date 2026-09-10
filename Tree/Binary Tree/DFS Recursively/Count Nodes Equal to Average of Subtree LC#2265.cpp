#include <iostream>
#include <climits>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution{
public:
    int dfs(TreeNode* root,int &sum,int &count){
        if(root==nullptr)
            return 0;

        int suml=0,sumr=0;

        int left=dfs(root->left,suml,count);
        int right=dfs(root->right,sumr,count);

        sum=root->val+suml+sumr;

        int average=sum/(1+left+right);

        if(average==root->val)
            count++;

        return 1+left+right;
    }

    int averageOfSubtree(TreeNode* root){
        int count=0,sum=0;
        dfs(root,sum,count);
        return count;
    }
};

int main(){
    TreeNode* root=new TreeNode(4);
    root->left=new TreeNode(8);
    root->right=new TreeNode(5);
    root->left->left=new TreeNode(0);
    root->left->right=new TreeNode(1);
    root->right->right=new TreeNode(6);

    Solution obj;

    cout<<"Nodes whose value equals subtree average = "
        <<obj.averageOfSubtree(root);

    return 0;
}