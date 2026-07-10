#include <iostream>
#include <vector>

using namespace std;

bool dfs(vector<vector<int>> &adj, vector<bool> &visited, int curr, int destination){
    if(curr==destination)
        return true;

    visited[curr]=true;    // Mark current node visited

    for(int neighbour : adj[curr])
        if(!visited[neighbour] && dfs(adj, visited, neighbour, destination))
            return true;    // Destination found

    return false;
}

vector<int> findRedundantConnection(vector<vector<int>> &edges){
    int n=edges.size();
    vector<vector<int>> adj(n+1);

    for(auto &edge : edges){
        int u=edge[0];
        int v=edge[1];

        vector<bool> visited(n+1,false);

        if(dfs(adj, visited, u, v))    // Check connectivity before adding edge
            return edge;

        adj[u].push_back(v);
        adj[v].push_back(u);    // Add edge if no cycle is formed
    }

    return {};
}

int main(){
    int m;

    cout<<"Enter number of edges: ";
    cin>>m;

    vector<vector<int>> edges(m, vector<int>(2));

    cout<<"Enter edges:\n";
    for(int i=0;i<m;i++)
        cin>>edges[i][0]>>edges[i][1];

    vector<int> ans=findRedundantConnection(edges);

    cout<<"Redundant Edge = "<<ans[0]<<" "<<ans[1];

    return 0;
}