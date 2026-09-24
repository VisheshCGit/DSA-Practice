#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int smallestIndex(vector<int> &nums){
        for(int i=0;i<nums.size();i++){
            int sum=0,x=nums[i];

            while(x>0){
                sum+=x%10;
                x/=10;
            }

            if(sum==i)
                return i;
        }

        return -1;
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

    cout<<"Smallest Index = "<<obj.smallestIndex(nums);

    return 0;
}