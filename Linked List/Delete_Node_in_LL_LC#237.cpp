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

void deleteNode(ListNode* node) {
    node->val = node->next->val;
    node->next = node->next->next;
}

void printList(ListNode* head) {
    ListNode* temp = head;

    while(temp != nullptr) {  // since we don't have access to the head.. we delete next node after (node) after copying its value in the current given node and doing pointer movement
        cout << temp->val << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main() {
    ListNode* head = new ListNode(4);
    head->next = new ListNode(5);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(9);

    cout << "Original Linked List: ";
    printList(head);

    deleteNode(head->next);

    cout << "Linked List after deletion: ";
    printList(head);

    return 0;
}