#include<iostream>
#include<vector>
using namespace std;

int majorityElement(vector<int>& nums){
    if(nums.size()<=2)
       return nums[0];
       int count=1, val=nums[0];
        for(int i=1; i<nums.size(); i++){
            if(count==0)
             val=nums[i];
            if(nums[i]==val)
            count++;
            else
            count--;

        }
        return val;
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

    int result=majorityElement(nums);

    cout<<"Majority element in the array is: "<<result;

    return 0;
}