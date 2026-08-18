#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution{
public:
    int firstUniqueEven(vector<int> &nums){
        unordered_map<int,int> mp;

        for(int x:nums)
            mp[x]++;

        for(int x:nums){
            if(x%2==0 && mp[x]==1)
                return x;
        }

        return -1;
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

    cout<<"First Unique Even = "<<obj.firstUniqueEven(nums);

    return 0;
}