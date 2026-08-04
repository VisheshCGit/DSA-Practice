#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
    vector<int> findMissingElements(vector<int> &nums){
        sort(nums.begin(),nums.end());

        vector<int> ans;

        for(int i=0;i<nums.size()-1;i++){
            int curr=nums[i]+1;

            while(curr<nums[i+1]){
                ans.push_back(curr);
                curr++;
            }
        }

        return ans;
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

    vector<int> ans=obj.findMissingElements(nums);

    if(ans.empty()){
        cout<<"No Missing Elements";
    }
    else{
        cout<<"Missing Elements: ";

        for(int x:ans)
            cout<<x<<" ";
    }

    return 0;
}