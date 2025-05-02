#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;
    
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};
    for(int i=0; i<4; i++){
        int nr = h + dr[i];
        int nc = w + dc[i];
        if(nr < 0 || nc < 0 || nr >= board.size() || nc >= board[0].size()) continue;
        if(board[nr][nc] == board[h][w]) answer++;
    }
    return answer;
}