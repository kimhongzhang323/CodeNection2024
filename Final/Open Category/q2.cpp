#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

struct Event {
    int x, y1, y2, type; // x-coordinate, y-interval [y1, y2], type: 1 for start, -1 for end
    Event(int x, int y1, int y2, int type) : x(x), y1(y1), y2(y2), type(type) {}
};

// Compare function to sort events by x-coordinate
bool compareEvents(const Event &a, const Event &b) {
    return a.x < b.x;
}

// Helper function to calculate the union of active y-intervals
int calculateActiveLength(const vector<pair<int, int>> &active) {
    int length = 0, prevY = -1;
    for (const auto &interval : active) {
        length += max(0, interval.second - max(prevY, interval.first));
        prevY = max(prevY, interval.second);
    }
    return length;
}

int main() {
    int n;
    cin >> n;

    vector<Event> events;
    for (int i = 0; i < n; i++) {
        int x1, x2, y1, y2;
        cin >> x1 >> x2 >> y1 >> y2;

        // Add start and end events
        events.emplace_back(x1, y1, y2, 1);  // Rectangle starts
        events.emplace_back(x2, y1, y2, -1); // Rectangle ends
    }

    // Sort events by x-coordinate
    sort(events.begin(), events.end(), compareEvents);

    vector<pair<int, int>> activeYIntervals; // Active intervals on y-axis
    int prevX = events[0].x, totalArea = 0;

    for (const auto &event : events) {
        int currentX = event.x;

        // Calculate area since the last x-coordinate
        int activeLength = calculateActiveLength(activeYIntervals);
        totalArea += activeLength * (currentX - prevX);

        // Update active intervals
        if (event.type == 1) {
            activeYIntervals.emplace_back(event.y1, event.y2);
        } else {
            auto it = find(activeYIntervals.begin(), activeYIntervals.end(), make_pair(event.y1, event.y2));
            if (it != activeYIntervals.end()) {
                activeYIntervals.erase(it);
            }
        }

        // Sort active intervals
        sort(activeYIntervals.begin(), activeYIntervals.end());

        prevX = currentX;
    }

    cout << totalArea << endl;
    return 0;
}
