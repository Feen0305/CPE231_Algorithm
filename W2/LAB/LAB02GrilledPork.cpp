// Phoorin Chinphuad 66070501043
/*
    Time Complexity :
        กลุ่ม addition operation (+,-) เกิดขึ้นจากการ iteration เพื่อรับค่า INPUT, เพื่อทำให้เกิดการเปรียบเทียบ และ การ search เพื่อหาคำตอบ
        กลุ่ม multiplication operation (*,/) ไม่เกิดขึ้น
        กลุ่ม comparison operation (>,<,==,||,&&) เกิดขึ้นใน loop ชั้นในสุดของ main algorithm 
    ดังนั้น ควรเลือกกลุ่ม comparison operation เป็น time complexity เพราะถือว่าเป็น basic operator ของ algorithm นี้ ในขณะที่ operation อื่นไม่ได้เกิดขึ้นแค่ตอน main algorithm ทำงาน
*/

#include <iostream>
#include <vector>

using namespace std;

int aOperation = 0, mOperation = 0, cOperation = 0;
/*
    aOperation = addition operation group (+,-)
    mOperation = multiplication operation group (*,/)
    cOperation = comparison opearation group (>,<,==,||,&&)
*/

int main(){
    int n, arr[4];

    // Input for arr
    for(int i = 0; i < 4; i++){
        cin >> arr[i];
        aOperation++; // addition operation g. ( + )
    }

    cin >> n;

    // Initialize Flag vector with size n+1 and set all values to false except [0]
    vector<bool> Flag(n + 1, false);
    Flag[0] = true;

    // Process the array and update Flag values
    for(int i = 0; i < 4; i++){
        for(int j = arr[i]; j <= n; j++){
            
            Flag[j] = Flag[j] || Flag[j - arr[i]];
            cOperation++; // comparison operation g. ( || )
            aOperation+=2; // addition operation g. ( + of loop j , - of [j - arr[i]] )
        }
        aOperation++; // addition operation g. ( + )
    }

    for(int i = n; i >= 0; i--){
        aOperation++; // addition operation g. ( - )
        if(!Flag[i]){
            cout << i << "\n";
            cout << "Addition Operation >> " << aOperation << "\n";
            cout << "Multiplication Operation >> " << mOperation << "\n";
            cout << "Comparison Operation >> " << cOperation << "\n";
            return 0;
        }
    }

    cout << "ERROR!!\n" ;
    return 0;
}