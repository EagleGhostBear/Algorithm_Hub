class Solution {
public:
    bool is_chk(string s, string ctg, bool chk){
        if(!chk || s.size() == 0) return false;
        for(int i=0; i<s.size(); i++){
            if('a' <= s[i] && s[i] <= 'z') continue;
            else if('A' <= s[i] && s[i] <= 'Z') continue;
            else if('0' <= s[i] && s[i] <= '9') continue;
            else if('_' == s[i]) continue;
            else return false;
        }
        if((ctg != "electronics" && ctg != "grocery") && (ctg != "pharmacy" && ctg != "restaurant")) return false;
        return true;
    }
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<vector<string>> v(4, vector<string>());

        for(int i=0; i<code.size(); i++){
            if(!is_chk(code[i], businessLine[i], isActive[i])) continue;

            if(businessLine[i] == "electronics") v[0].push_back(code[i]);
            else if(businessLine[i] == "grocery") v[1].push_back(code[i]);
            else if(businessLine[i] == "pharmacy") v[2].push_back(code[i]);
            else if(businessLine[i] == "restaurant") v[3].push_back(code[i]);
        }
        vector<string> ans;
        for(int i=0; i<4; i++){
            if(v[i].size() == 0) continue;
            sort(v[i].begin(), v[i].end());
            ans.insert(ans.end(), v[i].begin(), v[i].end());
        }
        return ans;
    }
};