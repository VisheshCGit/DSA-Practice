#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int findPeakElement(vector<int>& nums) {

        int low = 0;
        int high = nums.size() - 1;

        while (low < high) {  //arr[-1]=-infinite and also arr[m]=-infinite m>=n.. so this logic works 

            int mid = low + (high - low) / 2; // and we can observe that one of the peak element is also the max element of array
            // We are on an increasing slope.
            // A peak must exist somewhere on the right side.
            if (nums[mid] < nums[mid + 1]) {
                low = mid + 1; //because if some element is greater than the current then the peak must be present after that element 
            }
            // We are on a decreasing slope
            // or already at a peak.
            // A peak must exist on the left side (including mid).
            else {
                high = mid;
            }
        }
        // low == high
        // This index points to a peak element.
        return low;
    }
};

int main() {

    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array elements: ";

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;

    int peakIndex = obj.findPeakElement(nums);

    cout << "Peak Element Index = " << peakIndex << endl;
    cout << "Peak Element Value = " << nums[peakIndex] << endl;

    return 0;
}