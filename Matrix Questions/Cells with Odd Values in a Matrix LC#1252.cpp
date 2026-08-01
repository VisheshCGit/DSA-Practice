#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int oddCells(int m,int n,vector<vector<int>> &indices){
        vector<int> row(m,0),col(n,0);

        for(auto &x:indices){
            row[x[0]]++;
            col[x[1]]++;
        }

        int ans=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if((row[i]+col[j])&1)
                    ans++;
            }
        }

        return ans;
    }
};

int main(){

    int m,n,k;

    cout<<"Enter rows and columns: ";
    cin>>m>>n;

    cout<<"Enter number of operations: ";
    cin>>k;

    vector<vector<int>> indices(k,vector<int>(2));

    cout<<"Enter row and column for each operation:\n";

    for(int i=0;i<k;i++)
        cin>>indices[i][0]>>indices[i][1];

    Solution obj;

    cout<<"Odd Cells = "<<obj.oddCells(m,n,indices);

    return 0;
}