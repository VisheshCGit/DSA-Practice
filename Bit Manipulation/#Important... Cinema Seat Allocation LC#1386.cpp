#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution{
public:
    int maxNumberOfFamilies(int n,vector<vector<int>> &reservedSeats){
        unordered_map<int,int> mp;

        for(auto &x:reservedSeats)
            mp[x[0]]|=(1<<x[1]);

        int ans=(n-mp.size())*2;

        int left=(1<<2)|(1<<3)|(1<<4)|(1<<5);
        int middle=(1<<4)|(1<<5)|(1<<6)|(1<<7);
        int right=(1<<6)|(1<<7)|(1<<8)|(1<<9);

        for(auto &x:mp){
            int mask=x.second;
            bool leftFree=(mask&left)==0;
            bool middleFree=(mask&middle)==0;
            bool rightFree=(mask&right)==0;

            if(leftFree && rightFree)
                ans+=2;
            else if(leftFree || middleFree || rightFree)
                ans++;
        }

        return ans;
    }
};

int main(){
    int n,m;

    cout<<"Enter number of rows: ";
    cin>>n;

    cout<<"Enter number of reserved seats: ";
    cin>>m;

    vector<vector<int>> reservedSeats(m);

    cout<<"Enter reserved seats:\n";
    for(int i=0;i<m;i++){
        int row,seat;
        cin>>row>>seat;
        reservedSeats[i]={row,seat};
    }

    Solution obj;

    cout<<"Maximum Number of Families = "
        <<obj.maxNumberOfFamilies(n,reservedSeats);

    return 0;
}