#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool bfs(vector<vector<int>> &graph, vector<int> &color, int start){
    queue<int> q;

    color[start]=0;    // Start with first color
    q.push(start);

    while(!q.empty()){
        int curr=q.front();
        q.pop();

        for(int neighbour : graph[curr]){
            if(color[neighbour]==-1){
                color[neighbour]=1-color[curr];    // Assign opposite color
                q.push(neighbour);
            }
            else if(color[neighbour]==color[curr])
                return false;    // Same colored neighbours found
        }
    }

    return true;
}

bool isBipartite(vector<vector<int>> &graph){
    int n=graph.size();

    vector<int> color(n,-1);

    for(int node=0;node<n;node++)
        if(color[node]==-1)
            if(!bfs(graph,color,node))
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