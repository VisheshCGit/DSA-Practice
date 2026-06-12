#include<iostream>
#include<unordered_map>
using namespace std;

class Node{
public:
    int val;
    Node* next;
    Node* random;

    Node(int data){
        val=data;
        next=nullptr;
        random=nullptr;
    }
};

Node* copyRandomList(Node* head){

    if(head==nullptr)
        return nullptr;

    unordered_map<Node*,Node*> mp;  // we have to create deep copy so this step is mandatory.. dummy node method can't be used

     Node* temp=head;  // copied List's random and next pointer should point to the new copied List's nodes... Important
    Node* newHead=nullptr; // Not optimal.. S.C. - O(n)... can be done in O(1)...

    while(temp!=nullptr){

        Node* newNode=new Node(temp->val); // create copy of current node

        if(temp==head)
            newHead=newNode; // store head of copied list

        mp[temp]=newNode; // original node -> copied node mapping

        temp=temp->next;
    }

    temp=head;

    while(temp!=nullptr){

        if(temp->next!=nullptr)
            mp[temp]->next=mp[temp->next]; // connect next pointer
        else
            mp[temp]->next=nullptr;

        if(temp->random!=nullptr)
            mp[temp]->random=mp[temp->random]; // connect random pointer
        else
            mp[temp]->random=nullptr;

        temp=temp->next;
    }

    return newHead;
}

void printList(Node* head){

    while(head!=nullptr){

        cout<<"Value: "<<head->val<<" ";

        if(head->random!=nullptr)
            cout<<"Random: "<<head->random->val;
        else
            cout<<"Random: NULL";

        cout<<endl;

        head=head->next;
    }
}

int main(){

    Node* first=new Node(7);
    Node* second=new Node(13);
    Node* third=new Node(11);
    Node* fourth=new Node(10);
    Node* fifth=new Node(1);

    first->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=fifth;

    first->random=nullptr;
    second->random=first;
    third->random=fifth;
    fourth->random=third;
    fifth->random=first;

    Node* copiedHead=copyRandomList(first);

    cout<<"Copied List:"<<endl;
    printList(copiedHead);

    return 0;
}