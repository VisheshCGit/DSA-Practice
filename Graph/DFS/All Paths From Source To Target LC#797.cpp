#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &graph, int node, vector<int> &path, vector<vector<int>> &paths){
    path.push_back(node);    // Include current node

    if(node==graph.size()-1){
        paths.push_back(path);    // Store one complete path
        path.pop_back();
        return;
    }

    for(int neighbour : graph[node])
        dfs(graph, neighbour, path, paths);

    path.pop_back();    // Backtrack for other paths
}

vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph){
    vector<vector<int>> paths;
    vector<int> path;

    dfs(graph,0,path,paths);

    return paths;
}

int main(){
    int n;
    cout<<"Enter number of nodes: ";
    cin>>n;

    vector<vector<int>> graph(n);

    cout<<"Enter number of neighbours followed by neighbour nodes:\n";

    for(int i=0;i<n;i++){
        int neighbours;
        cin>>neighbours;

        while(neighbours--){
            int node;
            cin>>node;
            graph[i].push_back(node);
        }
    }

    vector<vector<int>> paths=allPathsSourceTarget(graph);

    cout<<"All Paths:\n";

    for(auto &path : paths){
        for(int node : path)
            cout<<node<<" ";
        cout<<"\n";
    }

    return 0;
}