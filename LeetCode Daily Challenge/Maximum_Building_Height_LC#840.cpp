#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{ //20-June-2026
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions){

        restrictions.push_back({1,0}); //building 1 always has height 0
        sort(restrictions.begin(), restrictions.end());

        int m=restrictions.size();

        for(int i=1;i<m;i++) //propagate constraints from left to right
            restrictions[i][1]=min(restrictions[i][1], restrictions[i-1][1]+restrictions[i][0]-restrictions[i-1][0]);
        for(int i=m-2;i>=0;i--) //propagate constraints from right to left
            restrictions[i][1]=min(restrictions[i][1],  restrictions[i+1][1]+restrictions[i+1][0]-restrictions[i][0]);
        long long ans=0;
        for(int i=1;i<m;i++){
            long long leftIndex=restrictions[i-1][0];
            long long rightIndex=restrictions[i][0];
            long long leftHeight=restrictions[i-1][1];
            long long rightHeight=restrictions[i][1];
            long long distance=rightIndex-leftIndex;
            ans=max(ans,(leftHeight+rightHeight+distance)/2); //maximum peak possible between two restrictions
        }
        auto &lastRestriction=restrictions.back();
        ans=max(ans,(long long)lastRestriction[1]+(n-lastRestriction[0])); //buildings after last restriction
        return ans;
    }
};

int main(){
    int n,m;

    cout<<"Enter number of buildings: ";
    cin>>n;

    cout<<"Enter number of restrictions: ";
    cin>>m;

    vector<vector<int>> restrictions(m,vector<int>(2));

    cout<<"Enter building index and max height:\n";

    for(int i=0;i<m;i++)
        cin>>restrictions[i][0]>>restrictions[i][1];

    Solution obj;

    cout<<"Maximum Building Height = "<<obj.maxBuilding(n,restrictions);

    return 0;
}