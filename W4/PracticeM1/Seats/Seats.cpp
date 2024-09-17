#include <iostream>
#include <vector>

using namespace std;

struct students{
    int id, score;
};

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

vector<struct students> SelectionSort(vector<struct students> data, int length){
    for(int i = 0; i < length - 1; i++){
        int maxPos = i;
        for(int j = i+1; j < length; j++){
            if(data[maxPos].score < data[j].score ){
                maxPos = j;
            }
        }
        if(data[i].score < data[maxPos].score){
            while(i < maxPos){
                swap(data[maxPos], data[maxPos-1]);
                maxPos--;
            }

        }
    }

    return data;
}

int main(){
    int N;
    cin >> N;

    vector<struct students> Student(N);
    for(int i = 0; i< N; i++){
        cin >> Student[i].id >> Student[i].score;
    }

    Student = SelectionSort(Student, N);

    for(int i = 0; i< N; i++){
        cout << Student[i].id << "\n";
    }

    return 0;
}
