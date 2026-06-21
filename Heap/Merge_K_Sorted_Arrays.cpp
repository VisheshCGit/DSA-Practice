#include <iostream>
#include <vector>
#include <queue>
using namespace std; //21-6-2026

vector<int> mergeKSortedArrays(vector<vector<int>>& arr, int k) {

    priority_queue<
        pair<int, pair<int, int>>,
        vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>>
    > minHeap;

    for(int i = 0; i < k; i++)
        minHeap.push({arr[i][0], {i, 0}});

    vector<int> ans;

    while(!minHeap.empty()) { // we are maintaining at max k elements in the heap.. when we pop the top element(smallest), we push the next value just after with the proper index... so overall T.C. becomes O(k^2log(k)) rather than O(k^2log(k^2))...
       auto curr = minHeap.top(); // we have used the thing that the array is sorted row wise... so we are maintaining at amx k elements at a time
        minHeap.pop();
        int value = curr.first;
        int row = curr.second.first; //row index of the top value
        int col = curr.second.second;//column index of top value
        ans.push_back(value);
        if(col < k-1) // as we are doing col+1 so it should be less than k 
            minHeap.push({arr[row][col + 1], {row, col + 1}});
    }
    return ans;
}

int main() {

    int k;

    cout << "Enter number of arrays: ";
    cin >> k;

    vector<vector<int>> arr(k, vector<int>(k));

    cout << "Enter elements of sorted arrays:\n";

    for(int i = 0; i < k; i++) {
        for(int j = 0; j < k; j++)
            cin >> arr[i][j];
    }

    vector<int> ans = mergeKSortedArrays(arr, k);

    cout << "Merged Sorted Array:\n";

    for(int x : ans)
        cout << x << " ";

    return 0;
}