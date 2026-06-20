#include <iostream>
using namespace std;

class MaxHeap {
public:
    int arr[100000];
    int size;

    MaxHeap() {
        size = 0;
    }

    void insert(int key) {

        int index = size;
        arr[index] = key;
        size++;

        while(index > 0) {

            int parent = (index - 1) / 2;

            if(arr[index] > arr[parent]) {
                swap(arr[index], arr[parent]);
                index = parent;
            }
            else
                break;
        }
    }

    void changeKey(int index, int newVal) {

        if(index >= size)
            return;

        int oldVal = arr[index];
        arr[index] = newVal;

        if(oldVal > newVal) {

            int i = index;

            while(true) { //heapify down

                int left = 2 * i + 1;
                int right = 2 * i + 2;
                int largest = i;

                if(left < size && arr[left] > arr[largest])
                    largest = left;

                if(right < size && arr[right] > arr[largest])
                    largest = right;

                if(largest == i)
                    break;

                swap(arr[i], arr[largest]);
                i = largest;
            }
        }
        else { //Heapify Up logic is same as insertion

            while(index > 0) {

                int parent = (index - 1) / 2;

                if(arr[index] > arr[parent]) {
                    swap(arr[index], arr[parent]);
                    index = parent;
                }
                else
                    break;
            }
        }
    }

    void extractMax() {

        if(size == 0)
            return;

        arr[0] = arr[size - 1];
        size--;

        int i = 0;

        while(true) {

            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int largest = i;

            if(left < size && arr[left] > arr[largest])
                largest = left;

            if(right < size && arr[right] > arr[largest])
                largest = right;

            if(largest == i)
                break;

            swap(arr[i], arr[largest]);
            i = largest;
        }
    }

    int getMax() {

        if(size == 0)
            return -1;

        return arr[0];
    }

    bool isEmpty() {
        return size == 0;
    }

    int heapSize() {
        return size;
    }
};

int main() {

    MaxHeap heap;

    heap.insert(50);
    heap.insert(30);
    heap.insert(80);
    heap.insert(20);

    cout << "Maximum Element: " << heap.getMax() << endl;

    heap.extractMax();

    cout << "Maximum After Deletion: " << heap.getMax() << endl;

    cout << "Heap Size: " << heap.heapSize() << endl;

    return 0;
}