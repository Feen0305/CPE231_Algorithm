// Phoorin Chinphuad 66070501043
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int findHashIndex(string word, int Z){
    int size = word.size();
    int sum = 0;
    for(int i = 0; i < size; i++){
        sum += (int)word[i] - 64;
    }
    return sum%Z;
}

int main(){
    int HashSize, N;
    cin >> HashSize >> N;

    vector<string> HashTable(HashSize, "NULL");
    for(int i = 0; i < N ; i++){
        string word;
        cin >> word;

        int HashIndex = findHashIndex(word, HashSize);
        
        if(HashTable[HashIndex] == "NULL"){
            HashTable[HashIndex] = word;
        }
        else{
            while(HashTable[HashIndex] != "NULL"){
                HashIndex = ( HashIndex + 1 ) % HashSize;
            }
            HashTable[HashIndex] = word;
        }
        
    }

    for(int i = 0 ; i < HashSize; i++){
        cout << HashTable[i] << " ";
    }
    

    return 0;
}