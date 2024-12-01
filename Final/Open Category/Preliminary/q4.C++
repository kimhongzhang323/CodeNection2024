#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool CanBeTogether(const string& manuscript, const string& hiddenMessage) {
    int m = manuscript.size();
    int h = hiddenMessage.size();
    int j = 0;

    for (int i = 0; i < m && j < h; ++i) {
        if (manuscript[i] == hiddenMessage[j] || manuscript[i] == '*') {
            j++;
        }
    }

    return j == h;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        string manuscript, hiddenMessage;
        cin >> manuscript >> hiddenMessage;
        if (CanBeTogether(manuscript, hiddenMessage)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}