#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &graph, int city, vector<bool> &visited){
    visited[city]=true;    // Visit current city

    for(int neighbour=0;neighbour<graph.size();neighbour++)
        if(graph[city][neighbour] && !visited[neighbour])
            dfs(graph, neighbour, visited);
}

int findCircleNum(vector<vector<int>> &graph){
    int n=graph.size();
    int provinces=0;

    vector<bool> visited(n,false);

    for(int city=0;city<n;city++)
        if(!visited[city]){
            provinces++;    // New DFS means new province
            dfs(graph, city, visited);
        }

    return provinces;
}

int main(){
    int n;
    cout<<"Enter number of cities: ";
    cin>>n;

    vector<vector<int>> graph(n, vector<int>(n));

    cout<<"Enter adjacency matrix:\n";

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>graph[i][j];

    cout<<"Number of Provinces = "<<findCircleNum(graph);

    return 0;
}