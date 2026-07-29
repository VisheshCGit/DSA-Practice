#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int searchInsert(vector<int> &nums,int target){
        int low=0,high=nums.size()-1;

        while(low<=high){
            int mid=low+(high-low)/2;

            if(nums[mid]==target)
                return mid;
            else if(target<nums[mid])
                high=mid-1;
            else
                low=mid+1;
        }

        return low;
    }
};

int main(){

    int n;

    cout<<"Enter number of elements: ";
    cin>>n;

    vector<int> nums(n);

    cout<<"Enter array elements: ";

    for(int &x:nums)
        cin>>x;

    int target;

    cout<<"Enter target: ";
    cin>>target;

    Solution obj;

    cout<<"Insert Position = "<<obj.searchInsert(nums,target);

    return 0;
}