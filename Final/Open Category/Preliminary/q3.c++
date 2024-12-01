#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int subarray(int n, int m, int p, vector<int>& kitchen, vector<int>& recipe) {
    unordered_map<int, int> recipeFreq;
    for (int ingredient : recipe) {
        recipeFreq[ingredient]++;
    }

    unordered_map<int, int> windowFreq;

    int count = 0;
    int matches = 0; 

    for (int i = 0; i < m; ++i) {
        int ingredient = kitchen[i];
        windowFreq[ingredient]++;
        if (recipeFreq.find(ingredient) != recipeFreq.end() && windowFreq[ingredient] <= recipeFreq[ingredient]) {
            matches++;
        }
    }

    if (matches >= p) {
        count++;
    }

    for (int i = m; i < n; ++i) {
        int outElement = kitchen[i - m];
        windowFreq[outElement]--;
        if (recipeFreq.find(outElement) != recipeFreq.end() && windowFreq[outElement] < recipeFreq[outElement]) {
            matches--;
        }

        int inElement = kitchen[i];
        windowFreq[inElement]++;
        if (recipeFreq.find(inElement) != recipeFreq.end() && windowFreq[inElement] <= recipeFreq[inElement]) {
            matches++;
        }

        if (matches >= p) {
            count++;
        }
    }

    return count;
}

int main() {
    int n, m, p;
    cin >> n >> m >> p;
    vector<int> kitchen(n);
    vector<int> recipe(m);
    
    for (int i = 0; i < n; i++) {
        cin >> kitchen[i];
    }
    
    for (int i = 0; i < m; i++) {
        cin >> recipe[i];
    }
    
    cout << subarray(n, m, p, kitchen, recipe) << endl;
    
    return 0;
}
