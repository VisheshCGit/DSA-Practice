#include <iostream>
#include <vector>
#include <stack>
#include <climits>
using namespace std;

bool find132Pattern(vector<int> &nums){
    stack<int> st;
    int second=INT_MIN; //stores the best possible '2' in the 132 pattern

    for(int i=nums.size()-1; i>=0; i--){

        if(nums[i]<second)
            return true; //found a valid '1'

        while(!st.empty() && st.top()<nums[i]){
            second=st.top(); //update the largest valid '2'
            st.pop();
        }

        st.push(nums[i]); //current element can act as a future '3'
    }

    return false;
}

int main(){
    int n;

    cout<<"Enter number of elements: ";
    cin>>n;

    vector<int> nums(n);

    cout<<"Enter array elements: ";
    for(int i=0; i<n; i++)
        cin>>nums[i];

    if(find132Pattern(nums))
        cout<<"132 Pattern Exists";
    else
        cout<<"132 Pattern Does Not Exist";

    return 0;
}