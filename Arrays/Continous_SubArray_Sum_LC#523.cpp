#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool checkSubarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> firstIndex;

    // Handles the case where a prefix itself is divisible by k
    firstIndex[0] = -1;

    long long prefixSum = 0;

    for (int i = 0; i < nums.size(); i++) {
        prefixSum += nums[i];

        int remainder = prefixSum % k;

        if (firstIndex.find(remainder) != firstIndex.end()) {

            if (i - firstIndex[remainder] >= 2) {
                return true;
            }

        } else {
            firstIndex[remainder] = i;
        }
    }

    return false;
}

int main() {
    int n;

    cout << "Please enter array length: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Please enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int k;
    cout << "Please enter value of k: ";
    cin >> k;

    bool result = checkSubarraySum(nums, k);

    if (result)
        cout << "Good subarray exists." << endl;
    else
        cout << "Good subarray does not exist." << endl;

    return 0;
}