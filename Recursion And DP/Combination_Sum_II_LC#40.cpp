#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void findCombination(int index, vector<vector<int>> &ans, vector<int> &ds, int target, vector<int>& candidates, int n){
    if(target==0){
        ans.push_back(ds);
        return;
    }

    for(int i=index;i<n;i++){
        if(i>index && candidates[i]==candidates[i-1])
            continue;

        if(candidates[i]>target)
            break;

        ds.push_back(candidates[i]);
        findCombination(i+1, ans, ds, target-candidates[i], candidates, n);
        ds.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target){
    vector<vector<int>> ans;
    vector<int> ds;

    sort(candidates.begin(), candidates.end());

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

    vector<vector<int>> result=combinationSum2(candidates,target);

    cout<<"Possible unique combinations are:\n";

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