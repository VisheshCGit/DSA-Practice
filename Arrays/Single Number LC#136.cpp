#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int singleNumber(vector<int> &nums){
        int x=0;

        for(int y:nums)
            x^=y;

        return x;
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

    cout<<"Single Number = "<<obj.singleNumber(nums);

    return 0;
}