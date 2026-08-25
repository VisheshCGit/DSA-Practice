#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

class Solution{
public:
    int firstMissingPositive(vector<int> &nums){
        int n=nums.size();

        for(int i=0;i<n;i++){
            if(nums[i]<=0 || nums[i]>n)
                nums[i]=n+1;
        }

        for(int i=0;i<n;i++){
            int x=abs(nums[i]);

            if(x<=n && nums[x-1]>0)
                nums[x-1]*=-1;
        }

        for(int i=0;i<n;i++){
            if(nums[i]>0)
                return i+1;
        }

        return n+1;
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

    Solution obj;

    cout<<"First Missing Positive = "<<obj.firstMissingPositive(nums);

    return 0;
}