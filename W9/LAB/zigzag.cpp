// Phoorin Chinphuad 66070501043
#include <iostream>
#include <vector>

using namespace std;

void LongestSubSequences(vector<vector<int>> &DP, int seq[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (seq[i] - seq[j] > 0) {
                DP[1][i] = max(DP[0][j] + 1, DP[1][i]);
            } 
            else if (seq[i] - seq[j] < 0) {
                DP[0][i] = max(DP[1][j] + 1, DP[0][i]);
            }
        }
    }
}

int main() {
    int n;
    cin >> n;

    int seq[n];
    for (int i = 0; i < n; i++) {
        cin >> seq[i];
    }

    vector<vector<int>> DP(2, vector<int>(n, 1));
    LongestSubSequences(DP, seq, n);


    //Ascending subsequence
    for (int i = 0; i < n; i++) {
        cout << DP[1][i] << " ";
    }
    cout << "\n";

    //Descending subsequence
    for (int i = 0; i < n; i++) {
        cout << DP[0][i] << " ";
    }
    cout << "\n";

    return 0;
}
