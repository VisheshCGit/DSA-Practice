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

ListNode* detectCycle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while(fast != nullptr && fast->next != nullptr) {   // First find the meeting point of both the pointers...
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast) {   //if they met, then cycle exists.. 
            slow = head;

            while(slow != fast) {  // Now, it cam be observed that distance from head to entrance of cycle is equal to the distance from fast to the entrance point 
                slow = slow->next;   // so now both the pointer moves 1 step each and the place where they meet is the entry point of cycle
                fast = fast->next;
            }

            return slow;
        }
    }

    return nullptr;
}

int main() {
    cout << "This problem requires creating a linked list with a cycle." << endl;
    cout << "It is usually tested directly on platforms like LeetCode." << endl;

    return 0;
}