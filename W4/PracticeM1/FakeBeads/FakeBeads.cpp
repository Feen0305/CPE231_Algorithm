#include <iostream>
#include <vector>

#define MAX 99999

using namespace std;

int main(){
    int NumBead;
    cin >> NumBead;

    vector<int> PosBeads(NumBead);
    for(int i = 0; i < NumBead; i++){
        cin >> PosBeads[i];
    }

    int minDist = MAX;
    for(int i = 0; i < NumBead - 1; i++){
        int CurDist = PosBeads[i+1] - PosBeads[i];
        if(minDist > CurDist){
            minDist = CurDist;
        }
    }

    vector<int> MoveDist(NumBead);
    MoveDist[0] = 0;
    for(int i = 1; i < NumBead; i++){
        int Move = 0;
        while((PosBeads[i] - PosBeads[i-1]) > minDist){
            PosBeads[i]--;
            Move++;
        }
        MoveDist[i] = Move;
    }

    for(int i = 0 ; i< NumBead; i++){
        cout << MoveDist[i] << " ";
    }

    return 0;
}
