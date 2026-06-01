#include<iostream>
#include<vector>
using namespace std;

void permu(vector<int> &nums, vector<vector<int>> &ans, vector<int> &ds, vector<int> &freq, int n){
    if(ds.size()==n){
        ans.push_back(ds);
        return;
    }

    for(int i=0;i<n;i++){
        if(!freq[i]){
            ds.push_back(nums[i]);
            freq[i]=1;

            permu(nums, ans, ds, freq, n);

            ds.pop_back();
            freq[i]=0;
        }
    }
}

vector<vector<int>> permute(vector<int>& nums){
    vector<vector<int>> ans;
    int n=nums.size();

    vector<int> ds;
    vector<int> freq(n,0);

    permu(nums, ans, ds, freq, n);

    return ans;
}

int main(){
    int n;

    cout<<"Please enter array length: ";
    cin>>n;

    vector<int> nums(n);

    cout<<"Please enter array elements: ";
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    vector<vector<int>> result=permute(nums);

    cout<<"All possible permutations are:\n";

    for(int i=0;i<result.size();i++){
        cout<<"[ ";
        for(int j=0;j<result[i].size();j++){
            cout<<result[i][j]<<" ";
        }
        cout<<"]\n";
    }

    return 0;
}