#include <iostream>

using namespace std;

void CountingSort(int arr[], int size, int out[]){
    //initialize counting array
    int Count[size];
    for(int i = 0; i < size; i++){
        out[i] = Count[i] = 0;
    }

    for(int i = 0; i < size - 1; i++){
        for(int j = i + 1 ; j < size; j++){
            if(arr[i] < arr[j]){
                Count[j] += 1;
            }
            else{
                Count[i] += 1;
            }
        }

        for(int i = 0; i < size; i++){
            cout << Count[i] << " ";
        }
        cout << "\n";
    }

    for(int i = 0; i < size; i++){
        out[Count[i]] = arr[i];
    }

    return;
}

int main(){
    int size;
    cin >> size;

    int arr[size], out[size];
    for(int i = 0; i < size; i++){
        cin >> arr[i];
    }

    CountingSort(arr, size, out);

    for(int i = 0; i < size; i++){
        cout << out[i] << " ";
    }

    return 0;
}

