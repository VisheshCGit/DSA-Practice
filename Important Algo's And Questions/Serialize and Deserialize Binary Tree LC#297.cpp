#include <iostream>
#include <queue>
#include <sstream>
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

class Codec{

public:

    // Serialize Binary Tree (Level Order)
    string serialize(TreeNode *root){

        if(root==nullptr)
            return ".";

        queue<TreeNode*> q;
        q.push(root);

        string data;

        while(!q.empty()){

            TreeNode *curr=q.front();
            q.pop();

            if(curr==nullptr){

                data+=".,";
                continue;
            }

            data+=to_string(curr->val)+",";

            q.push(curr->left);
            q.push(curr->right);
        }

        data.pop_back();

        return data;
    }

    // Deserialize Binary Tree
    TreeNode* deserialize(string data){

        if(data=="." || data.empty())
            return nullptr;

        stringstream ss(data);
        string token;

        getline(ss, token, ',');

        TreeNode *root=new TreeNode(stoi(token));

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){

            TreeNode *curr=q.front();
            q.pop();

            // Left Child
            getline(ss, token, ',');

            if(token!="."){

                TreeNode *left=new TreeNode(stoi(token));

                curr->left=left;

                q.push(left);
            }

            // Right Child
            getline(ss, token, ',');

            if(token!="."){

                TreeNode *right=new TreeNode(stoi(token));

                curr->right=right;

                q.push(right);
            }
        }

        return root;
    }
};

int main(){

    TreeNode *root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->right->left=new TreeNode(4);
    root->right->right=new TreeNode(5);

    Codec codec;

    string serialized=codec.serialize(root);

    cout<<"Serialized Tree : "<<serialized<<endl;

    TreeNode *newRoot=codec.deserialize(serialized);

    cout<<"Root after Deserialization : "<<newRoot->val<<endl;

    return 0;
}