// Phoorin Chinphuad 66070501043

#include <iostream>

using namespace std;

int QuickSelect(int arr[], int size, int key);
int partition(int arr[], int l, int r);
void swap(int* a, int* b);

int main() {
    int size;
    cin >> size;

    int arr[size];
    for(int i = 0; i < size; i++){
        cin >> arr[i];
    }

    int key;
    cin >> key;

    int keyValue = QuickSelect(arr, size, key);
    cout << keyValue ;

    return 0;
}

int QuickSelect(int arr[], int sizeOFarray, int key){

    int L = 0, R = sizeOFarray - 1;
    while( L <= R ){
        int pivot = partition(arr, L, R);
        if(pivot == key - 1){ return arr[pivot]; }
        if(pivot < key - 1){ L = pivot + 1; }
        else{ R = pivot - 1; }
    }

    return -1;
}

int partition(int arr[], int l, int r){
    if(l >= r){ return l; }
    for(int i = l; i < r; i++){
        if(arr[i] < arr[r]){ swap(arr[i], arr[l++]); }
    }

    swap(arr[l], arr[r]);
    return l;
}

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}