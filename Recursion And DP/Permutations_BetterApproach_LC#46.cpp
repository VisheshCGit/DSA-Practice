#include<iostream>
#include<vector>
using namespace std;

void permu(int index, vector<int> &nums, vector<vector<int>> &ans, int n){
    if(index==n){
        ans.push_back(nums);
        return;
    }

    for(int i=index;i<n;i++){
        swap(nums[index], nums[i]);

        permu(index+1, nums, ans, n);

        swap(nums[index], nums[i]);
    }
}

vector<vector<int>> permute(vector<int>& nums){
    vector<vector<int>> ans;
    int n=nums.size();

    permu(0, nums, ans, n);

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