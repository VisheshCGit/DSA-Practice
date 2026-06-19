#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int findMin(vector<int>& nums) {

        int low = 0;  //In a Rotated Sorted Array, One half is always Sorted...
        int high = nums.size() - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            // Rotation point lies on the right side
            if (nums[mid] > nums[high]) 
                low = mid + 1; // because this half is breaking the sorted nature that means a minimum lies in that half
            // Minimum is either at mid or on the left side
            else 
                high = mid;
        }
        return nums[low];
    }
};

int main() {

    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter elements of rotated sorted array: ";

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;

    cout << "Minimum Element = "
         << obj.findMin(nums)
         << endl;

    return 0;
}