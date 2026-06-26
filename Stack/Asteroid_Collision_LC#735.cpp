#include <iostream>
#include <vector>
using namespace std;

vector<int> asteroidCollision(vector<int> &asteroids){
    vector<int> st; //use vector as stack

    for(int asteroid : asteroids){

        while(!st.empty() && st.back()>0 && asteroid<0 && abs(st.back())<abs(asteroid))
            st.pop_back(); //smaller positive asteroid explodes

        if(!st.empty() && st.back()>0 && asteroid<0){

            if(abs(st.back())==abs(asteroid))
                st.pop_back(); //both asteroids explode

            continue; //current asteroid also gets destroyed
        }

        st.push_back(asteroid); //no collision or current asteroid survives
    }

    return st;
}

int main(){
    int n;

    cout<<"Enter number of asteroids: ";
    cin>>n;

    vector<int> asteroids(n);

    cout<<"Enter asteroid values: ";

    for(int i=0;i<n;i++)
        cin>>asteroids[i];

    vector<int> ans=asteroidCollision(asteroids);

    cout<<"Remaining asteroids: ";

    for(int x:ans)
        cout<<x<<" ";

    return 0;
}