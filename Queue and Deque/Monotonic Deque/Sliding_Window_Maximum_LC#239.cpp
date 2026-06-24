#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k){
    deque<int> dq; //stores indices in decreasing order of values
    vector<int> ans;
    int n=nums.size();

    for(int i=0; i<n; i++){
        while(!dq.empty() && dq.front()<=i-k) dq.pop_front(); //remove indices which are out of current window

        while(!dq.empty() && nums[dq.back()]<=nums[i]) dq.pop_back(); //remove smaller elements because they can never become maximum in future

        dq.push_back(i); //insert current index

        if(i>=k-1) ans.push_back(nums[dq.front()]); //front always stores maximum element of current window
    }

    return ans;
}

int main(){
    int n,k;

    cout<<"Enter size of array: ";
    cin>>n;

    vector<int> nums(n);

    cout<<"Enter array elements:\n";
    for(int i=0; i<n; i++)
        cin>>nums[i];

    cout<<"Enter window size: ";
    cin>>k;

    vector<int> ans=maxSlidingWindow(nums,k);

    cout<<"Maximum of every window:\n";
    for(auto x:ans)
        cout<<x<<" ";

    return 0;
}