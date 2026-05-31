#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> sortedSquares(vector<int>& nums){
    int i;
    int j=0;

    for(i=0;i<nums.size();i++){
        if(nums[i]<=0)
            j++;

        nums[i]*=nums[i];
    }

    int x=j;

    reverse(nums.begin(),nums.begin()+x);

    if(x==nums.size())
        return nums;

    i=0;

    vector<int> ans;

    while(i<x && j<nums.size()){
        if(nums[i]<=nums[j]){
            ans.push_back(nums[i]);
            i++;
        }
        else{
            ans.push_back(nums[j]);
            j++;
        }
    }

    while(i<x){
        ans.push_back(nums[i]);
        i++;
    }

    while(j<nums.size()){
        ans.push_back(nums[j]);
        j++;
    }

    return ans;
}

int main(){
    int n;

    cout<<"Please enter array length: ";
    cin>>n;

    vector<int> nums(n);

    cout<<"Please enter array elements: ";
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    vector<int> result=sortedSquares(nums);

    cout<<"Sorted squares array: ";

    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }

    return 0;
}