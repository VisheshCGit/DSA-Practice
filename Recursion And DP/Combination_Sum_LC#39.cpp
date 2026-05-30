#include<iostream>
#include<vector>
using namespace std;

void findCombination(int index, vector<vector<int>> &ans, vector<int> &ds, int target, vector<int>& candidates, int n){
    if(index==n){
        if(target==0)
            ans.push_back(ds);
        return;
    }

    if(target>=candidates[index]){
        ds.push_back(candidates[index]);
        findCombination(index, ans, ds, target-candidates[index], candidates, n);
        ds.pop_back();
    }

    findCombination(index+1, ans, ds, target, candidates, n);
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target){
    vector<vector<int>> ans;
    vector<int> ds;

    findCombination(0, ans, ds, target, candidates, candidates.size());

    return ans;
}

int main(){
    int n,target;

    cout<<"Please enter array length: ";
    cin>>n;

    vector<int> candidates(n);

    cout<<"Please enter array elements: ";
    for(int i=0;i<n;i++){
        cin>>candidates[i];
    }

    cout<<"Please enter target value: ";
    cin>>target;

    vector<vector<int>> result=combinationSum(candidates,target);

    cout<<"Possible combinations are:\n";

    if(result.size()==0){
        cout<<"No valid combination found.";
        return 0;
    }

    for(int i=0;i<result.size();i++){
        cout<<"[ ";
        for(int j=0;j<result[i].size();j++){
            cout<<result[i][j]<<" ";
        }
        cout<<"]\n";
    }

    return 0;
}