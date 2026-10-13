#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        vector<long long> squares;

        for(auto x:nums){
            long long val=x;
            squares.push_back(val*val);
        }

        sort(squares.begin(),squares.end());

        long long ans=0;
        int border=n/2;

        for(int i=0; i<n; i++){
            if(i>=border) ans+=squares[i];
            else ans-=squares[i];
        }

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

    cout<<"Maximum Alternating Sum = "<<obj.maxAlternatingSum(nums);

    return 0;
}