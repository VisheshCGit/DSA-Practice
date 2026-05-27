#include<iostream>
#include<vector>
using namespace std;

int removeDuplicates(vector<int>& nums){
    if(nums.size()==0)
        return 0;

    int k=1;
    int i=0;

    for(int j=1;j<nums.size();j++){
        if(nums[j]>nums[i]){
            nums[++i]=nums[j];
            k++;
        }
    }

    return k;
}

int main(){
    int n;

    cout<<"Please enter array length: ";
    cin>>n;

    vector<int> nums(n);

    cout<<"Please enter sorted array elements: ";
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    int k=removeDuplicates(nums);

    cout<<"Number of unique elements: "<<k<<endl;
    cout<<"Modified array: ";

    for(int i=0;i<k;i++){
        cout<<nums[i]<<" ";
    }

    return 0;
}