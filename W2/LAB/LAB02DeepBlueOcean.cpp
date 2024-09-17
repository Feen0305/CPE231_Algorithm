// Phoorin Chinphuad 66070501043
/*
    Time Complexity :
        กลุ่ม addition operation (+,-) เกิดขึ้นจากการ iteration เพื่อรับค่า INPUT และ เกิดขึ้นในฟังก์ชัน factorial แบบ recursive ตามค่า INPUT
        กลุ่ม multiplication operation (*,/) เกิดขึ้น ในฟังก์ชัน factorial แบบ recursive ตามค่า INPUT
        กลุ่ม comparison operation (>,<,==,||,&&) ไม่เกิดขึ้น
    ดังนั้น ควรเลือกกลุ่ม multiplication operation เป็น time complexity เพราะถือว่าเป็น basic operator ของ algorithm นี้ ในขณะที่ operation อื่นไม่ได้เกิดขึ้นแค่ตอน main algorithm ทำงาน
*/

#include <iostream>

using namespace std;

int aOperation = 0, mOperation = 0, cOperation = 0;
/*
    aOperation = addition operation group (+,-)
    mOperation = multiplication operation group (*,/)
    cOperation = comparison opearation group (>,<,==,||,&&)
*/

int factorial(int n){
    if(n == 1){ return 1; }
    else{
        mOperation++; // multiplication operation g. ( * ) 
        aOperation++; // addition operation g. ( - )
        return factorial(n-1) * n; 
    }
}

int main(){
    int n, v, p, TotalWays; 
    // n -> total number of student
    // v -> position of p'v
    // p -> total number of student who don't want to recieve a shirt from p'v

    cin >> n;
    cin >> v;

    int id_S[n]; // id_S -> id of total student
    for(int i = 0; i < n; i++){
        cin >> id_S[i];
        aOperation++; // addition operation g. ( + )
    }

    cin >> p;

    int id_E[p]; // id_E -> id of the person who don't want to recieve a shirt from p'v
    for(int i = 0; i < p; i++){
        cin >> id_E[i];
        aOperation++; // addition operation g. ( + )
    }

    mOperation++; // multiplication operation g. ( * )  
    aOperation+= 2; // addition operation g. ( - )
    TotalWays = factorial(n-1) * (n-p);


    cout << TotalWays << "\n";
    cout << "Addition Operation >> " << aOperation << "\n";
    cout << "Multiplication Operation >> " << mOperation << "\n";
    cout << "Comparison Operation >> " << cOperation << "\n";

    return 0;

}