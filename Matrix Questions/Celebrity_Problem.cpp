#include <iostream>
#include <vector>
using namespace std;

int celebrity(vector<vector<int>> &M){
    int n=M.size();

    int candidate=0;

    for(int i=1; i<n; i++){
        if(M[candidate][i]==1)
            candidate=i; //candidate knows i, so candidate cannot be celebrity
    }

    for(int i=0; i<n; i++){
        if(i==candidate)
            continue;

        if(M[candidate][i]==1 || M[i][candidate]==0)
            return -1; //celebrity should know nobody and everybody should know celebrity
    }

    return candidate;
}

int main(){
    int n;

    cout<<"Enter number of people: ";
    cin>>n;

    vector<vector<int>> M(n, vector<int>(n));

    cout<<"Enter acquaintance matrix:\n";

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin>>M[i][j];

    int ans=celebrity(M);

    if(ans==-1)
        cout<<"No Celebrity Found";
    else
        cout<<"Celebrity Index: "<<ans;

    return 0;
}