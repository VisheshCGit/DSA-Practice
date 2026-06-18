#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int m = nums1.size();
        int n = nums2.size();

        // Always perform binary search on the smaller array
        if (m > n)
            return findMedianSortedArrays(nums2, nums1); // make sure nums1 is the array with the smaller element.. so that we can work on the smaller array to reduce the time

        int leftElements = (m + n + 1) / 2; //valid for both (m+n) odd and even

        int low = 0; //at minimum 0 elements can be taken from nums1    Remember high and low doesn't represent index, they represent the number of elemets taken from the smaller array to from the answer...
        int high = m;//at max all the elements can be taken from nums1..

        while (low <= high) {
            int partition1 = low + (high - low) / 2;
            int partition2 = leftElements - partition1;
            int left1 = INT_MIN; // comparison is done everytime the loop runs so always initialize them before finding the valid configuration
            int left2 = INT_MIN; //only 1 possible configuration exists and we are finding that only so resetting the values for every iteration is importamt else previous state configuration can be reused in finding the valid config...
            int right1 = INT_MAX;
            int right2 = INT_MAX;
            if (partition1 > 0)
                left1 = nums1[partition1 - 1];   //for total number of elements (m+n)=odd, we are taking higher element on the left that's why max(l1,l2) is done to find median
            if (partition2 > 0)
                left2 = nums2[partition2 - 1];
            if (partition1 < m)
                right1 = nums1[partition1];
            if (partition2 < n)
                right2 = nums2[partition2];
            if (left2 > right1) {
                // Need more elements from nums1 on left side
                low = partition1 + 1;
            }
            else if (left1 > right2) {
                // Need fewer elements from nums1 on left side
                high = partition1 - 1;
            }
            else { // Correct partition found
                if ((m + n) % 2 == 0) {
                    return ((double)max(left1, left2)
                            + (double)min(right1, right2)) / 2.0;
                }
                return max(left1, left2); //median is present on the left side from the partition
            }
        }
        return 0.0;
    }
};

int main() {
    int m, n;
    cout << "Enter size of first array: ";
    cin >> m;
    vector<int> nums1(m);
    cout << "Enter elements of first sorted array: ";
    for (int i = 0; i < m; i++)
        cin >> nums1[i];
    cout << "Enter size of second array: ";
    cin >> n;
    vector<int> nums2(n);
    cout << "Enter elements of second sorted array: ";
    for (int i = 0; i < n; i++)
        cin >> nums2[i];
    Solution obj;
    cout << "Median = "
         << obj.findMedianSortedArrays(nums1, nums2)
         << endl;
    return 0;
}