#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int minimumEffortPath(vector<vector<int>> &heights){
    int m=heights.size();
    int n=heights[0].size();

    vector<vector<int>> effort(m,vector<int>(n,1e9));

    priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;

    pq.push({0,0,0});
    effort[0][0]=0;

    int dr[]={-1,1,0,0};
    int dc[]={0,0,-1,1};

    while(!pq.empty()){
        auto curr=pq.top();
        pq.pop();

        int diff=curr[0];
        int row=curr[1];
        int col=curr[2];

        if(diff>effort[row][col])
            continue;

        if(row==m-1 && col==n-1)
            return diff;

        for(int i=0;i<4;i++){
            int nrow=row+dr[i];
            int ncol=col+dc[i];

            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n){

                int newEffort=max(
                    diff,
                    abs(heights[row][col]-heights[nrow][ncol])
                );

                if(newEffort<effort[nrow][ncol]){
                    effort[nrow][ncol]=newEffort;
                    pq.push({newEffort,nrow,ncol});
                }
            }
        }
    }

    return 0;
}

int main(){
    int m,n;

    cout<<"Enter rows and columns: ";
    cin>>m>>n;

    vector<vector<int>> heights(m,vector<int>(n));

    cout<<"Enter heights:\n";

    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            cin>>heights[i][j];

    cout<<"Minimum Effort Path = "
        <<minimumEffortPath(heights);

    return 0;
}