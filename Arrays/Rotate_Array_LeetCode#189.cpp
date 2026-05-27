#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void rotateArray(vector<int>& nums,int k){
    int n=nums.size();

    k=k%n;

    reverse(nums.begin(),nums.end());
    reverse(nums.begin(),nums.begin()+k);
    reverse(nums.begin()+k,nums.end());
}

int main(){
    int n,k;

    cout<<"Please enter array length: ";
    cin>>n;

    vector<int> nums(n);

    cout<<"Please enter array elements: ";
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    cout<<"Please enter number of right rotations: ";
    cin>>k;

    rotateArray(nums,k);

    cout<<"Array after rotation: ";
    for(int i=0;i<n;i++){
        cout<<nums[i]<<" ";
    }

    return 0;
}