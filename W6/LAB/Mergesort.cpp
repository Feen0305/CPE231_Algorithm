// Phoorin Chinphuad 66070501043
#include <iostream>

using namespace std;

void BottomUpMergeSort(int arr[], int n);
void merge(int arr[], int left, int mid, int right);

int main(){
    int size;
    cin >> size;

    int arr[size];
    for(int i = 0; i < size; i++){
        cin >> arr[i];
    }

    BottomUpMergeSort(arr, size);

    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }


    return 0;
}

void BottomUpMergeSort(int arr[], int n){
    if(n < 2){ return ; }

    int i = 1;
    while (i < n){
        int j = 0;
        while(j < n - i){
            if(n < j + (2 * i)){ merge(arr, j, j+i, n); }
            else { merge(arr, j, j+i, j+(2*i)); }

            j += 2*i;
        }
        i *= 2;
    }
    
    return ;
}

void merge(int arr[], int left, int mid, int right){
    int range1 = mid - left;
    int range2 = right - mid;

    int L[range1], R[range2];

    // copy element from arr to L and R
    // to merge
    for(int i = 0; i < range1; i++){
        L[i] = arr[left + i];
    }
    for(int i = 0; i < range2; i++){
        R[i] = arr[mid + i];
    }

    int i = 0, j = 0, k = left;

    //merge
    while (i < range1 && j < range2){
        if(L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // copy if there are any remaining element left
    while(i < range1){
        arr[k] = L[i];
        i++; k++;
    }

    while(j < range2){
        arr[k] = R[j];
        j++; k++;
    }

    return ;
}