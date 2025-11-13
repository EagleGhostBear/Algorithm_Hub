class Solution {
public:
    int maxOperations(string s) {
        int ans = 0;
        pair<int, int> cnt = {0, 0}; // 지나간 0, 1의 개수
        bool chk = true;

        for(int i=0; i<s.size(); i++){
            if(s[i] == '0'){
                if(chk) ans += cnt.second;
                chk = false;
            }
            else{
                cnt.second++;
                chk = true;
            }
        }
        return ans;
    }
};
/*
시점을 바꿔서 0을 왼쪽으로 옮길때 지나쳐간 1의 개수를 계산하면 됨
*/