class Solution {
public:
    bool is_chk(vector<int> zeroCnt, int& sz){
        sort(zeroCnt.begin(), zeroCnt.end(), greater<int>());
        for(int i=0; i<sz; i++){
            if(zeroCnt[i] < sz - 1 - i) return false;
        }
        return true;
    }
    int minSwaps(vector<vector<int>>& grid) {
        int ans = 0, sz = grid.size();
        vector<int> zeroCnt(sz);
        for(int i=0; i<sz; i++){
            int cnt = 0;
            for(int j=sz - 1; j>-1; j--){
                if(grid[i][j]) break;
                cnt++;
            }
            zeroCnt[i] = cnt;
        }
        if(!is_chk(zeroCnt, sz)) return -1;
        for(int i=0; i<sz; i++){
            int need = sz - 1 - i;
            for(int j=i; j<sz; j++){
                if(zeroCnt[j] >= need){
                    ans += j - i;
                    for(int k=j; k>i; k--) zeroCnt[k] = zeroCnt[k - 1];
                    break;
                }
            }
        }
        return ans;
    }
};
/*
1. row별 0의 개수 카운팅
2. 유효한 그리드를 만들기 위한 row 가 성립하는지
3. 특정 row에 필요한 카운팅을 가진 row는 여러개 일텐데 어떤걸 끌어올건지
(해당 row 0개수를 충족하는건 무조건 존재하는걸 확인했기 때문에 위에서 부터 맞춰나갈때 만족하는것중 가장 row가 작은걸 배치하는게 맞음 - 그리드)
*/