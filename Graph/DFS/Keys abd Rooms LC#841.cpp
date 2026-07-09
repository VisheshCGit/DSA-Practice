#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &rooms, int room, vector<bool> &visited){
    if(visited[room]) return;

    visited[room]=true;    // Visit current room

    for(int neighbour : rooms[room])
        dfs(rooms, neighbour, visited);
}

bool canVisitAllRooms(vector<vector<int>> &rooms){
    int n=rooms.size();
    vector<bool> visited(n,false);

    dfs(rooms,0,visited);

    for(bool roomVisited : visited)
        if(!roomVisited)
            return false;

    return true;
}

int main(){
    int n;
    cout<<"Enter number of rooms: ";
    cin>>n;

    vector<vector<int>> rooms(n);

    cout<<"Enter number of keys followed by the room numbers:\n";

    for(int i=0;i<n;i++){
        int keys;
        cin>>keys;

        while(keys--){
            int room;
            cin>>room;
            rooms[i].push_back(room);
        }
    }

    cout<<(canVisitAllRooms(rooms) ? "true" : "false");

    return 0;
}