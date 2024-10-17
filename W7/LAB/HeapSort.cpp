// Phoorin Chinphuad 66070501043
#include <iostream>

using namespace std;

void Heapify(int arr[], int size){
    for(int i = (size/2); i >= 0; i--){
        int parent = i;
        int parentValue = arr[parent];
        bool heap = false;

        while (!heap && (2*parent + 1) <= size)
        {
            int child = 2*parent + 1; // left child of parent
            if (child < size){
                // if condition is true it mean there are 2 children
                if(arr[child] > arr[child + 1]){ child++ ; } // update to right child of parent
            }

            if(parentValue >= arr[child]){
                arr[parent] = arr[child];
                parent = child;
            }
            else{
                heap = true;
            }
        }
        arr[parent] = parentValue;
    }
}

void HeapSort(int arr[], int size){

    for(int i = size; i > 0; i--){    
        Heapify(arr, i - 1);
        if(i == size ){
            for(int i = 0; i< size; i++){
                cout << arr[i] << " ";
            }
            cout << "\n";
        }
        swap(arr[0], arr[i - 1]);
    }
}

int main(){
    int size;
    cin >> size;

    int arr[size];
    for(int i = 0; i < size; i++){
        cin >> arr[i];
    }

    HeapSort(arr, size);

    for(int i = 0; i< size; i++){
        cout << arr[i] << " ";
    }


    return 0;
}