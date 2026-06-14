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

ListNode* reverseList(ListNode* head){

    ListNode* current=head;
    ListNode* previous=nullptr;
    ListNode* nextNode=nullptr;

    while(current!=nullptr){

        nextNode=current->next;
        current->next=previous;
        previous=current;
        current=nextNode;
    }

    return previous;
}

int pairSum(ListNode* head){

    ListNode* slow=head;
    ListNode* fast=head;
    ListNode* previousNode=nullptr;

    while(fast!=nullptr && fast->next!=nullptr){

        previousNode=slow; // keep track of node before middle
        slow=slow->next;
        fast=fast->next->next;
    }

    previousNode->next=nullptr; // split linked list into two halves

    ListNode* secondHalfHead=reverseList(slow); // reverse second half

    int maximumTwinSum=0;

    ListNode* firstHalf=head;
    ListNode* secondHalf=secondHalfHead;

    while(secondHalf!=nullptr){

        int currentSum=firstHalf->val+secondHalf->val;

        maximumTwinSum=max(maximumTwinSum,currentSum);

        firstHalf=firstHalf->next;
        secondHalf=secondHalf->next;
    }

    return maximumTwinSum;
}

int main(){

    int n;

    cout<<"Please enter even number of nodes: ";
    cin>>n;

    if(n<=0 || n%2!=0)
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

    cout<<"Maximum Twin Sum: "<<pairSum(head);

    return 0;
}