#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int networkDelayTime(vector<vector<int>> &times, int n, int k){
    vector<vector<pair<int,int>>> adj(n+1);

    for(auto &edge:times)
        adj[edge[0]].push_back({edge[1],edge[2]});

    vector<int> dist(n+1,1e9);
    dist[k]=0;

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,k});

    while(!pq.empty()){
        auto curr=pq.top();
        pq.pop();

        int dis=curr.first;
        int node=curr.second;

        if(dis>dist[node])   // Ignore stale entries
            continue;

        for(auto &it:adj[node]){
            int adjNode=it.first;
            int edgeWeight=it.second;

            if(dis+edgeWeight<dist[adjNode]){
                dist[adjNode]=dis+edgeWeight;
                pq.push({dist[adjNode],adjNode});
            }
        }
    }

    int ans=0;

    for(int i=1;i<=n;i++)
        ans=max(ans,dist[i]);

    return ans==1e9 ? -1 : ans;
}

int main(){
    int n,m,k;

    cout<<"Enter number of nodes: ";
    cin>>n;

    cout<<"Enter number of edges: ";
    cin>>m;

    vector<vector<int>> times(m,vector<int>(3));

    cout<<"Enter edges (u v w):\n";
    for(int i=0;i<m;i++)
        cin>>times[i][0]>>times[i][1]>>times[i][2];

    cout<<"Enter source node: ";
    cin>>k;

    cout<<"Minimum Time to Reach All Nodes: "
        <<networkDelayTime(times,n,k);

    return 0;
}