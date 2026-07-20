#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:

    // Returns the maximum possible frequency after performing
    // at most k increment operations
    int maxFrequency(vector<int>& nums, int k){

        sort(nums.begin(), nums.end());

        long long sum=nums[0];
        int left=0;
        int ans=1;

        for(int right=1; right<nums.size(); right++){

            sum+=nums[right];

            while(1LL*nums[right]*(right-left+1)-sum>k)
                sum-=nums[left++];

            ans=max(ans, right-left+1);
        }

        return ans;
    }
};

int main(){

    Solution obj;

    vector<int> nums={1,2,4};
    int k=5;

    cout<<"Maximum Frequency = "<<obj.maxFrequency(nums,k);

    return 0;
}