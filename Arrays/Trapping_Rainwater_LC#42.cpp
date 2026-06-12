#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int trapRainWater(vector<int>& heights){

    if(heights.empty())
        return 0;

    int n=heights.size();

    vector<int> rightMax(n);  //Prefix Max + Suffix Max (Better than Brute Force)  T.C. - O(n) S.C. - O(n) can be reduced to O(1)

    rightMax[n-1]=heights[n-1];  // we are calculating lefmax and rightmax to check water logging

    for(int i=n-2;i>=0;i--)
        rightMax[i]=max(heights[i],rightMax[i+1]);

    int leftMax=0;
    int totalWater=0;

    for(int i=0;i<n;i++){

        leftMax=max(leftMax,heights[i]);

        if(heights[i]<leftMax && heights[i]<rightMax[i])
            totalWater+=min(leftMax,rightMax[i])-heights[i];
    }

    return totalWater;
}

int main(){

    int n;

    cout<<"Please enter array size: ";
    cin>>n;

    vector<int> heights(n);

    cout<<"Please enter elevation heights: ";
    for(int i=0;i<n;i++)
        cin>>heights[i];

    cout<<"Total trapped rain water: "
        <<trapRainWater(heights);

    return 0;
}