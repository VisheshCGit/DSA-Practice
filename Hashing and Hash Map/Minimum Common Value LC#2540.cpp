#include <iostream>
#include <vector>
#include <unordered_set>
#include <climits>
using namespace std;

class Solution{
public:
    int getCommon(vector<int> &nums1,vector<int> &nums2){
        unordered_set<int> st;
        int ans=INT_MAX;

        for(int x:nums1)
            st.insert(x);

        for(int x:nums2){
            if(st.find(x)!=st.end())
                ans=min(ans,x);
        }

        if(ans==INT_MAX)
            return -1;

        return ans;
    }
};

int main(){
    int n,m;

    cout<<"Enter size of first array: ";
    cin>>n;

    vector<int> nums1(n);
    cout<<"Enter first sorted array: ";
    for(int &x:nums1)
        cin>>x;

    cout<<"Enter size of second array: ";
    cin>>m;

    vector<int> nums2(m);
    cout<<"Enter second sorted array: ";
    for(int &x:nums2)
        cin>>x;

    Solution obj;

    cout<<"Minimum Common Value = "<<obj.getCommon(nums1,nums2);

    return 0;
}