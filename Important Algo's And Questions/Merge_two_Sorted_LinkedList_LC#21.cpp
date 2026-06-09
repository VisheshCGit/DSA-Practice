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

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if(l1 == nullptr) return l2;
    if(l2 == nullptr) return l1;

    if(l1->val > l2->val)
        swap(l1, l2);  //we are making sure that after every iteration, l1 will be pointing to the minimum of l1 and l2

    ListNode* head = l1;

    while(l1 != nullptr && l2 != nullptr) {
        ListNode* temp = nullptr;

        while(l1 != nullptr && l1->val <= l2->val) { // when this while loop stops either the list is sorted or value of l1 becomes greater than l2.. and it's going against the invarient.. so we swap l1 and l2
            temp = l1;     // We have done in-place merging of the list which is highly optimized in terms of space and time 
            l1 = l1->next;
        }

        temp->next = l2;
        swap(l1, l2);
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
    int n, m;

    cout << "Please enter number of nodes in first list: ";
    cin >> n;

    ListNode* l1 = nullptr;
    ListNode* tail1 = nullptr;

    cout << "Please enter values of first sorted list: ";

    for(int i = 0; i < n; i++) {
        int value;
        cin >> value;

        if(l1 == nullptr) {
            l1 = new ListNode(value);
            tail1 = l1;
        }
        else {
            tail1->next = new ListNode(value);
            tail1 = tail1->next;
        }
    }

    cout << "Please enter number of nodes in second list: ";
    cin >> m;

    ListNode* l2 = nullptr;
    ListNode* tail2 = nullptr;

    cout << "Please enter values of second sorted list: ";

    for(int i = 0; i < m; i++) {
        int value;
        cin >> value;

        if(l2 == nullptr) {
            l2 = new ListNode(value);
            tail2 = l2;
        }
        else {
            tail2->next = new ListNode(value);
            tail2 = tail2->next;
        }
    }

    ListNode* mergedHead = mergeTwoLists(l1, l2);

    cout << "Merged Sorted List: ";
    printList(mergedHead);

    return 0;
}