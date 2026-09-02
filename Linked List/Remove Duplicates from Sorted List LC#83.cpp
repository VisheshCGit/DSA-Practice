#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x,ListNode *next) : val(x), next(next) {}
};

class Solution{
public:
    ListNode* deleteDuplicates(ListNode* head){
        ListNode* temp=head;

        while(temp && temp->next){
            if(temp->val==temp->next->val)
                temp->next=temp->next->next;
            else
                temp=temp->next;
        }

        return head;
    }
};

int main(){
    int n;

    cout<<"Enter number of nodes: ";
    cin>>n;

    ListNode* head=nullptr;
    ListNode* tail=nullptr;

    cout<<"Enter elements: ";
    for(int i=0;i<n;i++){
        int x;
        cin>>x;

        ListNode* node=new ListNode(x);

        if(!head)
            head=tail=node;
        else{
            tail->next=node;
            tail=node;
        }
    }

    Solution obj;
    head=obj.deleteDuplicates(head);

    cout<<"After removing duplicates: ";
    while(head){
        cout<<head->val<<" ";
        head=head->next;
    }

    return 0;
}