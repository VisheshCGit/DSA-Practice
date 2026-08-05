#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution{
public:
    vector<int> intersection(vector<int> &nums1,vector<int> &nums2){
        unordered_set<int> st;
        vector<int> ans;

        if(nums1.size()<=nums2.size()){

            for(int x:nums1)
                st.insert(x);

            for(int x:nums2){
                if(st.find(x)!=st.end()){
                    ans.push_back(x);
                    st.erase(x);
                }
            }
        }
        else{

            for(int x:nums2)
                st.insert(x);

            for(int x:nums1){
                if(st.find(x)!=st.end()){
                    ans.push_back(x);
                    st.erase(x);
                }
            }
        }

        return ans;
    }
};

int main(){

    int n,m;

    cout<<"Enter size of first array: ";
    cin>>n;

    vector<int> nums1(n);

    cout<<"Enter first array elements: ";

    for(int &x:nums1)
        cin>>x;

    cout<<"Enter size of second array: ";
    cin>>m;

    vector<int> nums2(m);

    cout<<"Enter second array elements: ";

    for(int &x:nums2)
        cin>>x;

    Solution obj;

    vector<int> ans=obj.intersection(nums1,nums2);

    cout<<"Intersection: ";

    for(int x:ans)
        cout<<x<<" ";

    return 0;
} 