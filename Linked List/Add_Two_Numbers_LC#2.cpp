#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode() {
        val = 0;
        next = nullptr;
    }

    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dummy = new ListNode();
    ListNode* temp = dummy;

    int carry = 0;

    while(l1 != nullptr || l2 != nullptr || carry != 0) {
        int sum = carry;

        if(l1 != nullptr) {
            sum += l1->val;
            l1 = l1->next;
        }

        if(l2 != nullptr) {
            sum += l2->val;
            l2 = l2->next;
        }

        carry = sum / 10;

        ListNode* newNode = new ListNode(sum % 10);

        temp->next = newNode;
        temp = temp->next;
    }

    return dummy->next;
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
    int n1, n2;

    cout << "Please enter number of nodes in first list: ";
    cin >> n1;

    ListNode* l1 = nullptr;
    ListNode* tail1 = nullptr;

    cout << "Please enter values of first list: ";

    for(int i = 0; i < n1; i++) {
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
    cin >> n2;

    ListNode* l2 = nullptr;
    ListNode* tail2 = nullptr;

    cout << "Please enter values of second list: ";

    for(int i = 0; i < n2; i++) {
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

    ListNode* ans = addTwoNumbers(l1, l2);

    cout << "Sum List: ";
    printList(ans);

    return 0;
}