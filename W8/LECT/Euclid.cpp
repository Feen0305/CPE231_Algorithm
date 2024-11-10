#include <iostream>

using namespace std;

int Operation = 0;

int Euclid(int a , int b){
    if(b == 0) return a;
    else{
        Operation ++;
        return Euclid(b, a%b);
    }
}

int main(){
    int a, b; // a > b
    cin >> a >> b;

    cout << Euclid(a, b);
    cout << "\nOperation : " << Operation;
    return 0;
}