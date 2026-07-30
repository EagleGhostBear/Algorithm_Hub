class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        int left = to_string(low).size(), right = to_string(high).size();
        for(int len=left; len<=right; len++){ // len자리 숫자
            for(int i=1; i<10; i++){ // 가장 첫숫자
                int now = 0;
                if(len - 1 + i > 9) break;
                for(int j=0; j<len; j++) now = now * 10 + i + j;
                if(high < now) break;
                if(now < low) continue;
                ans.push_back(now);
            }
        }
        return ans;
    }
};