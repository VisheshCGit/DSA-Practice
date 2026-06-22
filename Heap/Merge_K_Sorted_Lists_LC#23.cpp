#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct ListNode { //22-06-2026
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

ListNode* mergeKLists(vector<ListNode*>& lists) {

    priority_queue< pair<int, ListNode*>, vector<pair<int, ListNode*>>,greater<pair<int, ListNode*>>> minHeap;
       
    for(auto node : lists) {
        if(node)
            minHeap.push({node->val, node});
    }

    ListNode* dummy = new ListNode(-1);
    ListNode* tail = dummy;

    while(!minHeap.empty()) {

        auto curr = minHeap.top();
        minHeap.pop();

        tail->next = curr.second;
        tail = tail->next;

        if(curr.second->next)
            minHeap.push({curr.second->next->val, curr.second->next});          
    }

    return dummy->next;
}

int main() {

    cout << "Use this function on LeetCode/GFG input.\n";

    return 0;
}