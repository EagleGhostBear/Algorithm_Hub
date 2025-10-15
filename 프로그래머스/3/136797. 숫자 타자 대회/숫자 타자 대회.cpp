#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

vector<int> num_idx = {10, 0, 1, 2, 3, 4, 5, 6, 7, 8}; // 번호들의 2차배열에서의 위치
vector<vector<vector<int>>> dp; // dp[시간][왼손][오른손] = 가중치

int cal_len(int a, int b){
    if(a == b) return 1;
    if(a > b) {int tmp = a; a = b; b = tmp;}
    pair<int, int> p1 = {a/3, a%3};
    pair<int, int> p2 = {b/3, b%3};
    int len = 0;
    
    if(p1.first != p2.first && p1.second != p2.second){ // 대각선 먼저 처리
        int minv = min(abs(p2.first - p1.first), abs(p2.second - p1.second));
        while(minv--){
            len+=3;
            p1.first++;
            if(p1.second > p2.second) p1.second--;
            else p1.second++;
        }
    }
    int ho_len = abs(p2.first - p1.first) + abs(p2.second - p1.second); // 가로, 세로 거리
    len += (ho_len * 2);
    return len;
}

int solution(string numbers) {
    dp.resize(numbers.size() + 1, vector<vector<int>>(10, vector<int>(10, 1e6)));
    dp[0][4][6] = 0;
    for(int i=1; i<dp.size(); i++){
        int num = numbers[i - 1] - '0'; // 한개 고정 나머지
        for(int l=0; l<10; l++) for(int r=0; r<10; r++){
            if(l == r || (l != num && r != num)) continue;
            
            if(l == num) for(int j=0; j<10; j++){ // 왼손의 이전자리 찾기
                if(j == r) continue;
                dp[i][l][r] = min(dp[i][l][r], dp[i - 1][j][r] + cal_len(num_idx[l], num_idx[j]));
            }
            else if(r == num) for(int j=0; j<10; j++){ // 오른손의 이전자리 찾기
                if(j == l) continue;
                dp[i][l][r] = min(dp[i][l][r], dp[i - 1][l][j] + cal_len(num_idx[r], num_idx[j]));
            }
        }
    }
    int ans = 1e6;
    for(int l=0; l<10; l++) for(int r=0; r<10; r++){
        ans = min(ans, dp.back()[l][r]);
    }
    return ans;
}
/*
그리드 안됨 : 현재의 최선이 미래의 최선임을 보장 불가
손위치?
*/