#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int x, y, k;
    cin >> x >> y >> k;

    int count = 0;

    for (int width = 1; width <= sqrt(k); ++width) {
        if (k % width == 0) {
            int height = k / width;

            if (width <= x && height <= y) {
                count += (x - width + 1) * (y - height + 1);
            }

            if (width != height && height <= x && width <= y) {
                count += (x - height + 1) * (y - width + 1);
            }
        }
    }

    cout << count << endl;

    return 0;
}
