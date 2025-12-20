class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int ans = 0;
        for(int i=0; i<strs[0].size(); i++){
            char base = strs[0][i];
            for(int j=1; j<strs.size(); j++){
                if(base > strs[j][i]){ans++; break;}
                base = strs[j][i];
            }
        }
        return ans;
    }
};