#include<iostream>
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

    Node* temp=head;
    Node* nextnode;

    while(temp!=nullptr){

        Node* copy=new Node(temp->val); // create copy node

        nextnode=temp->next;
        temp->next=copy;
        copy->next=nextnode; // insert copy after original node

        temp=nextnode;
    }

    temp=head;

    while(temp!=nullptr){
 
        Node* copy=temp->next;   // if the list was 1->2->3->null then we created 1->1'->2->2'->3->3'->null where 1 is original and 1' means copied part

        if(temp->random!=nullptr)
            copy->random=temp->random->next; // copied random node lies next to original random node

        temp=copy->next;
    }

    Node* newHead=head->next;
    temp=head;

    while(temp!=nullptr){

        Node* copy=temp->next;

        temp->next=copy->next; // restore original list

        if(copy->next!=nullptr)
            copy->next=copy->next->next; // connect copied nodes
        else
            copy->next=nullptr;

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

    second->random=first;
    third->random=fifth;
    fourth->random=third;
    fifth->random=first;

    Node* copiedHead=copyRandomList(first);

    cout<<"Copied List:"<<endl;
    printList(copiedHead);

    return 0;
}