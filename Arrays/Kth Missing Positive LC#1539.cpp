#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int findKthPositive(vector<int> &arr,int k){
        int low=0,high=arr.size()-1;

        while(low<=high){
            int mid=low+(high-low)/2;
            int missing=arr[mid]-(mid+1);

            if(missing<k)
                low=mid+1;
            else
                high=mid-1;
        }

        return low+k;
    }
};

int main(){

    int n,k;

    cout<<"Enter number of elements: ";
    cin>>n;

    vector<int> arr(n);

    cout<<"Enter sorted array: ";
    for(int &x:arr)
        cin>>x;

    cout<<"Enter k: ";
    cin>>k;

    Solution obj;

    cout<<"Kth Missing Positive Number = "<<obj.findKthPositive(arr,k);

    return 0;
}