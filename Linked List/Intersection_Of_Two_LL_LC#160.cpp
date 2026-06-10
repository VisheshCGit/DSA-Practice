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

ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    ListNode* ptrA = headA;
    ListNode* ptrB = headB;

    while(ptrA != ptrB) {  //ptrA and ptrB moves the same distance so the meet at either intersection or both becomes null in case of no intersection..
        if(ptrA == nullptr)  // Length of list 1- a+c  (c is the common part of both the list) Length of List 2 is (b+c)
            ptrA = headB;   //both the pointer travels both the list so distance moved by ptrA=(a+c)+(b+c).. ptrB=(b+c)+(a+c)
        else                   // we can see distance moved by ptrA == Distance moved by ptrB = a+b+2c... so eventually they meet at intersection..
            ptrA = ptrA->next;  // this is called path Equalization 

        if(ptrB == nullptr)   // no Hashing so S.C. = O(1).. T.C. = O(m+n)  Optimized
            ptrB = headA;
        else
            ptrB = ptrB->next;
    }

    return ptrA;
}

int main() {
    cout << "Intersection of Linked Lists problem requires two linked lists" << endl;
    cout << "sharing common nodes, so it is usually tested on platforms like LeetCode." << endl;

    return 0;
}