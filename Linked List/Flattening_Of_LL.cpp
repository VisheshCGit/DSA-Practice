#include<iostream>
using namespace std;

class ListNode{
public:
    int val;
    ListNode* next;
    ListNode* child;

    ListNode(int data){
        val=data;
        next=nullptr;
        child=nullptr;
    }
};

ListNode* mergeLists(ListNode* head1,ListNode* head2){

    ListNode* dummy=new ListNode(-1);
    ListNode* tail=dummy;

    while(head1!=nullptr && head2!=nullptr){

        if(head1->val < head2->val){
            tail->child=head1;
            head1=head1->child;
        }
        else{
            tail->child=head2;
            head2=head2->child;
        }

        tail=tail->child; // move tail forward
        tail->next=nullptr; // flattened list should use only child pointers
    }

    if(head1!=nullptr)
        tail->child=head1;
    else
        tail->child=head2;

    return dummy->child;
}

ListNode* flatten(ListNode* head){

    if(head==nullptr || head->next==nullptr)
        return head; // base case

    ListNode* flattenedHead=flatten(head->next); // flatten right side first

    return mergeLists(head,flattenedHead); // merge current list with flattened part
}

void printFlattenedList(ListNode* head){

    while(head!=nullptr){
        cout<<head->val<<" ";
        head=head->child;
    }

    cout<<endl;
}

int main(){

    ListNode* head=new ListNode(5);

    head->child=new ListNode(7);
    head->child->child=new ListNode(8);
    head->child->child->child=new ListNode(30);

    head->next=new ListNode(10);
    head->next->child=new ListNode(20);

    head->next->next=new ListNode(19);
    head->next->next->child=new ListNode(22);
    head->next->next->child->child=new ListNode(50);

    head->next->next->next=new ListNode(28);
    head->next->next->next->child=new ListNode(35);
    head->next->next->next->child->child=new ListNode(40);
    head->next->next->next->child->child->child=new ListNode(45);

    head=flatten(head);

    cout<<"Flattened Linked List: ";
    printFlattenedList(head);

    return 0;
}