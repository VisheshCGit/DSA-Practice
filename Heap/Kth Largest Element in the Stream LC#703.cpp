#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class KthLargest{
private:
    priority_queue<int,vector<int>,greater<int>> pq; //stores the k largest elements
    int k;

public:

    KthLargest(int k,vector<int> &nums){
        this->k=k;

        for(int num:nums){
            pq.push(num);

            if(pq.size()>k)
                pq.pop(); //remove the smallest so only k largest remain
        }
    }

    int add(int val){

        //heap not full yet
        if(pq.size()<k)
            pq.push(val);

        //replace the current kth largest only if a larger element arrives
        else if(val>pq.top()){
            pq.push(val);
            pq.pop();
        }

        return pq.top(); //smallest among the k largest = kth largest
    }
};

int main(){

    int k,n;

    cout<<"Enter k : ";
    cin>>k;

    cout<<"Enter number of initial elements : ";
    cin>>n;

    vector<int> nums(n);

    cout<<"Enter elements : ";
    for(int i=0;i<n;i++)
        cin>>nums[i];

    KthLargest obj(k,nums);

    int q;

    cout<<"Enter number of add operations : ";
    cin>>q;

    while(q--){

        int val;

        cout<<"Enter value : ";
        cin>>val;

        cout<<"Current Kth Largest : "<<obj.add(val)<<endl;
    }

    return 0;
}