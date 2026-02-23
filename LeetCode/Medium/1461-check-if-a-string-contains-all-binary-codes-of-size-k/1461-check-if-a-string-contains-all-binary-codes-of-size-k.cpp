class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(s.size() < k) return false;
        unordered_map<string, bool> um;
        for(int i=0; i<=s.size() - k; i++) um[s.substr(i, k)] = true;
        if((1 << k) != um.size()) return false;
        return true;
    }
};