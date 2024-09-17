#include <iostream>
#include <vector>

#define MAX 9999.0

using namespace std;

float CalEfficiency(int a1, int a2, int b1, int b2){
    float efficiency = 0.0;
    efficiency += float(abs(a1-a2))/float(abs(a1)+abs(a2))+
                    float(abs(b1-b2))/float(abs(b1)+abs(b2));

    return efficiency;
}

int main(){
    int NumPole;
    cin >> NumPole;

    vector<int> PoleH(NumPole), LocateH(NumPole);
    for(int i = 0; i<NumPole; i++){
        cin >> PoleH[i] >> LocateH[i];
    }

    float efficiency , minEffeciency = MAX;
    int minPole = -1, minLocate = -1;
    for(int i = 0; i<NumPole; i++){
        efficiency = 0;
        for(int j = 0; j<NumPole ; j++){
            if(j == i){ continue; }
            efficiency += CalEfficiency(PoleH[i], PoleH[j], LocateH[i], LocateH[j]);
        }
        efficiency /= float(NumPole-1);

        if(minEffeciency > efficiency){
            minEffeciency = efficiency;
            minPole = PoleH[i];
            minLocate = LocateH[i];
        }
    }

    cout << minPole << " " << minLocate << "\n";

    return 0;
}
