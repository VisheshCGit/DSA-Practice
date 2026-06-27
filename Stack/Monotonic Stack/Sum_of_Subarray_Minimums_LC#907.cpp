#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int sumSubarrayMins(vector<int> &arr){
    const int MOD=1000000007;

    int n=arr.size();
    stack<int> st;
    vector<int> nse(n),pse(n);

    for(int i=n-1;i>=0;i--){
        while(!st.empty() && arr[st.top()]>arr[i])
            st.pop();

        if(st.empty())
            nse[i]=n;
        else
            nse[i]=st.top();

        st.push(i);
    }

    while(!st.empty())
        st.pop();

    for(int i=0;i<n;i++){
        while(!st.empty() && arr[st.top()]>=arr[i])
            st.pop();

        if(st.empty())
            pse[i]=-1;
        else
            pse[i]=st.top();

        st.push(i);
    }

    long long ans=0;

    for(int i=0;i<n;i++){
        long long left=i-pse[i]; //number of choices for starting index
        long long right=nse[i]-i; //number of choices for ending index
        long long contribution=(left*right)%MOD; //total subarrays where arr[i] is the minimum

        ans=(ans+(contribution*arr[i])%MOD)%MOD; //add contribution of current element
    }

    return (int)ans;
}

int main(){
    int n;

    cout<<"Enter number of elements: ";
    cin>>n;

    vector<int> arr(n);

    cout<<"Enter array elements: ";
    for(int i=0;i<n;i++)
        cin>>arr[i];

    cout<<"Sum of Subarray Minimums: "<<sumSubarrayMins(arr);

    return 0;
}