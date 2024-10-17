// Phoorin Chinphuad 66070501043
#include <iostream>

using namespace std;

void ShiftTable(char pattern[], int M, int table[]){

    // Initialize table with size of pattern
    for(int i = 0; i < 26; i++){
        table[i] = M;
    }

    // Fill shift values based on the pattern
    for(int i = 0; i < M - 1; i++){
        table[pattern[i] - 'A'] = M - 1 - i;
    }
}

int HorspoolMatching(char pattern[], int M, char text[], int N, int* Nshift){

    int table[26];  // Shift table for uppercase letters A-Z
    ShiftTable(pattern, M, table);
    
    int i = M - 1;  // Start matching from the end of the pattern
    while(i <= N - 1){
        int k = 0;
        // Match the pattern from right to left
        while(k < M && pattern[M - 1 - k] == text[i - k]){
            k++;
        }
        if(k == M){  
            return i - M + 1; // If full match, return the starting position
        }
        else{
            i += table[text[i] - 'A'];  // Shift based on the table
            (*Nshift)++;
        }
    }

    return -1;  // If no match found, return -1
}

int main(){
    int Ntext, Npattern;
    cin >> Ntext >> Npattern;

    char text[Ntext], pattern[Npattern];

    for(int i = 0; i < Ntext; i++){
        cin >> text[i];
    }

    for(int i = 0; i < Npattern; i++){
        cin >> pattern[i];
    }
    
    int Nshift = 0;
    int matchIndex = HorspoolMatching(pattern, Npattern, text, Ntext, &Nshift);


    if(matchIndex >= 0){ cout << "YES "; }
    else{ cout << "NO "; }
    cout << Nshift << " " << matchIndex;
        

    return 0;
}