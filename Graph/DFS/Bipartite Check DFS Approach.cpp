#include <iostream>
#include <vector>

using namespace std;

bool dfs(vector<vector<int>> &graph, vector<int> &color, int curr, int currentColor){
    color[curr]=currentColor;    // Color current node

    for(int neighbour : graph[curr]){
        if(color[neighbour]==-1){
            if(!dfs(graph,color,neighbour,1-currentColor))
                return false;
        }
        else if(color[neighbour]==currentColor)
            return false;    // Same colored neighbours found
    }

    return true;
}

bool isBipartite(vector<vector<int>> &graph){
    int n=graph.size();

    vector<int> color(n,-1);

    for(int node=0;node<n;node++)
        if(color[node]==-1)
            if(!dfs(graph,color,node,0))
                return false;

    return true;
}

int main(){
    int n;

    cout<<"Enter number of vertices: ";
    cin>>n;

    vector<vector<int>> graph(n);

    cout<<"Enter number of neighbours for each vertex followed by the neighbours:\n";

    for(int i=0;i<n;i++){
        int degree;
        cin>>degree;

        while(degree--){
            int neighbour;
            cin>>neighbour;
            graph[i].push_back(neighbour);
        }
    }

    cout<<(isBipartite(graph) ? "Graph is Bipartite" : "Graph is Not Bipartite");

    return 0;
}