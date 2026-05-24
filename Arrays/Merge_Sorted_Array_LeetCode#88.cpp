#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>& nums1,int m,vector<int>& nums2,int n){
    for(int i=m+n-1;i>=0;i--){
        if(m>0 && n>0){
            if(nums1[m-1]>nums2[n-1]){
                nums1[i]=nums1[m-1];
                m=m-1;
            }
            else{
                nums1[i]=nums2[n-1];
                n=n-1;
            }
        }
        else{
            if(n==0)
                break;
            nums1[i]=nums2[n-1];
            n=n-1;
        }
    }
}

int main(){
    int m,n;

    cout<<"Please enter number of valid elements in first array: ";
    cin>>m;

    cout<<"Please enter number of elements in second array: ";
    cin>>n;

    vector<int> nums1(m+n);
    vector<int> nums2(n);

    cout<<"Please enter valid elements of first sorted array: ";
    for(int i=0;i<m;i++){
        cin>>nums1[i];
    }

    cout<<"Please enter elements of second sorted array: ";
    for(int i=0;i<n;i++){
        cin>>nums2[i];
    }

    merge(nums1,m,nums2,n);

    cout<<"Merged sorted array stored in first array: ";
    for(int i=0;i<m+n;i++){
        cout<<nums1[i]<<" ";
    }

    return 0;
}