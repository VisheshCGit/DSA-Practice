#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution{
public:
    int maxSubarrayLength(vector<int> &nums,int k){
        unordered_map<int,int> mp;
        int left=0,ans=0;

        for(int right=0;right<nums.size();right++){
            mp[nums[right]]++;

            while(mp[nums[right]]>k)
                mp[nums[left++]]--;

            ans=max(ans,right-left+1);
        }

        return ans;
    }
};

int main(){
    int n,k;

    cout<<"Enter number of elements: ";
    cin>>n;

    vector<int> nums(n);

    cout<<"Enter array elements: ";
    for(int &x:nums)
        cin>>x;

    cout<<"Enter k: ";
    cin>>k;

    Solution obj;

    cout<<"Maximum Subarray Length = "<<obj.maxSubarrayLength(nums,k);

    return 0;
} 