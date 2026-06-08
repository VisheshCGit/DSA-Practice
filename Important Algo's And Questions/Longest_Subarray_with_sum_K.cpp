#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int longestSubarray(vector<int>& nums, int k) {
    int n = nums.size();
    int ans = 0;

    unordered_map<int, int> mp;
    mp[0] = -1;

    int sum = 0;
    int cs = 0;

    for(int i = 0; i < n; i++) {
        sum += nums[i];

        if(mp.find(sum) == mp.end()) // we are using prefix sum but we haven't created another vector... sum is storing the current prefix sum
            mp[sum] = i; // same prefix sum can appear multiple times but we need to store the first occurrence not latest to get longest subarray

        cs = sum;                // so we update the map value once only... to get the subarray of size 1.. we initialised mp[0]=-1
        int target = cs - k;

        if(mp.find(target) != mp.end())
            ans = max(ans, i - mp[target]);
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

    int ans = longestSubarray(nums, k);

    cout << "Length of longest subarray: " << ans << endl;

    return 0;
}