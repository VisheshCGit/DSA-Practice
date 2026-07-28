#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
    int maxArea(vector<int> &height){
        int left=0,right=height.size()-1;
        int ans=0;

        while(left<right){
            int area=(right-left)*min(height[left],height[right]);
            ans=max(ans,area);

            if(height[left]<height[right])
                left++;
            else
                right--;
        }

        return ans;
    }
};

int main(){

    int n;

    cout<<"Enter number of heights: ";
    cin>>n;

    vector<int> height(n);

    cout<<"Enter heights: ";

    for(int &x:height)
        cin>>x;

    Solution obj;

    cout<<"Maximum Area = "<<obj.maxArea(height);

    return 0;
}