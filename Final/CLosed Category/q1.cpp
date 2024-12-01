#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n; // Read the number of points

    vector<int> x_coords(n);
    vector<int> y_coords(n);

    for (int i = 0; i < n; i++) {
        cin >> x_coords[i] >> y_coords[i]; // Read the X and Y coordinates of each point
    }

    int sum_abs_diff_x = 0;
    int sum_abs_diff_y = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            sum_abs_diff_x += abs(x_coords[i] - x_coords[j]); // Calculate absolute difference for X coordinates
            sum_abs_diff_y += abs(y_coords[i] - y_coords[j]); // Calculate absolute difference for Y coordinates
        }
    }

    cout << sum_abs_diff_x + sum_abs_diff_y << endl; // Output the sum of absolute differences
    return 0;
}