#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:

    int kthElement(vector<int>& nums1, vector<int>& nums2, int k) {

        int m = nums1.size();
        int n = nums2.size();
        // Always perform binary search on the smaller array
        if (m > n)
            return kthElement(nums2, nums1, k); // same logic as for median of 2 sorted array
        // Number of elements to be kept on the left side
        int leftElements = k;
        // Ensure partition2 remains within valid bounds [0, n]
        int low = max(0, k - n); // because if k=4, n=3, m=2.. that means left half should contain 4 elements but from larger array, at max 3 elements can come so from smaller array, a minumum of k-n=1 element should be present.. 
        int high = min(k, m);

        while (low <= high) {

            int partition1 = low + (high - low) / 2;
            int partition2 = leftElements - partition1;

            int left1  = (partition1 == 0) ? INT_MIN : nums1[partition1 - 1];
            int left2  = (partition2 == 0) ? INT_MIN : nums2[partition2 - 1];

            int right1 = (partition1 == m) ? INT_MAX : nums1[partition1];
            int right2 = (partition2 == n) ? INT_MAX : nums2[partition2];

            // Partition is too far right in nums1
            if (left1 > right2) {

                high = partition1 - 1;
            }

            // Partition is too far left in nums1
            else if (left2 > right1) {

                low = partition1 + 1;
            }

            // Correct partition found
            else {

                return max(left1, left2);
            }
        }

        return -1;
    }
};

int main() {

    int m, n, k;

    cout << "Enter size of first sorted array: ";
    cin >> m;

    vector<int> nums1(m);

    cout << "Enter elements of first sorted array: ";

    for (int i = 0; i < m; i++)
        cin >> nums1[i];

    cout << "Enter size of second sorted array: ";
    cin >> n;

    vector<int> nums2(n);

    cout << "Enter elements of second sorted array: ";

    for (int i = 0; i < n; i++)
        cin >> nums2[i];

    cout << "Enter k: ";
    cin >> k;

    Solution obj;

    cout << "Kth Element = "
         << obj.kthElement(nums1, nums2, k)
         << endl;

    return 0;
}