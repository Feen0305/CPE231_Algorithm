#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// custom compare for sorting max to min
bool MaxtoMin(int a, int b) {
    return a > b;
}

int main() {
    int n, height;
    cin >> n;

    vector<int> Trees(n), Pots(n), TotalHeights(n);

    for (int i = 0; i < n; ++i) {
        cin >> Trees[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> Pots[i];
    }

    sort(Trees.begin(), Trees.end(), MaxtoMin); // sort (max -> min)
    sort(Pots.begin(), Pots.end()); // sort (min -> max)

    for (int i = 0; i< n; i++) {
        TotalHeights[i] = Trees[i] + Pots[i]; 
    }

    sort(TotalHeights.begin(), TotalHeights.end()); // sort (min -> max)

    int sumOfDifferences = 0;
    for (int i = 1; i < n; ++i) {
        sumOfDifferences += (TotalHeights[i] - TotalHeights[i - 1]);
    }

    cout << sumOfDifferences << "\n";

    return 0;
}


