#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

vector<int> maxSumCombinations(vector<int>& nums1, vector<int>& nums2, int k) {

    int n = nums1.size();

    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());  //Heap Stores - Candidate, state

    priority_queue<pair<int, pair<int, int>>> maxHeap;
    set<pair<int, int>> visited;

    maxHeap.push({nums1[n - 1] + nums2[n - 1], {n - 1, n - 1}});
    visited.insert({n - 1, n - 1});

    vector<int> ans;

    while(k-- && !maxHeap.empty()) {
        auto curr = maxHeap.top();
        maxHeap.pop();
        int sum = curr.first;
        int i = curr.second.first;
        int j = curr.second.second;
             ans.push_back(sum);
            if(i-1 >= 0 && visited.find({i-1, j}) == visited.end()) {
                maxHeap.push({nums1[i-1]+nums2[j], {i-1, j}});
                visited.insert({i-1, j});
            }
            if(j-1 >= 0 && visited.find({i, j-1}) == visited.end()) {
                maxHeap.push({nums1[i]+nums2[j-1], {i, j-1}});
                visited.insert({i, j-1});
            }
       
    }

    return ans;
}

int main() {

    int n, k;

    cout << "Enter size of arrays: ";
    cin >> n;

    vector<int> nums1(n), nums2(n);

    cout << "Enter elements of first array: ";
    for(int i = 0; i < n; i++)
        cin >> nums1[i];

    cout << "Enter elements of second array: ";
    for(int i = 0; i < n; i++)
        cin >> nums2[i];

    cout << "Enter k: ";
    cin >> k;

    vector<int> ans = maxSumCombinations(nums1, nums2, k);

    cout << "Maximum Sum Combinations:\n";

    for(int x : ans)
        cout << x << " ";

    return 0;
}