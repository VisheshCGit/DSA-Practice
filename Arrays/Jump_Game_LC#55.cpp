#include<iostream>
#include<vector>
using namespace std;

bool canJump(vector<int>& nums){
    int rindex=0;

    for(int i=0;i<nums.size();i++){
        if(rindex>=nums.size()-1)
            return true;

        if(rindex>=i)
            rindex=max(i+nums[i],rindex);
    }

    return false;
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

    bool result=canJump(nums);

    if(result)
        cout<<"Last index is reachable.";
    else
        cout<<"Last index is not reachable.";

    return 0;
}