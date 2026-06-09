#include <iostream>
#include <vector>
using namespace std;

int findDuplicate(vector<int>& nums) {
    int slow = 0;
    int fast = 0;

    while(true) {
        slow = nums[slow];
        fast = nums[nums[fast]];  // Floyd's Method of Cycle Detection using fast and slow pointers

        if(slow == fast)
            break;
    }

    slow = 0;

    while(slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }

    return slow;
}

int main() {
    int n;

    cout << "Please enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Please enter array elements: ";
    for(int i = 0; i < n; i++)
        cin >> nums[i];

    cout << "Duplicate Number: " << findDuplicate(nums) << endl;

    return 0;
}