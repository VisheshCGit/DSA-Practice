#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>& arr, int low, int mid, int high) {
    int left = low;
    int right = mid + 1;

    vector<int> temp;

    while(left <= mid && right <= high) {
        if(arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    while(left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    while(right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    for(int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

long long countPairs(vector<int>& arr, int low, int mid, int high) {
    long long count = 0;

    int right = mid + 1;

    for(int i = low; i <= mid; i++) {

        while(right <= high &&
              (long long)arr[i] > 2LL * arr[right]) {
            right++;
        }

        count += right - (mid + 1);
    }

    return count;
}

long long mergeSort(vector<int>& arr, int low, int high) {

    if(low >= high)
        return 0;

    int mid = low + (high - low) / 2;

    long long count = 0;

    count += mergeSort(arr, low, mid);
    count += mergeSort(arr, mid + 1, high);

    count += countPairs(arr, low, mid, high);

    merge(arr, low, mid, high);

    return count;
}

int reversePairs(vector<int>& nums) {
    return (int)mergeSort(nums, 0, nums.size() - 1);
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

    int answer = reversePairs(nums);

    cout << "Number of reverse pairs: " << answer << endl;

    return 0;
}