class Solution {
public:
    ;

    int minDeletionSize(vector<string>& strs) {
        int ans = 0;
        vector<bool> skipRow(strs[0].size(), false);

        for(int col=0; col<strs[0].size(); col++){
            bool is_asc = true;
            vector<int> trust;
            for(int row=0; row<strs.size() - 1; row++){
                if(skipRow[row]) continue;
                if(strs[row][col] > strs[row + 1][col]){ // 오름차순X
                    is_asc = false;
                    ans++;
                    break;
                }
                else if(strs[row][col] < strs[row + 1][col]){ // 오름차순(확실)
                    trust.push_back(row);
                }
            }
            if(is_asc) for(auto n : trust) skipRow[n] = true;
        }
        return ans;
    }
};
/*
만약 해당 col에서 오름차순이 이루어지고 중복인게 있으면 확실한 row들은 생략하고 다음으로 넘어간다.
만약 a,a,b,b 처럼 중복이 여러개 나올때는 전부 untrust 로 
["abx","agz","bgc","bfc"]
*/