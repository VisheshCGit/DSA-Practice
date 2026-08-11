#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution{
public:
    int missingInteger(vector<int> &nums){
        int sum=nums[0];
        unordered_set<int> st;

        st.insert(nums[0]);

        for(int i=1;i<nums.size();i++){
            if(nums[i]!=nums[i-1]+1){
                while(i<nums.size()){
                    st.insert(nums[i]);
                    i++;
                }
                break;
            }

            sum+=nums[i];
            st.insert(nums[i]);
        }

        while(st.find(sum)!=st.end())
            sum++;

        return sum;
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

    cout<<"Smallest Missing Integer = "<<obj.missingInteger(nums);

    return 0;
}