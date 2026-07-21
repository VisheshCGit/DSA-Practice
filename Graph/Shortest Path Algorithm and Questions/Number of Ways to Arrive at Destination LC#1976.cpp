#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int countPaths(int n, vector<vector<int>> &roads){
    const int MOD=1e9+7;

    vector<vector<pair<int,int>>> adj(n);

    for(auto &road:roads){
        adj[road[0]].push_back({road[1],road[2]});
        adj[road[1]].push_back({road[0],road[2]});
    }

    vector<long long> dist(n,LLONG_MAX);
    vector<long long> ways(n,0);

    dist[0]=0;
    ways[0]=1;

    priority_queue<
        pair<long long,int>,
        vector<pair<long long,int>>,
        greater<pair<long long,int>>
    > pq;

    pq.push({0,0});

    while(!pq.empty()){
        auto curr=pq.top();
        pq.pop();

        long long dis=curr.first;
        int node=curr.second;

        if(dis>dist[node])
            continue;

        for(auto &it:adj[node]){
            int adjNode=it.first;
            int weight=it.second;

            if(dis+weight<dist[adjNode]){
                dist[adjNode]=dis+weight;
                ways[adjNode]=ways[node];
                pq.push({dist[adjNode],adjNode});
            }
            else if(dis+weight==dist[adjNode]){
                ways[adjNode]=(ways[adjNode]+ways[node])%MOD;
            }
        }
    }

    return ways[n-1];
}

int main(){
    int n,m;

    cout<<"Enter number of intersections: ";
    cin>>n;

    cout<<"Enter number of roads: ";
    cin>>m;

    vector<vector<int>> roads(m,vector<int>(3));

    cout<<"Enter roads (u v time):\n";
    for(int i=0;i<m;i++)
        cin>>roads[i][0]>>roads[i][1]>>roads[i][2];

    cout<<"Number of Shortest Paths = "
        <<countPaths(n,roads);

    return 0;
}