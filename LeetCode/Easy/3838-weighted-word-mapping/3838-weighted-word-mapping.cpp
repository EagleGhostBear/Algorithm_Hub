class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "";
        for(int i=0; i<words.size(); i++){
            int tot = 0;
            for(auto c : words[i]) tot += weights[c - 'a'];
            tot %= 26;
            tot = abs(25 - tot);
            ans += char(tot + 'a');
        }
        return ans;
    }
};