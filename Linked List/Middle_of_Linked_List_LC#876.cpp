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

ListNode* middleNode(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while(fast != nullptr && fast->next != nullptr) { // Tortoise and Hare Method... Fast and slow pointer...
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
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

    cout << "Linked List: ";
    printList(head);

    ListNode* middle = middleNode(head);

    cout << "Middle Node Value: " << middle->val << endl;

    return 0;
}