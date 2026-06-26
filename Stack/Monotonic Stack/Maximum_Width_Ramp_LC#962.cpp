#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int maxWidthRamp(vector<int> &nums){
    stack<int> st;

    for(int i=0; i<nums.size(); i++){
        if(st.empty() || nums[i]<nums[st.top()])
            st.push(i); //store only indices having strictly decreasing values
    }

    int ans=0;

    for(int j=nums.size()-1; j>=0; j--){
        while(!st.empty() && nums[j]>=nums[st.top()]){
            ans=max(ans,j-st.top()); //calculate width using current right endpoint
            st.pop(); //this index cannot produce a better answer in future
        }
    }

    return ans;
}

int main(){
    int n;

    cout<<"Enter number of elements: ";
    cin>>n;

    vector<int> nums(n);

    cout<<"Enter array elements: ";
    for(int i=0; i<n; i++)
        cin>>nums[i];

    cout<<"Maximum Width Ramp: "<<maxWidthRamp(nums);

    return 0;
}