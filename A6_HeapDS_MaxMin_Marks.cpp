#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int num_studs;
    int marks;
    
    cout << "Enter number of students: ";
    cin >> num_studs;

    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int i = 0; i < num_studs; i++) {
        cout << "Marks for student " << i+1 << ": ";
        cin >> marks;
        maxHeap.push(marks);
        minHeap.push(marks);
    }

    cout << "Maximum Marks: " << maxHeap.top() << endl;
    cout << "Minimum Marks: " << minHeap.top() << endl;

    return 0;
}
