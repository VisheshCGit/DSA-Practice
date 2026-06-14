#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    struct Sack {
        long long weight;
        long long value;
        double ratio;
    };

    static bool cmp(const Sack& a, const Sack& b) {
        return a.ratio > b.ratio;
    }

    double fractionalKnapsack(vector<long long>& val,
                              vector<long long>& wt,
                              long long capacity) {

        int n = val.size();

        vector<Sack> items(n);

        for (int i = 0; i < n; i++) {
            items[i].weight = wt[i];
            items[i].value = val[i];
            items[i].ratio =
                (double)val[i] / (double)wt[i];  //type conversion is important.. 
        }
//Applying Greedy approach, we will pick up that weight first which will give higher payment to lift a unit weight.. so sorted according to that ratio... 
        sort(items.begin(), items.end(), cmp);

        double maximumValue = 0;

        for (int i = 0; i < n; i++) {

            // If the complete item fits inside the knapsack
            if (items[i].weight <= capacity) {

                maximumValue += items[i].value;
                capacity -= items[i].weight;
            }

            // Otherwise take only the required fraction
            else {

                maximumValue +=
                    items[i].ratio * capacity;

                break; // Knapsack is full
            }
        }

        return maximumValue;
    }
};

int main() {

    int n;
    long long capacity;

    cout << "Please enter number of items: ";
    cin >> n;

    vector<long long> value(n);
    vector<long long> weight(n);

    cout << "Please enter values:\n";
    for (int i = 0; i < n; i++)
        cin >> value[i];

    cout << "Please enter weights:\n";
    for (int i = 0; i < n; i++)
        cin >> weight[i];

    cout << "Please enter knapsack capacity: ";
    cin >> capacity;

    Solution obj;

    cout << "Maximum value = "
         << obj.fractionalKnapsack(
                value,
                weight,
                capacity
            )
         << endl;

    return 0;
}