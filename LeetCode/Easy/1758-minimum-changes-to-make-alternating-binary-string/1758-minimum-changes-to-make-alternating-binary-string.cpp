class Solution {
public:
    int minOperations(string s) {
        vector<int> ans(2, 0);
        for(int i=0; i<s.size(); i++){
            if(s[i] == '0'){
                if(i % 2) ans[0]++;
                else ans[1]++;
            }
            else{
                if(i % 2) ans[1]++;
                else ans[0]++;
            }
        }
        return min(ans[0], ans[1]);
    }
};
/*
투트렉
0101...
1010...
*/