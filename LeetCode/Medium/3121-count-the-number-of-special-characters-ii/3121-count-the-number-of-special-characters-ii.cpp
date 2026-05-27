class Solution {
public:
    int numberOfSpecialChars(string word) {
        int ans = 0;
        vector<bool> lower(26, false); // 소문자 등장 여부
        vector<bool> upper(26, false); // 대문자 등장 여부
        vector<bool> chk(26, false); // 더 이상 확인 여부
        // 뒤에서부터 확인
        for(int i=word.size() - 1; i>-1; i--){
            if('a' <= word[i] && word[i] <= 'z'){
                int idx = word[i] - 'a';
                if(chk[idx] || lower[idx]) continue;
                if(upper[idx]) ans++;
                else chk[idx] = true;
                lower[idx] = true;
            }
            else{
                int idx = word[i] - 'A';
                if(chk[idx]) continue;
                if(lower[idx]){ // 무조건 점수에 가산된 뒤 나오는 lower
                    ans--;
                    chk[idx] = true;
                }
                upper[idx] = true;
            }
        }
        return ans;
    }
};