#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int subarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    int ans = 0;

    unordered_map<int, int> mp;
    mp[0] = 1;

    int sum = 0;

    for(int i = 0; i < n; i++) {
        sum += nums[i];

        int target = sum - k;

        if(mp.find(target) != mp.end())
            ans += mp[target];

        mp[sum]++;
    }

    return ans;
}

int main() {
    int n, k;

    cout << "Please enter array length: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Please enter array elements: ";
    for(int i = 0; i < n; i++)
        cin >> nums[i];

    cout << "Please enter target sum: ";
    cin >> k;

    int ans = subarraySum(nums, k);

    cout << "Number of subarrays with sum " << k << " is: " << ans << endl;

    return 0;
}