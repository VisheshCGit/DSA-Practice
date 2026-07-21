#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:

    // Rearranges the array such that positive and negative
    // numbers appear alternately while preserving their order.
    vector<int> rearrangeArray(vector<int>& nums){

        int n=nums.size();

        vector<int> ans(n);

        int pos=0;
        int neg=1;

        for(int i=0;i<n;i++){

            if(nums[i]>0){
                ans[pos]=nums[i];
                pos+=2;
            }
            else{
                ans[neg]=nums[i];
                neg+=2;
            }
        }

        return ans;
    }
};

int main(){

    Solution obj;

    vector<int> nums={3,1,-2,-5,2,-4};

    vector<int> ans=obj.rearrangeArray(nums);

    cout<<"Rearranged Array: ";

    for(int x:ans)
        cout<<x<<" ";

    return 0;
}