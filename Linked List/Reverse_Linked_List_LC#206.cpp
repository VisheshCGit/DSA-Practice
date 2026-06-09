#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

ListNode* reverseList(ListNode* head) {
    ListNode* temp = head;
    ListNode* prev = nullptr;
    ListNode* front = nullptr;

    while(temp != nullptr) {    // we have to reverse the direction of chain
        front = temp->next;  // from 1->2->3->4->5->X  to  5->4->3->2->1->X   X is null... we want our inital head to point to X so initially prev=null(X)
        temp->next = prev;
        prev = temp;
        temp = front;
    }

    return prev;
}

void printList(ListNode* head) {
    ListNode* temp = head;

    while(temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main() {
    int n;

    cout << "Please enter number of nodes: ";
    cin >> n;

    if(n == 0)
        return 0;

    int value;
    cout << "Please enter node values: ";

    cin >> value;
    ListNode* head = new ListNode(value);
    ListNode* tail = head;

    for(int i = 1; i < n; i++) {
        cin >> value;

        tail->next = new ListNode(value);
        tail = tail->next;
    }

    cout << "Original Linked List: ";
    printList(head);

    head = reverseList(head);

    cout << "Reversed Linked List: ";
    printList(head);

    return 0;
}