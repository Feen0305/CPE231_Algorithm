#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

vector<bool> ConvertToBin(int NumBit, int Number){
    vector<bool> bin(NumBit, 0);
    int i = NumBit - 1; // set "i" to last position

    while(Number && i >= 0){
        bin[i] = Number % 2;
        Number /= 2;
        i--;
    }

    return bin;
}

int SumCheck(int NumBit, vector<bool> binary, int Target){
    int sum = 0;
    for(int i = 0; i< NumBit; i++){
        if(binary[i]){
            sum += (i+1);
        }
    }
    if(sum == Target){
        return 1;
    }
    return 0;
}

void OddEvenCheck(int NumBit, vector<bool> binary, int* NumOdd, int* NumEven){
    for(int i = 0; i < NumBit; i++){
        if(binary[i]){
            if((i+1)%2){
                (*NumOdd) += 1;
            }
            else{
                (*NumEven) += 1;
            }
        }
    }

    return ;
}

int main(){
    int x, y,NumOdd = 0, NumEven = 0;
    cin >> x;
    cin >> y;

    int PossibleWays = pow(2,x);

    for(int i = 1; i<PossibleWays; i++){
        vector<bool> bin = ConvertToBin(x, i);
        if(SumCheck(x, bin, y)){
            OddEvenCheck(x, bin, &NumOdd, &NumEven);
        }
    }

    cout << NumOdd << "\n";
    cout << NumEven << "\n";

    return 0;
}
