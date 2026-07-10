#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> updateMatrix(vector<vector<int>> &mat){
    int m=mat.size(), n=mat[0].size();

    vector<vector<int>> ans(m, vector<int>(n,-1));
    queue<pair<int,int>> q;

    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            if(mat[i][j]==0){
                ans[i][j]=0;    // Distance of every 0 is already known
                q.emplace(i,j);
            }

    int dr[]={-1,1,0,0};
    int dc[]={0,0,-1,1};

    while(!q.empty()){
        auto curr=q.front();
        q.pop();

        int row=curr.first;
        int col=curr.second;

        for(int i=0;i<4;i++){
            int newRow=row+dr[i];
            int newCol=col+dc[i];

            if(newRow>=0 && newRow<m && newCol>=0 && newCol<n &&
               ans[newRow][newCol]==-1 && mat[newRow][newCol]==1){
                ans[newRow][newCol]=ans[row][col]+1;    // First time reached => shortest distance
                q.emplace(newRow,newCol);
            }
        }
    }

    return ans;
}

int main(){
    int m,n;

    cout<<"Enter rows and columns: ";
    cin>>m>>n;

    vector<vector<int>> mat(m, vector<int>(n));

    cout<<"Enter matrix:\n";
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            cin>>mat[i][j];

    vector<vector<int>> ans=updateMatrix(mat);

    cout<<"Distance Matrix:\n";
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
            cout<<ans[i][j]<<" ";
        cout<<"\n";
    }

    return 0;
}