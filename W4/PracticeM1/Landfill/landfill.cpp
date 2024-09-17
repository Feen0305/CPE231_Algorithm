#include <iostream>
#include <vector>
#include <cmath>

#define MAX 99999

using namespace std;

vector<bool> ConvertToBin(int NumBit, int Number){
    vector<bool> binary(NumBit, 0);
    int i = NumBit - 1; //set i to last position

    while(Number && i >= 0){
        binary[i] = Number % 2;
        Number /= 2;
        i--;
    }

    return binary;
}

vector<int> SumFilled(vector<bool> binary,vector<int> Lands,vector<int> Fills,
                      int lengthLand, int lengthFill, int NumBit){

    int index;

    for(int i = 0; i < NumBit; i++){
        index = 0;
        if(binary[i]){
            for(int j = i; j < i+lengthFill; j++){
                Lands[j] += Fills[index++];
            }
        }
    }

    return Lands;
}

int findRough(vector<int> filled, int lengthLand){
    int rough = 0;
    for(int i= 0; i< lengthLand-1; i++){
        rough += abs(filled[i] - filled[i+1]);
    }

    return rough;
}

int main(){
    int lengthLand;
    cin >> lengthLand;

    vector<int> highsLand(lengthLand);
    for(int i = 0; i<lengthLand; i++){
        cin >> highsLand[i];
    }

    int l, m, r;
    cin >> l; cin >> m; cin >> r;

    int index = 0, lengthFill = (m-l)+(m-r)+1;
    vector<int> highsFill(lengthFill);

    while(l < m){
        highsFill[index++] = l++;
    }
    while(m >= r){
        highsFill[index++] = m--;
    }

    int NumBit = lengthLand - lengthFill + 1;
    int minRough = MAX;
    long int PossibleWays = pow(2,NumBit);

    for(int i = 0; i<PossibleWays; i++){
        vector<bool> bin = ConvertToBin(NumBit, i);

        vector<int> Filled = SumFilled(bin, highsLand, highsFill,
                                        lengthLand, lengthFill, NumBit);

        int CurRough = findRough(Filled, lengthLand);
        if(minRough > CurRough){
            minRough = CurRough;
        }
    }

    cout << minRough;

    return 0;
}
