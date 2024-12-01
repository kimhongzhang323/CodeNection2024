#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> codey_y; // Stores y-coordinates of Codey (on y-axis)
    vector<int> alien_x; // Stores x-coordinates of aliens (on x-axis)

    for (int i = 0; i < 2 * n; ++i) {
        int x, y;
        cin >> x >> y;
        if (x == 0) {
            codey_y.push_back(abs(y)); // Codey clone on y-axis
        } else {
            alien_x.push_back(abs(x)); // Alien on x-axis
        }
    }

    // Sort the coordinates
    sort(codey_y.begin(), codey_y.end());
    sort(alien_x.begin(), alien_x.end());

    // Calculate the minimum total distance
    double total_distance = 0.0;
    for (int i = 0; i < n; ++i) {
        total_distance += sqrt(pow(alien_x[i], 2) + pow(codey_y[i], 2));
    }

    // Print the result with 9 decimal places
    cout << fixed << setprecision(9) << total_distance << endl;

    return 0;
}
