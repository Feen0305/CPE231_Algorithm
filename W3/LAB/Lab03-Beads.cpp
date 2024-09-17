// Phoorin Chinphuad 66070501043
#include <iostream>
#include <string>

using namespace std;

int main(){
    string beads;
    char start, end;
    cin >> beads;
    cin >> start;
    cin >> end;

    int minLen , length, count = 0;
    cin >> minLen;

    length = beads.length();
    
    for(int i = 0; i < length; i++){
        for(int j = i + minLen - 1 ; j < length; j++){
            if(beads[i] == start && beads[j] == end && (j-i+1) >= minLen){
                count++;
            }
        }
    }

    cout << count;

    return 0;
}