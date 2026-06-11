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

ListNode* rotateRight(ListNode* head,int k){

    if(head==nullptr || head->next==nullptr)
        return head;

    int length=0;
    ListNode* current=head;

    while(current!=nullptr){
        length++;
        current=current->next;
    }

    k%=length;

    if(k==0)
        return head;

    ListNode* slow=head;
    ListNode* fast=head;

    while(k--){
        fast=fast->next;
    }

    while(fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next;
    }

    ListNode* newHead=slow->next;
    slow->next=nullptr;
    fast->next=head;

    return newHead;
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

    head=rotateRight(head,k);

    cout<<"Linked list after rotation: ";
    printList(head);

    return 0;
}