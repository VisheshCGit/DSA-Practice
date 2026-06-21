#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {

    int n = nums1.size();
    int m = nums2.size();

    priority_queue<pair<long long, pair<int, int>>, vector<pair<long long, pair<int, int>>>,greater<pair<long long, pair<int, int>>>> minHeap;
    minHeap.push({1LL * nums1[0] + nums2[0], {0, 0}});

    set<pair<int, int>> visited;
    visited.insert({0, 0});

    vector<vector<int>> ans;

    while(k-- && !minHeap.empty()) {

        auto curr = minHeap.top();
        minHeap.pop();

        int i = curr.second.first;
        int j = curr.second.second;

        ans.push_back({nums1[i], nums2[j]});

        if(i + 1 < n && visited.find({i + 1, j}) == visited.end()) {

            minHeap.push({
                1LL * nums1[i + 1] + nums2[j],
                {i + 1, j}
            });

            visited.insert({i + 1, j});
        }

        if(j + 1 < m && visited.find({i, j + 1}) == visited.end()) {

            minHeap.push({
                1LL * nums1[i] + nums2[j + 1],
                {i, j + 1}
            });

            visited.insert({i, j + 1});
        }
    }

    return ans;
}

int main() {

    int n, m, k;

    cout << "Enter size of first array: ";
    cin >> n;

    vector<int> nums1(n);

    cout << "Enter elements of first sorted array: ";
    for(int i = 0; i < n; i++)
        cin >> nums1[i];

    cout << "Enter size of second array: ";
    cin >> m;

    vector<int> nums2(m);

    cout << "Enter elements of second sorted array: ";
    for(int i = 0; i < m; i++)
        cin >> nums2[i];

    cout << "Enter k: ";
    cin >> k;

    vector<vector<int>> ans = kSmallestPairs(nums1, nums2, k);

    cout << "K Smallest Pairs:\n";

    for(auto &pair : ans)
        cout << "[" << pair[0] << ", " << pair[1] << "]\n";

    return 0;
}