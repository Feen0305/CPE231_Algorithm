// Phoorin Chinphuad 66070501043
#include <iostream>
#include <string>
#include <algorithm> 
#include <vector>
#include <cmath>

using namespace std;

int isUnique(string s , vector<string> setofunique){
    for(int i = 0; i < setofunique.size(); i++){
        if(setofunique[i] == s) return 0;;
    }
    return 1;
}

vector<char> Convert(vector<bool> BINset, string name){
    vector<char> result;
    for (int i = 0; i < BINset.size(); i++) {
        if (BINset[i]) {
            result.push_back(name[i]);
        }
    }
    return result;
}

int isPalindrome(string s){
    string rv_s = s;
    reverse(rv_s.begin(), rv_s.end());

    if(rv_s == s && s.length() > 1) return 1;
    else return 0;
}

vector<bool> binary(int nBit,int n){
    vector<bool> bin(nBit, 0);
    int i = nBit - 1;
    
    while(n && i >= 0){
        bin[i] = n%2;
        n /= 2;
        i--;
    }
    return bin;
}

int main(){
    string name;
    cin >> name;

    int length = name.length(), solution = 0;
    int N = pow(2, length);
    vector<string> uniquePalindromes;
    

    for(int i = 0; i < N; i++){
        vector<bool> BINset = binary(length, i);
        vector<char> setString = Convert(BINset, name);

        string str(setString.begin(), setString.end());
        if(isPalindrome(str) && isUnique(str, uniquePalindromes)){
            uniquePalindromes.push_back(str);
        }
    }
    
    cout << uniquePalindromes.size();
    return 0;
}
