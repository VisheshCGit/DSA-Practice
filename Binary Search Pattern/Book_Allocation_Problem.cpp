#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:

    bool canAllocate(vector<int>& books, int students, int maxPages) {

        int studentCount = 1;
        int currentPages = 0;

        for (int i = 0; i < books.size(); i++) {

            if (currentPages + books[i] <= maxPages) {
                currentPages += books[i];
            }
            else {
                studentCount++;
                currentPages = books[i];

                if (studentCount > students)
                    return false;
            }
        }

        return true;
    }

    int findPages(vector<int>& books, int students) {

        int n = books.size();

        if (students > n)
            return -1;

        int low = INT_MIN; // max of minimum pages a student can get.. lowest Upper Bound
        int high = 0;   // if m=n then, our answer will be the book with max pages so low=maxof(book array)

        for (int i = 0; i < n; i++) {
            low = max(low, books[i]);
            high += books[i];
        }

        int answer = -1;

        while (low <= high) { //if you do (low<high) then high=mid, if(low<=high) then high=mid-1

            int mid = low + (high - low) / 2;

            if (canAllocate(books, students, mid)) {

                answer = mid;  //feasible answer.. we are storing it so that it doesn't get lost
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return answer;
    }
};

int main() {

    int n, students;

    cout << "Enter number of books: ";
    cin >> n;

    vector<int> books(n);

    cout << "Enter pages in each book: ";

    for (int i = 0; i < n; i++) {
        cin >> books[i];
    }

    cout << "Enter number of students: ";
    cin >> students;

    Solution obj;

    cout << "Minimum possible maximum pages = "
         << obj.findPages(books, students)
         << endl;

    return 0;
}