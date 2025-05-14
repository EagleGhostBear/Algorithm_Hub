#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> victory(2, vector<int>(8, 0));
int cnt_w = 0, cnt_b = 0;

int solution(vector<string> board) {
    for(int i=0; i<board.size(); i++){
        for(int j=0; j<board[i].size(); j++){
            if(board[i][j] == 'O'){
                cnt_w++;
                victory[0][i]++;
                victory[0][3 + j]++;
                if(i == j) victory[0][6]++;
                if(i + j == 2) victory[0][7]++;
            }
            else if(board[i][j] == 'X'){
                cnt_b++;
                victory[1][i]++;
                victory[1][3 + j]++;
                if(i == j) victory[1][6]++;
                if(i + j == 2) victory[1][7]++;
            }
        }
    }
    
    vector<int> cnt(2, 0);
    for(int i=0; i<2; i++){
        for(int j=0; j<8; j++){
            if(victory[i][j] == 3) cnt[i]++;
        }
    }
    if(cnt[0] > 0 && cnt[1] > 0) return 0;
    else if(cnt[0] == 1 && cnt_w - cnt_b != 1) return 0;
    else if(cnt[1] == 1 && cnt_w - cnt_b != 0) return 0;
    else if(cnt_w - cnt_b > 1 || cnt_w - cnt_b < 0) return 0;
    
    return 1;
}
/*
1. 게임이 끝났는데 계속함
2. O개수 >= X개수 여야함
*/