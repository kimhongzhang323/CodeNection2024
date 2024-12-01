#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n; // Read the number of friends

    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i]; // Read the feedback scores for each friend
    }

    int totalmarks = 0; // Initialize total feedback score
    int count = 0; // Initialize count of speeches
    priority_queue<int, vector<int>, greater<int>> minHeap; // Min-heap to track smallest negative feedback scores

    for (int i = 0; i < n; i++) {
        totalmarks += A[i]; // Add current feedback score to total
        count++; // Increment count of speeches
        if (A[i] < 0) {
            minHeap.push(A[i]); // Push negative feedback score to min-heap
        }

        // If total feedback score becomes negative, remove smallest negative feedback score
        while (totalmarks < 0 && !minHeap.empty()) {
            totalmarks -= minHeap.top(); // Remove smallest negative feedback score from total
            minHeap.pop(); // Remove smallest negative feedback score from min-heap
            count--; // Decrement count of speeches
        }
    }

    cout << count << endl; // Output the maximum number of speeches
    return 0;
}