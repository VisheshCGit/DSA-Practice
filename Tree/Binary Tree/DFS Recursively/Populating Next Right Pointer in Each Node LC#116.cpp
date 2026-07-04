#include <iostream>
using namespace std;

class Node{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node(int x){
        val=x;
        left=nullptr;
        right=nullptr;
        next=nullptr;
    }
};

void connectNodes(Node *root){

    if(root==nullptr)
        return;

    // Connect left child with right child
    if(root->left)
        root->left->next=root->right;

    // Connect right child with next subtree's left child
    if(root->next && root->right)
        root->right->next=root->next->left;

    connectNodes(root->left);
    connectNodes(root->right);
}

Node* connect(Node *root){

    connectNodes(root);

    return root;
}

void printLevels(Node *root){

    while(root){

        Node *curr=root;

        while(curr){
            cout<<curr->val<<" ";
            curr=curr->next;
        }

        cout<<"# ";

        root=root->left;
    }
}

int main(){

    Node *root=new Node(1);

    root->left=new Node(2);
    root->right=new Node(3);

    root->left->left=new Node(4);
    root->left->right=new Node(5);

    root->right->left=new Node(6);
    root->right->right=new Node(7);

    connect(root);

    printLevels(root);

    return 0;
}