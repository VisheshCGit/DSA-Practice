#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
using namespace std;

class Solution{
public:

    // Returns the sum of three integers closest to the target
    int threeSumClosest(vector<int> &nums, int target){

        sort(nums.begin(), nums.end());

        int closestSum=INT_MAX;
        int minDistance=INT_MAX;

        for(int i=0;i<nums.size();i++){

            int left=i+1;
            int right=nums.size()-1;

            while(left<right){

                int sum=nums[i]+nums[left]+nums[right];

                int distance=abs(sum-target);

                if(distance==0)
                    return sum;

                if(distance<minDistance){

                    minDistance=distance;
                    closestSum=sum;
                }

                if(sum>target)
                    right--;
                else
                    left++;
            }
        }

        return closestSum;
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

    int target;

    cout<<"Enter target: ";
    cin>>target;

    cout<<"Closest Sum = "<<obj.threeSumClosest(nums,target);

    return 0;
}