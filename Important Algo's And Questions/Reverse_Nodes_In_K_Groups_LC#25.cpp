#include<iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;

    ListNode(int data){
        val=data;
        next=nullptr;
    }
};

ListNode* findKthNode(ListNode* temp,int k){
    for(int i=1;i<k;i++){ // move k-1 steps ahead
        if(temp==nullptr)
            return nullptr; // less than k nodes available
        temp=temp->next;
    }
    return temp; // kth node found
}

ListNode* reverseLinkedList(ListNode* head){
    ListNode* curr=head; // current node
    ListNode* prev=nullptr; // previous node
    ListNode* front=nullptr; // store next node

    while(curr!=nullptr){
        front=curr->next; // save next node
        curr->next=prev; // reverse link
        prev=curr; // move prev forward
        curr=front; // move curr forward
    }

    return prev; // new head after reversal
}

ListNode* reverseKGroup(ListNode* head,int k){

    ListNode* temp=head; // current group start
    ListNode* prevGroupTail=nullptr; // tail of previous reversed group

    while(temp!=nullptr){

        ListNode* kthNode=findKthNode(temp,k); // find kth node of current group

        if(kthNode==nullptr){ // group size less than k
            if(prevGroupTail!=nullptr)
                prevGroupTail->next=temp; // attach remaining nodes
            break;
        }

        ListNode* nextGroupHead=kthNode->next; // store next group's start
        kthNode->next=nullptr; // detach current group

        ListNode* newHead=reverseLinkedList(temp); // reverse current group

        if(temp==head)
            head=newHead; // first group updates overall head
        else
            prevGroupTail->next=newHead; // connect previous group

        prevGroupTail=temp; // old head becomes new tail after reversal
        temp=nextGroupHead; // move to next group
    }

    return head;
}

void printList(ListNode* head){
    while(head!=nullptr){
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<endl;
}

int main(){

    int n;
    cout<<"Please enter number of nodes: ";
    cin>>n;

    if(n==0)
        return 0;

    int value;
    cin>>value;

    ListNode* head=new ListNode(value);
    ListNode* tail=head;

    for(int i=1;i<n;i++){
        cin>>value;
        tail->next=new ListNode(value);
        tail=tail->next;
    }

    int k;
    cout<<"Please enter k: ";
    cin>>k;

    head=reverseKGroup(head,k);

    cout<<"Linked List after reversing in groups of k: ";
    printList(head);

    return 0;
}