#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Fleet{
    int position;
    double time;
};

bool cmp(const Fleet &a,const Fleet &b){
    return a.position>b.position; //sort cars from nearest to target to farthest
}

int carFleet(int target,vector<int> &position,vector<int> &speed){
    int n=position.size();
    if(n==0) return 0;

    vector<Fleet> cars(n);

    for(int i=0;i<n;i++){
        cars[i].position=position[i];
        cars[i].time=(double)(target-position[i])/speed[i]; //time required to reach target
    }

    sort(cars.begin(),cars.end(),cmp);

    int fleets=1;
    double fleetTime=cars[0].time; //arrival time of the current fleet

    for(int i=1;i<n;i++){

        if(cars[i].time<=fleetTime)
            continue; //this car catches the current fleet before reaching target

        fleets++; //cannot catch the current fleet, so it forms a new fleet
        fleetTime=cars[i].time; //update arrival time of the newly formed fleet
    }

    return fleets;
}

int main(){
    int target,n;

    cout<<"Enter target distance: ";
    cin>>target;

    cout<<"Enter number of cars: ";
    cin>>n;

    vector<int> position(n),speed(n);

    cout<<"Enter positions: ";
    for(int i=0;i<n;i++)
        cin>>position[i];

    cout<<"Enter speeds: ";
    for(int i=0;i<n;i++)
        cin>>speed[i];

    cout<<"Total Fleets: "<<carFleet(target,position,speed);

    return 0;
}