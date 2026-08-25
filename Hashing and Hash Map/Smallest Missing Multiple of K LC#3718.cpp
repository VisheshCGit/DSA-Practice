#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution{
public:
    int missingMultiple(vector<int> &nums,int k){
        unordered_set<int> st;

        for(int x:nums)
            st.insert(x);

        for(int i=1;;i++){
            int x=k*i;
            if(st.find(x)==st.end())
                return x;
        }
    }
};

int main(){
    int n,k;

    cout<<"Enter number of elements: ";
    cin>>n;

    vector<int> nums(n);

    cout<<"Enter array elements: ";
    for(int &x:nums)
        cin>>x;

    cout<<"Enter k: ";
    cin>>k;

    Solution obj;

    cout<<"Smallest Missing Multiple = "<<obj.missingMultiple(nums,k);

    return 0;
}