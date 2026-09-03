#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution{
public:
    bool uniformArray(vector<int> &nums){
        int mini=INT_MAX,count=0;

        for(auto x:nums)
            mini=min(mini,x);

        for(auto x:nums){
            if(x%2==0)
                count++;
        }

        if(count==nums.size())
            return true;

        return mini&1;
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

    cout<<"Result: "<<obj.uniformArray(nums);

    return 0;
}