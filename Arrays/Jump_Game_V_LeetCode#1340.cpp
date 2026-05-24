#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> jump;

int dfs(int index,vector<int>& arr,int d){
    if(jump[index]!=-1)
        return jump[index];

    jump[index]=1;

    for(int i=index-1;i>=0 && index-i<=d;i--){
        if(arr[i]<arr[index]){
            jump[i]=dfs(i,arr,d);
            jump[index]=max(jump[index],jump[i]+1);
        }
        else
            break;
    }

    for(int i=index+1;i<arr.size() && i-index<=d;i++){
        if(arr[i]<arr[index]){
            jump[i]=dfs(i,arr,d);
            jump[index]=max(jump[index],jump[i]+1);
        }
        else
            break;
    }

    return jump[index];
}

int maxJumps(vector<int>& arr,int d){
    int n=arr.size();
    jump=vector<int>(n,-1);

    for(int index=0;index<n;index++){
        jump[index]=dfs(index,arr,d);
    }

    int ans=jump[0];

    for(int i=1;i<n;i++){
        ans=max(ans,jump[i]);
    }

    return ans;
}

int main(){
    int n,d;

    cout<<"Please enter array length: ";
    cin>>n;

    vector<int> arr(n);

    cout<<"Please enter array elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<"Please enter maximum jump distance (d): ";
    cin>>d;

    int result=maxJumps(arr,d);

    cout<<"Maximum number of indices that can be visited: "<<result;

    return 0;
}