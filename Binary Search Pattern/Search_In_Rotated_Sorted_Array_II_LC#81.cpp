#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    bool search(vector<int>& nums, int target) {

        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target)
                return true;
            // Duplicates are hiding the structure of the array.
            // We cannot determine which half is sorted.
            if (nums[low] == nums[mid] &&
                nums[mid] == nums[high]) {
                low++;
                high--;
                continue;
            }
            // Left half is sorted
            if (nums[mid] > nums[high]) {
                if (target >= nums[low] &&
                    target < nums[mid]) {
                    high = mid - 1;
                }
                else {
                    low = mid + 1;
                }
            }
            // Right half is sorted
            else {
                if (target > nums[mid] &&
                    target <= nums[high]) {

                    low = mid + 1;
                }
                else 
                     high = mid - 1;
            }
        }
        return false;
    }
};

int main() {
    int n, target;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << "Enter target: ";
    cin >> target;
    Solution obj;
    if (obj.search(nums, target))
        cout << "Target Found\n";
    else
        cout << "Target Not Found\n";
    return 0;
}