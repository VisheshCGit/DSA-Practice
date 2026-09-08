#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int missingNumber(vector<int> &nums){
        int n=nums.size();
        int ans=n;

        for(int i=0;i<n;i++)
            ans^=i^nums[i];

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

    cout<<"Missing Number = "<<obj.missingNumber(nums);

    return 0;
}