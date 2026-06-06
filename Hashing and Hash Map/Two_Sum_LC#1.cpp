#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> mp;

    for(int i = 0; i < nums.size(); i++) {
        if(mp.find(target - nums[i]) != mp.end())
            return {mp[target - nums[i]], i};

        mp[nums[i]] = i;
    }

    return {};
}

int main() {
    int n, target;

    cout << "Please enter array length: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Please enter array elements: ";
    for(int i = 0; i < n; i++)
        cin >> nums[i];

    cout << "Please enter target value: ";
    cin >> target;

    vector<int> ans = twoSum(nums, target);

    if(ans.size() == 2)
        cout << "Indices are: " << ans[0] << " " << ans[1] << endl;
    else
        cout << "No valid pair found." << endl;

    return 0;
}