#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void traversalSalesman(vector<vector<int>> Flights, vector<string> countryList, int NumCountry) {
    vector<int> PossibleWays(NumCountry);
    vector<int> Ans;
    int start = 0;

    for(int i = 0; i < NumCountry; i++) {
        PossibleWays[i] = i + 1;
    }

    int MAXcost = 0;
    do{
        int CURcost = 0;
        int current = start;

        for(int i = 0; i < NumCountry; i++){
            CURcost += Flights[current][PossibleWays[i]];
//            cout << " cur cost >>" << Flights[current][PossibleWays[i]]  << " origin >>" << current << " dest>>" << PossibleWays[i] << "\n";
            current = PossibleWays[i];
        }
        CURcost += Flights[current][start];

//        cout << CURcost << "\n";

        if(CURcost > MAXcost){
            MAXcost = CURcost;
            Ans = PossibleWays;
        }
    }while(next_permutation(PossibleWays.begin(), PossibleWays.end()));

    Ans.insert(Ans.begin(), 0);
    Ans.insert(Ans.end(), 0);

    for(int i = 0; i<NumCountry+2; i++){
        cout << countryList[Ans[i]] << " ";
    }

    cout << "\n" << MAXcost;
}

vector<string> AddTo(string name, vector<string> countryList, int* index){
    int NumCountry = countryList.size();
    int i = 0;
    bool found = false;

    for(; i < NumCountry; i++){
        if(name == countryList[i]){
            found = true;
            break;
        }
    }

    if(!found){
        *index = NumCountry;
        countryList.push_back(name);
    }
    else{
        *index = i;
    }
    return countryList;
}

int main() {
    int NumCountry, Numflight;
    cin >> NumCountry >> Numflight;

    vector<string> countryList;
    countryList.push_back("THA"); // start end

    vector<pair<string, string>> tempPath(Numflight);
    vector<int> tempWeight(Numflight);

    for(int i=0 ; i<Numflight; i++){
        cin >> tempPath[i].first >> tempPath[i].second >> tempWeight[i];
    }

    vector<vector<int>> Flights(NumCountry+1, vector<int>(NumCountry+1, 0));
    int indexOri, indexDest;

    for(int i=0 ; i<Numflight; i++){
        countryList = AddTo(tempPath[i].first, countryList, &indexOri);
        countryList = AddTo(tempPath[i].second, countryList, &indexDest);

        Flights[indexOri][indexDest] = Flights[indexDest][indexOri] = tempWeight[i];
    }

//    for(int i= 0; i < NumCountry+1; i++){
//        cout << countryList[i] << " ";
//    }
//    cout << "\n";
//
//    for(int i= 0; i < NumCountry+1; i++){
//        for(int j= 0; j < NumCountry+1; j++){
//            cout << Flights[i][j] << " ";
//        }
//        cout << "\n";
//    }
//    cout << "\n";

    traversalSalesman(Flights, countryList, NumCountry);


    return 0;
}
