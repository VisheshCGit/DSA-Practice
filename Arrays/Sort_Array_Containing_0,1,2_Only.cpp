#include <iostream>
#include <vector>
using namespace std;

void sortZeroOneTwo(vector<int>& nums) {
    int n = nums.size();                     //Striver's SDE Sheet's Question No. 5 of Array-I
    int low = 0, mid = 0, high = n - 1;      //Dutch National Flag's Algorithm is used!!
    while (mid <= high) {
        if (nums[mid] == 2) {                 //Partition the Array in 3 reigns Containing 1, 2, and 0s. 
            swap(nums[mid], nums[high]);
            high--;
        }
        else if (nums[mid] == 0) {
            swap(nums[mid], nums[low]);
            low++;
            mid++;
        }
        else {
            mid++;
        }
    }
}

int main() {
    int n;

    cout << "Please enter array length: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Please enter array elements (only 0, 1, and 2): ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    sortZeroOneTwo(nums);

    cout << "Sorted array: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}