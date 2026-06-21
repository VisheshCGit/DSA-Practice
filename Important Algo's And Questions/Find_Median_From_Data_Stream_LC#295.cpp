#include <iostream>
#include <queue>
using namespace std;

class MedianFinder {
private:
    priority_queue<int> maxHeap;
    priority_queue< int, vector<int>, greater<int> > minHeap;  // 4,5,6,7,8|9,10,11,12 Left Side- Pick top element from max heap, Right Side- Pick top element from Min Heap
public:

    void addNum(int num) {

        maxHeap.push(num);

        minHeap.push(maxHeap.top()); //max heap's top contains largest value from the left portion
        maxHeap.pop();

        if(minHeap.size() > maxHeap.size()) { //size of left can be equal to right or only 1 greater than the right
            maxHeap.push(minHeap.top()); //min heap's top contains smallest value of right half 
            minHeap.pop();
        }
    }

    double findMedian() {

        int totalSize = maxHeap.size() + minHeap.size();

        if(totalSize % 2)
            return maxHeap.top();

        return (maxHeap.top() + minHeap.top()) / 2.0;
               
    }
};

int main() {

    MedianFinder mf;

    mf.addNum(1);
    cout << "Median: " << mf.findMedian() << endl;

    mf.addNum(2);
    cout << "Median: " << mf.findMedian() << endl;

    mf.addNum(3);
    cout << "Median: " << mf.findMedian() << endl;

    mf.addNum(4);
    cout << "Median: " << mf.findMedian() << endl;

    return 0;
}