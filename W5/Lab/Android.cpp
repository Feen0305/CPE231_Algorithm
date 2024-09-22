// Phoorin Chinphuad 66070501043

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int findTargetRound(string target, string pattern);
bool checkConsecutiveIncreasing(string pattern);
int findLargestIncreasingIndex(string pattern);
int findLargestGreaterIndex(string pattern, int i);
void reverse(string &pattern, int i);
void swap(int* a, int* b);



int main(){
    int Npoint , Mquest;
    string pattern;

    cin >> Npoint >> Mquest;

    pattern.resize(Npoint);
    // initial pattern length
    for(int i = 0; i < Npoint; i++){
        pattern[i] = 'A' + i;
    }
    // int count = 1;
    // for (string perm : permutations) {
    //     cout << count << " " << perm << endl;
    //     count++;
    // }

    string target;
    vector<int> Answer(Mquest);
    for(int i = 0; i < Mquest; i++){
        cin >> target;
        Answer[i] = findTargetRound(target , pattern);
    }

    for(const int n : Answer){
        cout << n << "\n";
    }

    return 0;
}

int findTargetRound(string target, string pattern){
    int count = 1;
    if(target == pattern){ return count; }

    while(checkConsecutiveIncreasing(pattern)){
        int i = findLargestIncreasingIndex(pattern);
        int j = findLargestGreaterIndex(pattern, i);
        swap(pattern[i], pattern[j]);
        reverse(pattern, i);
        count++;
        if(target == pattern){ return count; }
    }

    return -1;
}

bool checkConsecutiveIncreasing(string pattern){
    int N = pattern.length();
    for(int i = 0; i < N-1; i++){
        if(pattern[i] < pattern[i+1]){ return true; }
    }

    return false;
}

int findLargestIncreasingIndex(string pattern){
    int N = pattern.length();
    for(int i = N-2; i >= 0; i--){
        if(pattern[i+1] > pattern[i]){ return i ; }
    }

    return -1;
}

int findLargestGreaterIndex(string pattern, int i){
    int N = pattern.length();
    for(int j = N - 1; j > i; j--){
        if(pattern[i] < pattern[j]){ return j ; }
    }

    return -1;
}

void reverse(string &pattern, int i) {
    int N = pattern.length() - 1;
    for (int j = i + 1; j < N; j++, N--) {
        swap(pattern[j], pattern[N]);
    }
}

void swap(char &a, char &b) {
    char temp = a;
    a = b;
    b = temp;
}