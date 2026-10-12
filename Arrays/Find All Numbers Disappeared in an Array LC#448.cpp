#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        int n=nums.size();

        for(int i=0; i<n; i++){
            int x=abs(nums[i]);
            if(x-1<n && nums[x-1]>0) nums[x-1]*=-1;
        }

        for(int i=0; i<n; i++){
            if(nums[i]>0) ans.push_back(i+1);
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

    vector<int> ans=obj.findDisappearedNumbers(nums);

    cout<<"Missing numbers: ";
    for(auto x:ans)
        cout<<x<<" ";

    return 0;
}