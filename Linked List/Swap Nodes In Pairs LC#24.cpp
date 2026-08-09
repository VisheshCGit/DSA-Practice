#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x,ListNode* next) : val(x), next(next) {}
};

class Solution{
public:
    ListNode* swapPairs(ListNode* head){
        ListNode* temp=head;
        if(!temp || !temp->next) return temp;

        ListNode* front;
        ListNode dummy;
        dummy.next=head;
        ListNode* prev=&dummy;

        while(temp && temp->next){
            front=temp->next;
            prev->next=front;
            temp->next=front->next;
            front->next=temp;
            prev=temp;
            temp=temp->next;
        }

        return dummy.next;
    }
};

ListNode* createList(int n){
    ListNode* head=nullptr;
    ListNode* tail=nullptr;

    for(int i=0;i<n;i++){
        int x;
        cin>>x;

        ListNode* newNode=new ListNode(x);

        if(!head){
            head=newNode;
            tail=newNode;
        }
        else{
            tail->next=newNode;
            tail=newNode;
        }
    }

    return head;
}

void printList(ListNode* head){
    while(head){
        cout<<head->val;
        if(head->next)
            cout<<" -> ";
        head=head->next;
    }
    cout<<endl;
}

int main(){
    int n;

    cout<<"Enter number of nodes: ";
    cin>>n;

    cout<<"Enter elements: ";
    ListNode* head=createList(n);

    Solution obj;
    head=obj.swapPairs(head);

    cout<<"After swapping pairs: ";
    printList(head);

    return 0;
}