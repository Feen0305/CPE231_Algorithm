#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int Num;
    cin >> Num;

    vector<vector<float>> matrix(Num, vector<float>(Num));

    for(int n = 0; n < Num; n++){
        for(int m = 0; m < Num; m++){
            cin >> matrix[n][m];
        }
    }

    vector<int> PossibleWays(Num);
    for(int i = 0; i< Num; i++){
        PossibleWays[i] = i;
    }

    float MaxSum = 0.0;
    do{
        float CurSum = 0.0;
        for(int i = 0; i< Num; i++){
            CurSum += matrix[i][PossibleWays[i]];
        }
        if(CurSum > MaxSum){
            MaxSum = CurSum;
        }
    }while(next_permutation(PossibleWays.begin(), PossibleWays.end()));

    cout << MaxSum;

    return 0;
}
