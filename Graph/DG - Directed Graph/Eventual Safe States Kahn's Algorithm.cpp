#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> eventualSafeNodes(vector<vector<int>> &graph){
    int n=graph.size();

    vector<vector<int>> reverseGraph(n);
    vector<int> indegree(n,0);

    // Reverse the graph
    for(int node=0;node<n;node++)
        for(int neighbour : graph[node])
            reverseGraph[neighbour].push_back(node);

    // Reverse graph indegree = Original graph outdegree
    for(int node=0;node<n;node++)
        indegree[node]=graph[node].size();

    queue<int> q;

    // Original terminal nodes
    for(int node=0;node<n;node++)
        if(indegree[node]==0)
            q.push(node);

    vector<int> safeNodes;

    while(!q.empty()){
        int curr=q.front();
        q.pop();

        safeNodes.push_back(curr);

        for(int neighbour : reverseGraph[curr]){
            indegree[neighbour]--;

            if(indegree[neighbour]==0)
                q.push(neighbour);
        }
    }

    sort(safeNodes.begin(), safeNodes.end());

    return safeNodes;
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

    vector<int> ans=eventualSafeNodes(graph);

    cout<<"Safe Nodes:\n";
    for(int node : ans)
        cout<<node<<" ";

    return 0;
}