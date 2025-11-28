class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        string ans = strs[0];
        for(int i=1; i<strs.size(); i++){
            for(int j=0; j<min(ans.size(), strs[i].size()); j++){
                if(ans[j] != strs[i][j]){
                    ans = strs[i].substr(0, j);
                    break;
                }
            }
        }
        return ans;
    }
};