#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
 //Find the breaking index by scanning from the last... Then find the minimum Largest by Scanning from the index till index(Exclusive)... the swap and reverse the array from index till last
void nextPermutation(vector<int>& nums) {
    int index = -1;
    int n = nums.size();

    for(int i = n - 2; i >= 0; i--) {
        if(nums[i + 1] > nums[i]) {
            index = i;
            break;
        }
    }

    if(index == -1) {
        reverse(nums.begin(), nums.end());
    }
    else {
        for(int i = n - 1; i > index; i--) {
            if(nums[i] > nums[index]) {
                swap(nums[i], nums[index]);
                break;
            }
        }

        reverse(nums.begin() + index + 1, nums.end());
    }
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

    nextPermutation(nums);

    cout << "Next permutation: ";
    for(int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}