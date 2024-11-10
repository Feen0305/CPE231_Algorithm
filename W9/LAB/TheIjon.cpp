// Phoorin Chinphuad 66070501043
#include <iostream>
#include <vector>

using namespace std;

int Knapsack(int i, int j, int n, int W, int weights[], int value[], vector<vector<int>> &KnapTable){
    int Val;

    if (i < 0){ return 0; }

    if(KnapTable[i][j] < 0){

        if(j < weights[i]){
            Val = Knapsack(i - 1, j, n, W, weights, value, KnapTable); 
        }
        else{
            Val = max(Knapsack(i - 1 , j, n, W, weights, value, KnapTable), 
            value[i] + Knapsack(i - 1 , j - weights[i], n, W, weights, value, KnapTable));
        }

        KnapTable[i][j] = Val;
    }

    return KnapTable[i][j];

}

int main(){
    int n;
    cin >> n;

    int weights[n], value[n]; // weights ความรุงรัง , value ความหรูหรา

    for(int i = 0; i < n; i++){
        cin >> weights[i] >> value[i];
    }

    int W;
    cin >> W;

    vector<vector<int>> KnapTable(n , vector<int>(W + 1, -1));

    int maxVal = Knapsack(n - 1, W, n, W, weights, value, KnapTable);

    cout << maxVal << "\n";

    return 0;

}