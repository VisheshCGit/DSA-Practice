#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution{
public:
    int firstStableIndex(vector<int> &nums,int k){
        int n=nums.size();
        vector<int> mini(n);
        int minimum=INT_MAX;

        for(int i=n-1;i>=0;i--){
            minimum=min(minimum,nums[i]);
            mini[i]=minimum;
        }

        int maxi=INT_MIN;

        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
            int instability=maxi-mini[i];

            if(instability<=k)
                return i;
        }

        return -1;
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