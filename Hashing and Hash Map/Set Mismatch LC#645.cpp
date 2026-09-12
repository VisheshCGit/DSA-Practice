#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution{
public:
    vector<int> findErrorNums(vector<int> &nums){
        int n=nums.size();
        unordered_set<int> st;
        int duplicate=0,summ=0;

        for(auto x:nums){
            if(st.find(x)!=st.end())
                duplicate=x;

            st.insert(x);
            summ+=x;
        }

        int sum=(n*(n+1))/2;
        int missing=sum-(summ-duplicate);

        return {duplicate,missing};
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

    vector<int> ans=obj.findErrorNums(nums);

    cout<<"Duplicate = "<<ans[0]<<endl;
    cout<<"Missing = "<<ans[1]<<endl;

    return 0;
}