#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> findMissingRepeatingNumbers(vector<int>& nums) {
    int n = nums.size();
    unordered_map<int, int> mp;

    int repeating;
    long long sum = 0;

    for(int i = 0; i < n; i++) {
        sum += nums[i];

        if(mp.find(nums[i]) != mp.end())
            repeating = nums[i];
        else
            mp[nums[i]] = 1;
    }

    sum -= repeating;

    long long expectedSum = 1LL * n * (n + 1) / 2;

    vector<int> ans;
    ans.push_back(repeating);
    ans.push_back(expectedSum - sum);

    return ans;
}

int main() {
    int n;

    cout << "Please enter array length: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Please enter array elements: ";
    for(int i = 0; i < n; i++)
        cin >> nums[i];

    vector<int> ans = findMissingRepeatingNumbers(nums);

    cout << "Repeating Number: " << ans[0] << endl;
    cout << "Missing Number: " << ans[1] << endl;

    return 0;
}