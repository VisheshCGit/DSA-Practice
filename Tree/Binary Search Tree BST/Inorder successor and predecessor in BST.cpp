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

vector<int> predecessorSuccessor(TreeNode *root, int key){

    TreeNode *pred=nullptr;
    TreeNode *succ=nullptr;

    while(root){

        if(key>root->data){

            pred=root;
            root=root->right;
        }

        else if(key<root->data){

            succ=root;
            root=root->left;
        }

        else{

            TreeNode *temp=root;

            // Find predecessor (maximum in left subtree)
            if(temp->left){

                temp=temp->left;

                while(temp->right)
                    temp=temp->right;

                pred=temp;
            }

            temp=root;

            // Find successor (minimum in right subtree)
            if(temp->right){

                temp=temp->right;

                while(temp->left)
                    temp=temp->left;

                succ=temp;
            }

            break;
        }
    }

    vector<int> ans;

    ans.push_back(pred ? pred->data : -1);
    ans.push_back(succ ? succ->data : -1);

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

    vector<int> ans=predecessorSuccessor(root,50);

    cout<<"Predecessor: "<<ans[0]<<endl;
    cout<<"Successor: "<<ans[1];

    return 0;
}