#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {

    unordered_map<int, int> freq;

    for(int num : nums)
        freq[num]++; //Hashmap Initializes all the values to be zero for a key

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap; // Min Heap is required because we are popping elements when heap size becomes greater than k so we want elements will lower frequency to be popped so a min heap ensures that everytime the element with lowest frequency remains at the top...
    for(auto &x : freq) { //& is required otherwise a copy of pair is made every time..
        minHeap.push({x.second, x.first});
        if(minHeap.size() > k)
            minHeap.pop();
    }

    vector<int> ans;

    while(!minHeap.empty()) {

        ans.push_back(minHeap.top().second);
        minHeap.pop();
    }

    return ans;
}

int main() {

    int n, k;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array elements: ";
    for(int i = 0; i < n; i++)
        cin >> nums[i];

    cout << "Enter k: ";
    cin >> k;

    vector<int> ans = topKFrequent(nums, k);

    cout << "Top K Frequent Elements: ";

    for(int x : ans)
        cout << x << " ";

    return 0;
}