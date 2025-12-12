typedef long long ll;

class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        int ans = 0;
        vector<pair<int, int>> rowList(n, pair<int, int>({1e5+1, -1}));
        vector<pair<int, int>> colList(n, pair<int, int>({1e5+1, -1}));

        for(int i=0; i<buildings.size(); i++){
            int row = buildings[i][0] - 1;
            int col = buildings[i][1] - 1;
            rowList[row].first = min(rowList[row].first, col);
            rowList[row].second = max(rowList[row].second, col);
            colList[col].first = min(colList[col].first, row);
            colList[col].second = max(colList[col].second, row);
        }
        for(int i=0; i<buildings.size(); i++){
            int row = buildings[i][0] - 1;
            int col = buildings[i][1] - 1;
            if((rowList[row].first < col && col < rowList[row].second) && (colList[col].first < row && row < colList[col].second)) ans++;
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