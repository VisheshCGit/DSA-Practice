#include <iostream>
#include <vector>

using namespace std;

bool dfs(vector<int> &color, vector<vector<int>> &adj, int curr, int currentColor){
    color[curr]=currentColor;    // Assign color to current node

    for(int neighbour : adj[curr]){
        if(color[neighbour]==-1){
            if(!dfs(color, adj, neighbour, 1-currentColor))
                return false;
        }
        else if(color[neighbour]==currentColor)
            return false;    // Adjacent nodes have same color
    }

    return true;
}

bool possibleBipartition(int n, vector<vector<int>> &dislikes){
    vector<vector<int>> adj(n+1);

    for(auto &edge : dislikes){
        int u=edge[0];
        int v=edge[1];

        adj[u].push_back(v);
        adj[v].push_back(u);    // Undirected graph
    }

    vector<int> color(n+1,-1);

    for(int person=1;person<=n;person++)
        if(color[person]==-1)
            if(!dfs(color, adj, person, 0))
                return false;

    return true;
}

int main(){
    int n,m;

    cout<<"Enter number of people and dislikes: ";
    cin>>n>>m;

    vector<vector<int>> dislikes;

    cout<<"Enter dislike pairs:\n";
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        dislikes.push_back({u,v});
    }

    cout<<(possibleBipartition(n,dislikes) ? "Possible" : "Not Possible");

    return 0;
}