#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;  
    
    vector<pair<int, int>> moneyBags(n);  
    for (int i = 0; i < n; ++i) {
        cin >> moneyBags[i].first >> moneyBags[i].second;
    }
    
    sort(moneyBags.begin(), moneyBags.end());   

    auto calculateCoins = [&](bool startRight) {
        set<int> visitedPositions;
        int totalCoins = 0;
        int left = 0, right = n - 1;
        bool moveRight = startRight;
        
        while (left <= right) {
            if (moveRight) {
                if (visitedPositions.find(moneyBags[right].first) == visitedPositions.end()) {
                    totalCoins += moneyBags[right].second;  
                    visitedPositions.insert(moneyBags[right].first);
                }
                right--;  
            } else {
                if (visitedPositions.find(moneyBags[left].first) == visitedPositions.end()) {
                    totalCoins += moneyBags[left].second;  
                    visitedPositions.insert(moneyBags[left].first);
                }
                left++;  
            }
            moveRight = !moveRight;  
        }
        
        return totalCoins;
    };
    
    int maxCoins = max(calculateCoins(true), calculateCoins(false));
    
    cout << maxCoins << endl;  
    return 0;
}
