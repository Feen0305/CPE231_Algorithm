// Phoorin Chinphuad 66070501043
#include <iostream>
#include <vector>

using namespace std;

int main(){
    int max, n;
    cin >> max >> n;

    int arr[n];
    // Input for arr
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    // Initialize Flag vector with size n+1 and set all values to false except [0]
    vector<bool> Flag(max + 1, false);
    Flag[0] = true;

    // Process the array and update Flag values
    for(int i = 0; i < n; i++){
        for(int j = arr[i]; j <= max; j++){
            Flag[j] = Flag[j] || Flag[j - arr[i]];
        }
    }

    for(int i = max; i >= 0; i--){
        if(!Flag[i]){
            cout << i << "\n";
            return 0;
        }
    }

    return 0;
}

