// Phoorin Chinphuad 66070501043

#include <iostream>

using namespace std;

void pancakeSort(int arr[], int size);
int findMaxIndex(int arr[], int i);
void flip(int arr[], int i);
void swap(int* a, int* b);

int main(){
    int size;
    cin >> size;

    int arr[size];
    for(int i = 0; i < size; i++){
        cin >> arr[i];
    }

    pancakeSort(arr, size);

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    return 0;

}

void pancakeSort(int arr[], int size){

    for(int i = size - 1; i > 0; i--){
        int MaxPos = findMaxIndex(arr, i);

        if(MaxPos != i){
            if(MaxPos != 0){
                flip(arr, MaxPos);
            }
            flip(arr, i);
        }
    }
}

int findMaxIndex(int arr[], int i){
    int MaxPos = i;
    for(int j = i-1; j >= 0; j--){
        if(arr[j] > arr[MaxPos]){ MaxPos = j; } 
    }

    return MaxPos;
}

void flip(int arr[], int i){
    int k = i;
    for(int j = 0; j < k; j++){   
        swap(&arr[j] , &arr[k]);
        k--;
    }
}

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}