#include<iostream>
#include<vector>
#include<climits>
using namespace std;

vector<int> majorityElement(vector<int>& nums) {
    int n = nums.size();
 // Moore Voting algo
    int candidate1 = INT_MIN;
    int candidate2 = INT_MIN;

    int count1 = 0;
    int count2 = 0;

    // First pass: find possible candidates
    for(int i = 0; i < n; i++) {

        if(nums[i] == candidate1)
            count1++;

        else if(nums[i] == candidate2)
            count2++;

        else if(count1 == 0) {
            candidate1 = nums[i];
            count1 = 1;
        }

        else if(count2 == 0) {
            candidate2 = nums[i];
            count2 = 1;
        }

        else {
            count1--;
            count2--;
        }
    }

    // Second pass: verify frequencies
    count1 = 0;
    count2 = 0;

    for(int i = 0; i < n; i++) {
        if(nums[i] == candidate1)
            count1++;
        else if(nums[i] == candidate2)
            count2++;
    }

    vector<int> ans;

    if(count1 > n / 3)
        ans.push_back(candidate1);

    if(count2 > n / 3)
        ans.push_back(candidate2);

    return ans;
}

int main() {
    int n;

    cout << "Please enter array length: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Please enter array elements: ";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<int> ans = majorityElement(nums);

    if(ans.empty()) {
        cout << "No element appears more than n/3 times." << endl;
    }
    else {
        cout << "Elements appearing more than n/3 times: ";
        for(int num : ans)
            cout << num << " ";
        cout << endl;
    }

    return 0;
}