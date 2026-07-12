#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites){
    vector<vector<int>> adj(numCourses);
    vector<int> indegree(numCourses,0);

    for(auto &edge : prerequisites){
        adj[edge[1]].push_back(edge[0]);    // prerequisite -> course
        indegree[edge[0]]++;                // Incoming dependency
    }

    queue<int> q;

    for(int course=0;course<numCourses;course++)
        if(indegree[course]==0)
            q.push(course);

    vector<int> order;

    while(!q.empty()){
        int curr=q.front();
        q.pop();

        order.push_back(curr);

        for(int neighbour : adj[curr]){
            indegree[neighbour]--;

            if(indegree[neighbour]==0)
                q.push(neighbour);
        }
    }

    if(order.size()!=numCourses)
        return {};

    return order;
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

    vector<int> order=findOrder(numCourses,prerequisites);

    if(order.empty()){
        cout<<"No Valid Order";
        return 0;
    }

    cout<<"Course Order:\n";
    for(int course : order)
        cout<<course<<" ";

    return 0;
}