#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution{
public:
    int firstStableIndex(vector<int> &nums,int k){
        int n=nums.size();
        vector<int> maxi(n);
        int largest=INT_MIN;

        for(int i=0;i<n;i++){
            largest=max(largest,nums[i]);
            maxi[i]=largest;
        }

        int mini=INT_MAX,ans=-1;

        for(int i=n-1;i>=0;i--){
            mini=min(mini,nums[i]);
            int instability=maxi[i]-mini;

            if(instability<=k)
                ans=i;
        }

        return ans;
    }
};

int main(){
    int n,k;

    cout<<"Enter number of elements: ";
    cin>>n;

    vector<int> nums(n);

    cout<<"Enter elements: ";
    for(int &x:nums)
        cin>>x;

    cout<<"Enter k: ";
    cin>>k;

    Solution obj;

    cout<<"First Stable Index = "<<obj.firstStableIndex(nums,k);

    return 0;
}