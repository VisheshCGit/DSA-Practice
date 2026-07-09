#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &adj, int curr, int destination, vector<bool> &visited, bool &found){
    if(visited[curr] || found) return;

    visited[curr]=true;    // Visit current node only once

    if(curr==destination){
        found=true;    // Destination reached
        return;
    }

    for(int neighbour : adj[curr])
        dfs(adj, neighbour, destination, visited, found);
}

bool validPath(int n, vector<vector<int>> &edges, int source, int destination){
    vector<vector<int>> adj(n);
    vector<bool> visited(n,false);

    for(auto &edge : edges){
        int u=edge[0];
        int v=edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);    // Undirected graph
    }

    bool found=false;
    dfs(adj, source, destination, visited, found);

    return found;
}

int main(){
    int n,m;

    cout<<"Enter number of vertices and edges: ";
    cin>>n>>m;

    vector<vector<int>> edges;

    cout<<"Enter edges:\n";
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        edges.push_back({u,v});
    }

    int source,destination;
    cout<<"Enter source and destination: ";
    cin>>source>>destination;

    cout<<(validPath(n,edges,source,destination) ? "Path Exists" : "Path Doesn't Exist");

    return 0;
}