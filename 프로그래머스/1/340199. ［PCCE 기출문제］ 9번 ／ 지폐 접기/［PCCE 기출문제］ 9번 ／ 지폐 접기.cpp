#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool is_chk(vector<int> wallet, vector<int> bill){
    if(wallet[0] >= bill[0] && wallet[1] >= bill[1]) return true;
    else return false;
}

int solution(vector<int> wallet, vector<int> bill) {
    int ans = 0;
    
    sort(wallet.begin(), wallet.end(), greater<int>());
    sort(bill.begin(), bill.end(), greater<int>());
    
    while(!is_chk(wallet, bill)){
        bill[0] /= 2;
        ans++;
        sort(bill.begin(), bill.end(), greater<int>());
    }
    
    
    return ans;
}