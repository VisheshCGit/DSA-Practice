#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution{
public:
    vector<int> intersect(vector<int> &nums1,vector<int> &nums2){
        unordered_map<int,int> mp;
        vector<int> ans;

        for(int x:nums1)
            mp[x]++;

        for(int x:nums2){
            if(mp[x]>0){
                ans.push_back(x);
                mp[x]--;
            }
        }

        return ans;
    }
};

int main(){
    int m,n;

    cout<<"Enter size of first array: ";
    cin>>m;

    vector<int> nums1(m);
    cout<<"Enter first array: ";
    for(int &x:nums1)
        cin>>x;

    cout<<"Enter size of second array: ";
    cin>>n;

    vector<int> nums2(n);
    cout<<"Enter second array: ";
    for(int &x:nums2)
        cin>>x;

    Solution obj;
    vector<int> ans=obj.intersect(nums1,nums2);

    cout<<"Intersection: ";
    for(int x:ans)
        cout<<x<<" ";

    return 0;
}