#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            // Make mid point to the first index of a pair
            if (mid % 2 == 1)
                mid--;
            // Before the single element:
            // pairs start at even indices.
            // If the pair is valid, the answer lies on the right side.
            if (nums[mid] == nums[mid + 1]) {
                low = mid + 2;
            }
            // Pair pattern is broken.
            // Single element lies on the left side (including mid).
            else {
                high = mid;
            }
        }
        return nums[low];
    }
};
int main() {
    int n;
    cout << "Please enter array size: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Please enter sorted array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    Solution obj;
    cout << "Single Element = "
         << obj.singleNonDuplicate(nums)
         << endl;

    return 0;
}