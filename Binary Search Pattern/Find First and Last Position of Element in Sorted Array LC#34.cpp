#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    vector<int> searchRange(vector<int> &nums,int target){
        int first=-1,last=-1;
        int low=0,high=(int)nums.size()-1;

        while(low<=high){
            int mid=low+(high-low)/2;

            if(nums[mid]==target){
                if(mid>0 && nums[mid-1]==target)
                    high=mid-1;
                else{
                    first=mid;
                    break;
                }
            }
            else if(nums[mid]>target)
                high=mid-1;
            else
                low=mid+1;
        }

        low=0;
        high=(int)nums.size()-1;

        while(low<=high){
            int mid=low+(high-low)/2;

            if(nums[mid]==target){
                if(mid<nums.size()-1 && nums[mid+1]==target)
                    low=mid+1;
                else{
                    last=mid;
                    break;
                }
            }
            else if(nums[mid]>target)
                high=mid-1;
            else
                low=mid+1;
        }

        return {first,last};
    }
};

int main(){
    int n,target;

    cout<<"Enter number of elements: ";
    cin>>n;

    vector<int> nums(n);

    cout<<"Enter sorted array: ";
    for(int &x:nums)
        cin>>x;

    cout<<"Enter target: ";
    cin>>target;

    Solution obj;
    vector<int> ans=obj.searchRange(nums,target);

    cout<<"Range: ["<<ans[0]<<", "<<ans[1]<<"]";

    return 0;
}