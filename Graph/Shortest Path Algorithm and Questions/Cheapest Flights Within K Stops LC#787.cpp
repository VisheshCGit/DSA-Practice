#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k){
    vector<vector<pair<int,int>>> adj(n);

    for(auto &flight:flights)
        adj[flight[0]].push_back({flight[1],flight[2]});

    vector<int> cost(n,1e9);
    cost[src]=0;

    queue<vector<int>> q;
    q.push({0,src,0});   // {stops,node,cost}

    while(!q.empty()){
        auto curr=q.front();
        q.pop();

        int stops=curr[0];
        int node=curr[1];
        int currCost=curr[2];

        if(stops>k)
            continue;

        for(auto &it:adj[node]){
            int adjNode=it.first;
            int weight=it.second;

            if(currCost+weight<cost[adjNode] && stops<=k){
                cost[adjNode]=currCost+weight;
                q.push({stops+1,adjNode,currCost+weight});
            }
        }
    }

    return cost[dst]==1e9 ? -1 : cost[dst];
}

int main(){
    int n,m;

    cout<<"Enter number of cities: ";
    cin>>n;

    cout<<"Enter number of flights: ";
    cin>>m;

    vector<vector<int>> flights(m,vector<int>(3));

    cout<<"Enter flights (from to price):\n";
    for(int i=0;i<m;i++)
        cin>>flights[i][0]>>flights[i][1]>>flights[i][2];

    int src,dst,k;

    cout<<"Enter source, destination and maximum stops: ";
    cin>>src>>dst>>k;

    cout<<"Cheapest Price = "
        <<findCheapestPrice(n,flights,src,dst,k);

    return 0;
}