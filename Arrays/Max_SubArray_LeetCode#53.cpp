#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cout<<"Enter Length of Array\n";
    cin>>n;
    int arr[n];
    cout<<"Enter Elements\n";  // Taking input of array elements
    for (int i = 0; i < n; i++){    
       cin>>arr[i];
    }
    cout<<"All Possible Sub Array : \n";
    for(int start=0; start<n; start++){ //All Possible Sub Array
        for(int end = start; end < n; end++)
        {
            for(int j=start; j<=end; j++){
                if(j==end)
                cout<<arr[j]<<" || ";
                else
                cout<<arr[j]<<" ";
            }
        }
        cout<<endl;
    }
    int cs=0; int ms=INT_MIN; //cs= current sum, ms = max sum
       cout<<"Using Kadane's Algorithm! \nTime Complexity : O(n)\n";
       cs=0; ms=INT_MIN;
       for(int i=0; i<n; i++){   // Kadane's Algorithm
        cs+=arr[i];
        ms=max(cs,ms);
        if(cs<0)
        cs=0;
       } 
       cout<<"Max SubArray sum is : "<<ms;  
    return 0;
}