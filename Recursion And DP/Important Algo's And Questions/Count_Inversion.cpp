#include<iostream>
#include<vector>
using namespace std;
     // Apply Merge Sort and Count number of inversions for recursively divided Subarray... 
     // When you Merge 2 sorted Sub-arrays, The inversion count for each Subarray is 0 and is already counted 
     // Can think of like divide and conquer.. not exactly but kind of...
 //Count inversion for recursively divided Sub-Array and then sort it... Now after Sorting The inversion count becomes 0 for that part... 
long long merge(vector<int>& arr, int low, int mid, int high){
    int l = low;
    int r = mid + 1;
    long long count = 0;
    vector<int> ds;
    while(l <= mid && r <= high){
        if(arr[l] > arr[r]){
            ds.push_back(arr[r]);
            count += mid - l + 1;
            r++;
        }
        else{
            ds.push_back(arr[l]);
            l++;
        }
    }
    while(l <= mid){
        ds.push_back(arr[l]);
        l++;
    }
    while(r <= high){
        ds.push_back(arr[r]);
        r++;
    }
    for(int i = low; i <= high; i++){
        arr[i] = ds[i - low];
    }
    return count;
}

long long mergeSort(vector<int>& arr, int low, int high){
    long long count = 0;
    if(low >= high)
        return count;
    int mid = low + (high - low) / 2;
    count += mergeSort(arr, low, mid);
    count += mergeSort(arr, mid + 1, high);
    count += merge(arr, low, mid, high);
    return count;
}

long long numberOfInversions(vector<int>& nums){
    return mergeSort(nums, 0, nums.size() - 1);
}

int main(){
    int n;
    cout<<"Please enter array length: ";
    cin>>n;
    vector<int> nums(n);
    cout<<"Please enter array elements: ";
    for(int i = 0; i < n; i++){
        cin>>nums[i];
    }
    long long inversions = numberOfInversions(nums);
    cout<<"Number of inversions: "<<inversions<<endl;
    return 0;
}