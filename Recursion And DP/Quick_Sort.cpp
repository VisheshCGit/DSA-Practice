#include <iostream>
#include <vector>
using namespace std;
int findp(vector<int> &arr, int low, int high){
    int pivot=arr[low];
    int i=low, j=high;
    while(i<j){
        while(arr[i]<=pivot&& i<=high-1)
            i++;
        while(arr[j]>pivot && j>=low+1)
        j--;
            if(i<j)
        swap(arr[i],arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}
void quicksort(vector<int> &arr, int low, int high){
    if(low>=high)
    return;
    int partition=findp(arr,low,high);
    quicksort(arr, partition+1, high);
    quicksort(arr,low,partition-1);
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

    quicksort(arr,0,n-1);

    cout<<"Sorted array: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}