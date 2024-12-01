#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool doIntersect(pair<int, int> bridge1, pair<int, int> bridge2) {
    if (bridge1.first > bridge1.second) swap(bridge1.first, bridge1.second);
    if (bridge2.first > bridge2.second) swap(bridge2.first, bridge2.second);

    return (bridge1.first < bridge2.first && bridge2.first < bridge1.second && bridge1.second < bridge2.second) ||
           (bridge2.first < bridge1.first && bridge1.first < bridge2.second && bridge2.second < bridge1.second);
}

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> bridges(n);
    for (int i = 0; i < n; ++i) {
        cin >> bridges[i].first >> bridges[i].second;
        if (bridges[i].first > bridges[i].second) {
            swap(bridges[i].first, bridges[i].second);
        }
    }

    int complexity = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (doIntersect(bridges[i], bridges[j])) {
                complexity++;
            }
        }
    }

    cout << complexity << endl;

    return 0;
}