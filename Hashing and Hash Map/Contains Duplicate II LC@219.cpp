#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution{
public:
    bool containsNearbyDuplicate(vector<int> &nums,int k){
        unordered_map<int,int> mp;

        for(int i=0;i<nums.size();i++){
            if(mp.find(nums[i])!=mp.end() && i-mp[nums[i]]<=k)
                return true;

            mp[nums[i]]=i;
        }

        return false;
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

    if(obj.containsNearbyDuplicate(nums,k))
        cout<<"True";
    else
        cout<<"False";

    return 0;
}