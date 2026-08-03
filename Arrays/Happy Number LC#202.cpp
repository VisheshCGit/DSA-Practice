#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution{
public:
    bool containsDuplicate(vector<int> &nums){
        unordered_set<int> st;

        for(int x:nums){
            if(st.find(x)!=st.end())
                return true;

            st.insert(x);
        }

        return false;
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

    if(obj.containsDuplicate(nums))
        cout<<"True";
    else
        cout<<"False";

    return 0;
}