#include<iostream>
#include<vector>
#include<climits>
using namespace std;

vector<int> majorityElement(vector<int>& nums) {
    int n = nums.size();

    int E1 = INT_MIN;
    int E2 = INT_MIN;

    int count1 = 0;
    int count2 = 0;

    // Find potential majority elements
    for(int i = 0; i < n; i++) {   //Moore Voting Algorithm is used... There can be at most k-1 elements which are appearing more than n/k times

        if(count1 == 0 && nums[i] != E2) {   //Both E1 and E2 can't be same... We are looking for 2 Different Candidates
            E1 = nums[i];
            count1++;
        }

        else if(count2 == 0 && nums[i] != E1) {
            E2 = nums[i];  //Important Steps = the IF-Else conditions 
            count2++;
        }

        else if(nums[i] == E1) {
            count1++;
        }

        else if(nums[i] == E2) {
            count2++;
        }

        else {
            count1--;
            count2--;
        }
    }

    // Verify frequencies
    count1 = 0;
    count2 = 0;

    for(int i = 0; i < n; i++) {
        if(nums[i] == E1)
            count1++;
        else if(nums[i] == E2)
            count2++;
    }

    vector<int> ans;

    if(count1 > n / 3)
        ans.push_back(E1);

    if(count2 > n / 3)
        ans.push_back(E2);

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
        for(int num : ans) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}