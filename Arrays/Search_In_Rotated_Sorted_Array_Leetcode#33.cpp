#include<iostream>
#include<vector>
using namespace std;

int search(vector<int>& arr,int target){
    int n=arr.size();
    int mid=(n-1)/2;
    int low=0,high=n-1;

    while(low<=high){
        if(arr[mid]==target)
            return mid;

        else if(arr[mid]>=arr[low]){
            if(target<arr[mid] && target>=arr[low])
                high=mid-1;
            else
                low=mid+1;
        }
        else{
            if(target>arr[mid] && target<=arr[high])
                low=mid+1;
            else
                high=mid-1;
        }

        mid=(low+high)/2;
    }

    return -1;
}

int main(){
    int n,target;

    cout<<"Please enter array length: ";
    cin>>n;

    vector<int> arr(n);

    cout<<"Please enter array elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<"Please enter target value: ";
    cin>>target;

    int result=search(arr,target);

    if(result!=-1)
        cout<<"Your target is present at index "<<result<<" in the provided array.";
    else
        cout<<"Your target is not present in the provided array.";

    return 0;
}