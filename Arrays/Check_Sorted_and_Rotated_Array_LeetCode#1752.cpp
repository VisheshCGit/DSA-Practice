#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool checkSortedRotated(vector<int>& numbers){
    vector<int> sorted=numbers;
    int size=numbers.size();
    int matchedCount=0;

    sort(sorted.begin(),sorted.end());

    for(int shift=0;shift<size;shift++){
        for(int i=0;i<size;i++){
            if(numbers[i]==sorted[(i+shift)%size])
                matchedCount++;
        }

        if(matchedCount==size)
            return true;

        matchedCount=0;
    }

    return false;
}
int main(){
    int size;

    cout<<"Enter the size of array: ";
    cin>>size;

    vector<int> numbers(size);

    cout<<"Enter the array elements: ";
    for(int i=0;i<size;i++)
        cin>>numbers[i];

    cout<<"\nBrute Force Result: ";
    if(checkSortedRotated(numbers))
        cout<<"true";
    else
        cout<<"false";
    return 0;
}