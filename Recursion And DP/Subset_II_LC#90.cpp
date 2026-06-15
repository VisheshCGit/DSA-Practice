#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void generateSubsets(int index, vector<int>& numbers,
                     vector<int>& currentSubset,
                     vector<vector<int>>& allSubsets){

    allSubsets.push_back(currentSubset); // current subset is a valid answer

    for(int currentIndex=index; currentIndex<numbers.size(); currentIndex++){

        if(currentIndex>index &&
           numbers[currentIndex]==numbers[currentIndex-1])
            continue; // skip duplicate subsets at same recursion level

        currentSubset.push_back(numbers[currentIndex]); // choose current element

        generateSubsets(currentIndex+1,
                        numbers,
                        currentSubset,
                        allSubsets);

        currentSubset.pop_back(); // backtrack
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& numbers){

    sort(numbers.begin(), numbers.end()); // bring duplicates together

    vector<vector<int>> allSubsets;
    vector<int> currentSubset;

    generateSubsets(0,
                    numbers,
                    currentSubset,
                    allSubsets);

    return allSubsets;
}

int main(){

    int size;

    cout<<"Please enter array size: ";
    cin>>size;

    vector<int> numbers(size);

    cout<<"Please enter array elements: ";
    for(int i=0;i<size;i++)
        cin>>numbers[i];

    vector<vector<int>> answer=subsetsWithDup(numbers);

    cout<<"All unique subsets:"<<endl;

    for(auto subset : answer){

        cout<<"[ ";

        for(auto value : subset)
            cout<<value<<" ";

        cout<<"]"<<endl;
    }

    return 0;
}