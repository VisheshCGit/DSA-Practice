#include<iostream>
#include<vector>
using namespace std;

int trapRainWater(vector<int>& heights){

    int left=0;
    int right=heights.size()-1;

    int leftMax=0;
    int rightMax=0;

    int totalWater=0;

    while(left<right){

        if(heights[left]<=heights[right]){ // left side is the limiting boundary

            if(heights[left]<leftMax)
                totalWater+=leftMax-heights[left]; // water trapped at current left index
            else
                leftMax=heights[left]; // update left maximum height

            left++;
        }
        else{

            if(heights[right]<rightMax)
                totalWater+=rightMax-heights[right]; // water trapped at current right index
            else
                rightMax=heights[right]; // update right maximum height

            right--;
        }
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