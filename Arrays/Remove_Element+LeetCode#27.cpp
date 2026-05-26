#include<iostream>
#include<vector>
using namespace std;

int removeElement(vector<int>& nums,int val){
    int k=0;
    int j=nums.size()-1;

    for(int i=0;i<=j;i++){
        if(nums[i]!=val){
            k++;
            continue;
        }
        else{
            if(nums[j]==val && j>i){
                j--;
                i--;
            }
            else{
                k++;
                swap(nums[i],nums[j]);
                j--;
            }
        }
    }

    return k;
}

int main(){
    int n,val;

    cout<<"Please enter array length: ";
    cin>>n;

    vector<int> nums(n);

    cout<<"Please enter array elements: ";
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    cout<<"Please enter the value to remove: ";
    cin>>val;

    int k=removeElement(nums,val);

    cout<<"Number of elements not equal to "<<val<<" is: "<<k<<endl;
    cout<<"Modified array: ";

    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<" ";
    }

    return 0;
}