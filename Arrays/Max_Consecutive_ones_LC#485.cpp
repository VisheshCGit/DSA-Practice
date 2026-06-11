#include<iostream>
#include<vector>
using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums){

    int currentCount=0;
    int maximumCount=0;

    for(int i=0;i<nums.size();i++){

        if(nums[i]==1)
            currentCount++;
        else
            currentCount=0;

        maximumCount=max(maximumCount,currentCount);
    }

    return maximumCount;
}

int main(){

    int n;

    cout<<"Please enter array size: ";
    cin>>n;

    vector<int> nums(n);

    cout<<"Please enter array elements: ";
    for(int i=0;i<n;i++)
        cin>>nums[i];

    cout<<"Maximum consecutive ones: "
        <<findMaxConsecutiveOnes(nums);

    return 0;
}