#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> distinctNumbers(vector<int> &nums, int k){
    unordered_map<int, int> mp;
    vector<int> ans;

    int left=0, right=0;

    while(right<nums.size()){
        mp[nums[right]]++;

        // Window of size k formed
        if(right-left+1==k){
            ans.push_back(mp.size());

            // Remove leftmost element before sliding
            if(mp[nums[left]]==1) mp.erase(nums[left]);
            else mp[nums[left]]--;

            left++;
        }

        right++;
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

    int k;
    cout<<"Enter window size: ";
    cin>>k;

    vector<int> ans=distinctNumbers(nums, k);

    cout<<"Distinct elements in each window: ";
    for(int x: ans)
        cout<<x<<" ";

    return 0;
}