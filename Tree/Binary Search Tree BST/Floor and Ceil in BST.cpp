#include <iostream>
#include <vector>
using namespace std;

struct TreeNode{
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x){
        data=x;
        left=nullptr;
        right=nullptr;
    }
};

vector<int> floorCeilOfBST(TreeNode *root, int key){

    TreeNode *floor=nullptr;
    TreeNode *ceil=nullptr;

    while(root){

        if(root->data>key){

            ceil=root;
            root=root->left;
        }

        else if(root->data<key){

            floor=root;
            root=root->right;
        }

        else{

            floor=root;
            ceil=root;
            break; //Important otherwise the loop will continue and can alter the values found...
        }
    }

    vector<int> ans;

    ans.push_back(floor ? floor->data : -1);
    ans.push_back(ceil ? ceil->data : -1);

    return ans;
}

int main(){

    TreeNode *root=new TreeNode(50);
    root->left=new TreeNode(30);
    root->right=new TreeNode(70);
    root->left->left=new TreeNode(20);
    root->left->right=new TreeNode(40);
    root->right->left=new TreeNode(60);
    root->right->right=new TreeNode(80);

    int key=65;

    vector<int> ans=floorCeilOfBST(root, key);

    cout<<"Floor = "<<ans[0]<<endl;
    cout<<"Ceil = "<<ans[1];

    return 0;
}