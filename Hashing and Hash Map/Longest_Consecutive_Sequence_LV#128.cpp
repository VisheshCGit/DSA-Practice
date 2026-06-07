#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

int longestConsecutive(vector<int>& nums){

    if(nums.size()<=1)
        return nums.size();

    unordered_set<int> st;

    for(int num:nums)
        st.insert(num);

    int longest=1;

    for(int num:st){

        if(st.find(num-1)==st.end()){

            int currentNum=num;
            int count=1;

            while(st.find(currentNum+1)!=st.end()){
                currentNum++;
                count++;
            }

            longest=max(longest,count);
        }
    }

    return longest;
}

int main(){

    int n;

    cout<<"Please enter array length: ";
    cin>>n;

    vector<int> nums(n);

    cout<<"Please enter array elements: ";
    for(int i=0;i<n;i++)
        cin>>nums[i];

    cout<<"Length of longest consecutive sequence: "
        <<longestConsecutive(nums);

    return 0;
}