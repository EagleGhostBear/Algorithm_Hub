typedef long long ll;

class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        int ans = 0;
        unordered_map<ll, int> board;
        vector<vector<int>> rowList(n, vector<int>());
        vector<vector<int>> colList(n, vector<int>());

        for(int i=0; i<buildings.size(); i++){
            rowList[buildings[i][0] - 1].push_back(buildings[i][1] - 1);
            colList[buildings[i][1] - 1].push_back(buildings[i][0] - 1);
        }
        for(int i=0; i<rowList.size(); i++){
            sort(rowList[i].begin(), rowList[i].end());

            if(rowList.size() < 2) continue;
            for(int j=0; j<rowList[i].size(); j++){
                ll point = (ll)i*n + rowList[i][j];
                if(j == 0 || j == rowList[i].size() - 1) board[point] += 1;
                else board[point] += 2;
            }
        }
        for(int i=0; i<colList.size(); i++){
            sort(colList[i].begin(), colList[i].end());

            if(colList.size() < 2) continue;
            for(int j=0; j<colList[i].size(); j++){
                ll point = (ll)colList[i][j]*n + i;
                if(j == 0 || j == colList[i].size() - 1) board[point] += 1;
                else board[point] += 2;

                if(board[point] == 4) ans++;
            }
        }
        return ans;
    }
};
/*
좌표 추가시 고려사항
1. 내가 들어갈때 몇 방향으로 부터 막히는가
2. 들어감으로 인해 다른 좌표 어떤것들을 막는가

미리 row, col을 기준으로 좌표들을 모아놓고 정렬해서 한번에 고려사항을 한번에 처리하게함
*/