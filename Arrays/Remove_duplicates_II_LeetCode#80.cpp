#include<iostream>
#include<vector>
using namespace std;

int removeDuplicates(vector<int>& nums){
    if(nums.size()<=2)
        return nums.size();

    int k=2;

    for(int j=2;j<nums.size();j++){
        if(nums[j]!=nums[k-2]){
            nums[k]=nums[j];
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

    cout<<"Number of valid elements after removing extra duplicates: "<<k<<endl;
    cout<<"Modified array: ";

    for(int i=0;i<k;i++){
        cout<<nums[i]<<" ";
    }

    return 0;
}