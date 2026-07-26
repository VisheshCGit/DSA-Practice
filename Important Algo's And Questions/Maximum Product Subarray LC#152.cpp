#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution{
public:

    // Returns the maximum product of any contiguous subarray
    int maxProduct(vector<int> &nums){

        int answer=INT_MIN;

        int prefix=1;
        int suffix=1;

        int n=nums.size();

        for(int i=0;i<n;i++){

            // Start a new segment after a zero
            if(prefix==0)
                prefix=1;

            if(suffix==0)
                suffix=1;

            // Product from left to right
            prefix*=nums[i];

            // Product from right to left
            suffix*=nums[n-i-1];

            // Best product seen so far
            answer=max(answer,max(prefix,suffix));
        }

        return answer;
    }
};

int main(){

    Solution obj;

    int n;

    cout<<"Enter number of elements: ";
    cin>>n;

    vector<int> nums(n);

    cout<<"Enter array elements: ";

    for(int &x:nums)
        cin>>x;

    cout<<"Maximum Product = "<<obj.maxProduct(nums);

    return 0;
}