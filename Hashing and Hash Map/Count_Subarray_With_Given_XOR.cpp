#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int subarraysWithXorK(vector<int>& nums, int k) {
    int n = nums.size();
    int xr = 0;
    int ans = 0;

    unordered_map<int, int> mp;
    mp[0] = 1;

    for(int i = 0; i < n; i++) {
        xr ^= nums[i];

        if(mp.find(xr ^ k) != mp.end())
            ans += mp[xr ^ k];

        mp[xr]++;
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

    cout << "Please enter target XOR value: ";
    cin >> k;

    int ans = subarraysWithXorK(nums, k);

    cout << "Number of subarrays with XOR " << k << " is: " << ans << endl;

    return 0;
}