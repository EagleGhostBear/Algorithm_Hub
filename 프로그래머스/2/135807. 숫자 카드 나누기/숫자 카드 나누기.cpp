#include <string>
#include <vector>
#include <iostream>

using namespace std;

int gcd(int a, int b) {
    while (b) { // 나머지가 0이 될때까지 시행
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    int gcdA, gcdB;
    gcdA = arrayA[0];
    for(int i=1; i<arrayA.size(); i++) gcdA = gcd(gcdA, arrayA[i]);
    gcdB = arrayB[0];
    for(int i=1; i<arrayB.size(); i++) gcdB = gcd(gcdB, arrayB[i]);
    bool chk = true;
    for(int i=0; i<arrayB.size(); i++){
        if(arrayB[i]%gcdA == 0){
            chk = false;
            break;
        }
    }
    if(chk) answer = max(answer, gcdA);
    
    chk = true;
    for(int i=0; i<arrayA.size(); i++){
        if(arrayA[i]%gcdB == 0){
            chk = false;
            break;
        }
    }
    if(chk) answer = max(answer, gcdB);
    return answer;
}