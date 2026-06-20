#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int kthLargestElement(vector<int>& nums, int k) {

    priority_queue<int> maxHeap(nums.begin(), nums.end()); // build max heap in O(n)

    int answer = -1;

    while(k--) {

        answer = maxHeap.top(); // current largest element
        maxHeap.pop(); // remove it from heap
    }

    return answer;
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

    cout << "Kth Largest Element: " << kthLargestElement(nums, k);

    return 0;
}