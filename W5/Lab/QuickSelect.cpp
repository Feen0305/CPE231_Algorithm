// Phoorin Chinphuad 66070501043

#include <iostream>

using namespace std;

int partition(int arr[], int l, int r);
int QuickSelect(int arr[], int l, int r, int key);
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

    int L = 0, R = size - 1;
    int keyValue = QuickSelect(arr, L, R, key);
    cout << keyValue ;

    return 0;
}

int QuickSelect(int arr[], int l, int r, int key){
    int pivot = partition(arr, l, r);
    // debug each partition
    // for(int i = l; i <= r; i++){
    //         cout << arr[i] << " ";
    // }
    // cout << "\n";

    if(pivot == key - 1){ return arr[pivot]; }
    else if(pivot > key - 1){ return QuickSelect(arr, l, pivot - 1, key); }
    else{ return QuickSelect(arr, pivot + 1, r, key); }

}

int partition(int arr[], int l, int r){
    int pivot = arr[l];
    int s = l;

    for(int i = l+1;  i <= r; i++){
        if(arr[i] < pivot){
            swap(arr[++s] , arr[i]);
        }
    }
    swap(arr[l] , arr[s]);
    return s;
}
