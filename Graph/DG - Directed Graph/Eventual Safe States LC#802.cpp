#include <iostream>
#include <vector>

using namespace std;

bool dfs(vector<vector<int>> &graph, vector<int> &visited, vector<int> &pathVisited,
         vector<int> &safe, int curr){
    visited[curr]=1;
    pathVisited[curr]=1;    // Current node is part of current DFS path

    for(int neighbour : graph[curr]){
        if(!visited[neighbour]){
            if(dfs(graph, visited, pathVisited, safe, neighbour))
                return true;    // Cycle found in current path
        }
        else if(pathVisited[neighbour])
            return true;    // Back edge found => Cycle
    }

    safe[curr]=1;    // No cycle reachable from current node
    pathVisited[curr]=0;    // Backtracking

    return false;
}

vector<int> eventualSafeNodes(vector<vector<int>> &graph){
    int n=graph.size();

    vector<int> visited(n,0);
    vector<int> pathVisited(n,0);
    vector<int> safe(n,0);

    for(int node=0;node<n;node++)
        if(!visited[node])
            dfs(graph, visited, pathVisited, safe, node);

    vector<int> ans;

    for(int node=0;node<n;node++)
        if(safe[node])
            ans.push_back(node);

    return ans;
}

int main(){
    int n;

    cout<<"Enter number of vertices: ";
    cin>>n;

    vector<vector<int>> graph(n);

    cout<<"Enter number of neighbours followed by neighbours for each vertex:\n";

    for(int i=0;i<n;i++){
        int degree;
        cin>>degree;

        while(degree--){
            int neighbour;
            cin>>neighbour;
            graph[i].push_back(neighbour);
        }
    }

    vector<int> safeNodes=eventualSafeNodes(graph);

    cout<<"Safe Nodes:\n";
    for(int node : safeNodes)
        cout<<node<<" ";

    return 0;
}