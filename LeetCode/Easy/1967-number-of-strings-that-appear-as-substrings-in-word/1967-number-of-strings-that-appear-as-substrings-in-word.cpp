class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int ans = 0;
        unordered_map<string, bool> um;
        for(int i=0; i<word.size(); i++){
            for(int len=1; len<=word.size() - i; len++){
                string s = word.substr(i, len);
                um[s] = true;
            }
        }
        for(auto s : patterns) if(um[s]) ans++;
        return ans;
    }
};