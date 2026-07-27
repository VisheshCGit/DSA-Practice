#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution{
public:
    int maxProduct(vector<int> &nums){
        int max1=INT_MIN,max2=INT_MIN;

        for(int x:nums){
            if(x>max1){
                max2=max1;
                max1=x;
            }
            else if(x>max2)
                max2=x;
        }

        return (max1-1)*(max2-1);
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

    cout<<"Maximum Product = "<<obj.maxProduct(nums);

    return 0;
}