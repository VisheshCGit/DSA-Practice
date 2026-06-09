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

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* slow = head;
    ListNode* fast = head;

    for(int i = 1; i <= n; i++)
        fast = fast->next;

    if(fast == nullptr) {
        head = head->next;
    }
    else {
        while(fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        slow->next = slow->next->next;
    }

    return head;
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

    int removeFromEnd;
    cout << "Please enter N: ";
    cin >> removeFromEnd;

    head = removeNthFromEnd(head, removeFromEnd);

    cout << "Linked List after deletion: ";
    printList(head);

    return 0;
}