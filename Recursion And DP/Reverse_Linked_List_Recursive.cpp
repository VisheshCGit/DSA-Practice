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

ListNode* solve(ListNode* head) {

    // Base case:
    // Empty list or single node list is already reversed
    if(head == nullptr || head->next == nullptr)
        return head;

    // Recursively reverse the remaining list
    ListNode* newHead = solve(head->next);

    // head -> 1 -> 2 -> 3 -> NULL
    // Suppose recursion has already reversed:
    // 2 -> 3 -> NULL
    // into:
    // 3 -> 2 -> NULL

    ListNode* front = head->next;

    // Make next node point back to current node
    front->next = head;

    // Break the old forward connection
    head->next = nullptr;

    // Return the head of the reversed list
    return newHead;
}

ListNode* reverseList(ListNode* head) {
    return solve(head);
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