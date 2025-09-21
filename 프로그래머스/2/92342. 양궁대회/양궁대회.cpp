#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct node{
    int score = -100;
    int cnt;
    vector<int> path = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
};

int ps = 0;
node ans;
vector<vector<node>> dp; // dp[idx][남은 화살 개수] = 점수차

bool is_chk(vector<int> left, vector<int> right){ // true
    for(int i=10; i>-1; i--){
        if(left[i] > right[i]) return false;
        if(left[i] < right[i]) return true;
    }
    return false;
}

vector<int> solution(int n, vector<int> info) {
    for(int i=0; i<info.size(); i++) if(info[i]) ps += (10 - i);
    dp.resize(11, vector<node>(11, {-100, n, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}));
    
    // 10점 과녁 초기화
    // 안쐈을때
    dp[0][n].score = 0;
    // 쐈을때
    if(n > info[0]){
        if(info[0]) dp[0][n - info[0] - 1].score = 2 * 10;
        else dp[0][n - info[0] - 1].score = 10;
        dp[0][n - info[0] - 1].cnt -= (info[0] + 1);
        dp[0][n - info[0] - 1].path[0] = info[0] + 1;
    }
    
    for(int i=1; i<11; i++){ // 과녁
        for(int j=0; j<=n; j++){ // 화살수
            // 화살을 안쏠경우
            dp[i][j] = dp[i - 1][j];
            
            // 화살을 쏘는 경우
            if(j + info[i] + 1 <= n){
                if(info[i]){ // 상대 점수를 뺐어오는 경우
                    if(dp[i][j].score < dp[i - 1][j + info[i] + 1].score + 2 * (10 - i)){
                        dp[i][j] = dp[i - 1][j + info[i] + 1];
                        dp[i][j].score += 2 * (10 - i);
                        dp[i][j].cnt -= (info[i] + 1);
                        dp[i][j].path[i] = info[i] + 1;
                    }
                    else if(dp[i][j].score == dp[i - 1][j + info[i] + 1].score + 2 * (10 - i)){
                        vector<int> tmp = dp[i - 1][j + info[i] + 1].path;
                        tmp[i] = info[i] + 1;
                        if(is_chk(dp[i][j].path, tmp)){
                            dp[i][j].cnt -= (info[i] + 1);
                            dp[i][j].path = dp[i - 1][j + info[i] + 1].path;
                            dp[i][j].path[i] = info[i] + 1;
                        }
                    }
                }
                else{
                    if(dp[i][j].score < dp[i - 1][j + info[i] + 1].score + (10 - i)){
                        dp[i][j] = dp[i - 1][j + info[i] + 1];
                        dp[i][j].score += (10 - i);
                        dp[i][j].cnt -= (info[i] + 1);
                        dp[i][j].path[i] = info[i] + 1;
                    }
                    else if(dp[i][j].score == dp[i - 1][j + info[i] + 1].score + (10 - i)){
                        vector<int> tmp = dp[i - 1][j + info[i] + 1].path;
                        tmp[i] = info[i] + 1;
                        if(is_chk(dp[i][j].path, tmp)){
                            dp[i][j].cnt -= (info[i] + 1);
                            dp[i][j].path = dp[i - 1][j + info[i] + 1].path;
                            dp[i][j].path[i] = info[i] + 1;
                        }
                    }
                }
            }
            if(ans.score < dp[i][j].score) ans = dp[i][j];
            else if(ans.score == dp[i][j].score && is_chk(ans.path, dp[i][j].path)) ans = dp[i][j];
        }
    }
    for(int j=1; j<=n; j++){
        if(dp[10][j].cnt) dp[10][j].path[10] = dp[10][j].cnt;
        if(ans.score == dp[10][j].score && is_chk(ans.path, dp[10][j].path)) ans = dp[10][j];
    }
    
    if(ans.score - ps > 0) return ans.path;
    else return {-1};
}
/*
순서 : 어피치 -> 라이언
같은 점수일 경우 우선 순위 : 어피치
dp[점수판][남은화살] = {최대점수, 사용화살}
*/