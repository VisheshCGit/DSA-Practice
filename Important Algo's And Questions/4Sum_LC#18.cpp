#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums,int target){
    vector<vector<int>> ans;

    sort(nums.begin(),nums.end());  //k Sum  -> Fix (k-2) elements + Two Pointers    2 Sum  -> Two Pointers

    int n=nums.size();

    for(int i=0;i<n;i++){
        if(i>0 && nums[i]==nums[i-1])
            continue;

        for(int j=i+1;j<n;j++){
            if(j>i+1 && nums[j]==nums[j-1])
                continue;

            int left=j+1;
            int right=n-1;

            while(left<right){
                long long sum=(long long)nums[i]+nums[j]+nums[left]+nums[right];

                if(sum<target)
                    left++;
                else if(sum>target)
                    right--;
                else{
                    ans.push_back({nums[i],nums[j],nums[left],nums[right]});

                    left++;
                    right--;

                    while(left<right && nums[left]==nums[left-1])
                        left++;

                    while(left<right && nums[right]==nums[right+1])
                        right--;
                }
            }
        }
    }

    return ans;
}

int main(){
    int n;

    cout<<"Please enter array length: ";
    cin>>n;

    vector<int> nums(n);

    cout<<"Please enter array elements: ";
    for(int i=0;i<n;i++)
        cin>>nums[i];

    int target;

    cout<<"Please enter target: ";
    cin>>target;

    vector<vector<int>> ans=fourSum(nums,target);

    cout<<"Quadruplets are:\n";

    for(auto &quad:ans){
        for(int num:quad)
            cout<<num<<" ";
        cout<<endl;
    }

    return 0;
}