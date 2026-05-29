#include <iostream>
#include <vector>
using namespace std;
void merge(vector<int>& arr, int low, int mid, int high){
  int l=low, r=mid+1;
    vector<int> temp;
    while(l<=mid && r<=high){
        if(arr[l]<=arr[r]){
            temp.push_back(arr[l]);
            l++;
        }
        else{
            temp.push_back(arr[r]);
            r++;
        }
        while(l<=mid){
            temp.push_back(arr[l]);
            l++;
        }
        while(r<=high){
            temp.push_back(arr[r]);
            r++;
        }
        for(int i=low; i<=high; i++){
            arr[i]=temp[i-low];
        }
    }  
}
void mergeSort(vector<int>& arr, int low, int high){
    if(low>=high)
        return;
    int mid=low+(high-low)/2;
    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1,high);
    merge(arr,low,mid,high);
}
int main(){
    int n;

    cout<<"Please enter array length: ";
    cin>>n;

    vector<int> arr(n);

    cout<<"Please enter array elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    mergeSort(arr,0,n-1);

    cout<<"Sorted array: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}