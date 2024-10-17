// Phoorin Chinphuad 66070501043
#include <iostream>

using namespace std;

void QuickSort(int arr[], int l, int r);
int HoarePartition(int arr[], int l, int r);

int main(){
    int size;
    cin >> size;

    int arr[size];
    for(int i = 0; i < size; i++){
        cin >> arr[i];
    }

    int l = 0 , r = size - 1;
    QuickSort(arr, l, r);

    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }

    return 0;
   
}

void QuickSort(int arr[], int l, int r){
    if(l < r){
        int s = HoarePartition(arr, l, r);
        // debug each partition
        // for(int i = l; i <= r; i++){
        //         cout << arr[i] << " ";
        // }
        // cout << "\n";

        QuickSort(arr, l, s - 1);
        QuickSort(arr, s + 1, r);
    }

    return ;
}

int HoarePartition(int arr[], int l, int r){
    int pivot = arr[l];
    int i = l;
    int j = r+1;
    while(i < j){
        do{i++;}while(arr[i] < pivot);
        do{j--;}while(arr[j] > pivot);
        swap(arr[i], arr[j]);
    }
    swap(arr[i], arr[j]);
    swap(arr[l], arr[j]);
    return j;
}