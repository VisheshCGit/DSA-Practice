#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int n=nums.size();

        for(int i=0; i<n; ){
            int start=nums[i];

            while(i+1<n && nums[i+1]==nums[i]+1)
                i++;

            if(start==nums[i])
                ans.push_back(to_string(start));
            else
                ans.push_back(to_string(start)+"->"+to_string(nums[i]));

            i++;
        }

        return ans;
    }
};

int main(){
    int n;

    cout<<"Enter number of elements: ";
    cin>>n;

    vector<int> nums(n);

    cout<<"Enter elements: ";
    for(int &x:nums)
        cin>>x;

    Solution obj;

    vector<string> ans=obj.summaryRanges(nums);

    cout<<"Summary Ranges: ";
    for(auto x:ans)
        cout<<x<<" ";

    return 0;
}