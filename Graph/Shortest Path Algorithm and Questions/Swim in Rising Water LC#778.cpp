#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int swimInWater(vector<vector<int>> &grid){
    int n=grid.size();

    vector<vector<int>> dist(n,vector<int>(n,1e9));
    dist[0][0]=grid[0][0];

    priority_queue<
        pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>
    > pq;

    pq.push({grid[0][0],{0,0}});

    int dr[]={-1,1,0,0};
    int dc[]={0,0,-1,1};

    while(!pq.empty()){
        auto curr=pq.top();
        pq.pop();

        int time=curr.first;
        int row=curr.second.first;
        int col=curr.second.second;

        if(time>dist[row][col])
            continue;

        if(row==n-1 && col==n-1)
            return time;

        for(int i=0;i<4;i++){
            int nrow=row+dr[i];
            int ncol=col+dc[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<n){

                int newTime=max(time,grid[nrow][ncol]);

                if(newTime<dist[nrow][ncol]){
                    dist[nrow][ncol]=newTime;
                    pq.push({newTime,{nrow,ncol}});
                }
            }
        }
    }

    return -1;
}

int main(){
    int n;

    cout<<"Enter grid size: ";
    cin>>n;

    vector<vector<int>> grid(n,vector<int>(n));

    cout<<"Enter grid:\n";

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>grid[i][j];

    cout<<"Minimum Time = "<<swimInWater(grid);

    return 0;
}