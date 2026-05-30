#include<iostream>
#include<vector>
using namespace std;

bool subsetSum(int i, vector<int>& nums, int sum, int n, int cs){
    if(cs==sum)
        return true;

    if(i==n || cs>sum)
        return false;

    cs+=nums[i];
    bool pick=subsetSum(i+1, nums, sum, n, cs);

    cs-=nums[i];
    bool non_pick=subsetSum(i+1, nums, sum, n, cs);

    if(pick==true || non_pick==true)
        return true;
    else
        return false;
}

bool canPartition(vector<int>& nums){
    int sum=0;
    int n=nums.size();

    for(int i=0;i<n;i++)
        sum+=nums[i];

    if(sum%2==0)
        sum/=2;
    else
        return false;

    return subsetSum(0, nums, sum, n, 0);
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

    bool result=canPartition(nums);

    if(result)
        cout<<"Array can be partitioned into two subsets with equal sum.";
    else
        cout<<"Array cannot be partitioned into two subsets with equal sum.";

    return 0;
}