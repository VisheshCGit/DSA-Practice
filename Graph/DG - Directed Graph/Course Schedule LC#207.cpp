#include <iostream>
#include <vector>

using namespace std;

bool dfs(int curr, vector<vector<int>> &adj, vector<int> &visited, vector<int> &pathVisited){
    visited[curr]=1;
    pathVisited[curr]=1;    // Current node is in recursion path

    for(int neighbour : adj[curr]){
        if(!visited[neighbour]){
            if(!dfs(neighbour, adj, visited, pathVisited))
                return false;
        }
        else if(pathVisited[neighbour])
            return false;    // Back edge found => Cycle
    }

    pathVisited[curr]=0;    // Backtracking

    return true;
}

bool canFinish(int numCourses, vector<vector<int>> &prerequisites){
    vector<vector<int>> adj(numCourses);

    for(auto &edge : prerequisites)
        adj[edge[1]].push_back(edge[0]);    // prerequisite -> course

    vector<int> visited(numCourses,0);
    vector<int> pathVisited(numCourses,0);

    for(int course=0;course<numCourses;course++)
        if(!visited[course])
            if(!dfs(course, adj, visited, pathVisited))
                return false;

    return true;
}

int main(){
    int numCourses,m;

    cout<<"Enter number of courses and prerequisites: ";
    cin>>numCourses>>m;

    vector<vector<int>> prerequisites;

    cout<<"Enter prerequisite pairs:\n";
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        prerequisites.push_back({u,v});
    }

    cout<<(canFinish(numCourses,prerequisites) ? "Possible" : "Not Possible");

    return 0;
}