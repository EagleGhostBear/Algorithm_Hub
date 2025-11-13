class Solution {
public:
    int maxOperations(string s) {
        int ans = 0, cnt = 0; // 지나간 1의 개수
        bool chk = true;

        for(int i=0; i<s.size(); i++){
            if(s[i] == '0'){
                if(chk) ans += cnt;
                chk = false;
            }
            else{ cnt++; chk = true; }
        }
        return ans;
    }
};
/*
시점을 바꿔서 0을 왼쪽으로 옮길때 지나쳐간 1의 개수를 계산하면 됨
*/