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

bool isPalindrome(ListNode* head) {
    if(head == nullptr || head->next == nullptr)
        return true;

    ListNode* slow = head;
    ListNode* fast = head;

    while(fast != nullptr && fast->next != nullptr) {  // first find the middle of list and reverse the other half and compare both the halfs
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode* prev = nullptr;
    ListNode* curr;

    if(fast == nullptr)
        curr = slow;
    else
        curr = slow->next;

    while(curr != nullptr) {
        ListNode* front = curr->next;
        curr->next = prev;
        prev = curr;
        curr = front;
    }

    ListNode* first = head;
    ListNode* second = prev;

    while(second != nullptr) {
        if(first->val != second->val)
            return false;

        first = first->next;
        second = second->next;
    }

    return true;
}

int main() {
    int n;

    cout << "Please enter number of nodes: ";
    cin >> n;

    if(n == 0)
        return 0;

    int value;
    cin >> value;

    ListNode* head = new ListNode(value);
    ListNode* tail = head;

    for(int i = 1; i < n; i++) {
        cin >> value;
        tail->next = new ListNode(value);
        tail = tail->next;
    }

    if(isPalindrome(head))
        cout << "Palindrome" << endl;
    else
        cout << "Not Palindrome" << endl;

    return 0;
}