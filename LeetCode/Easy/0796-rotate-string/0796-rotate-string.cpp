class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false;
        for(int i=0; i<s.size(); i++){
            if(s[i] == goal[0]){
                bool is_chk = true;
                for(int j=0; j<goal.size(); j++){
                    int left = (i + j >= s.size() ? i + j - s.size() : i + j);
                    if(s[left] != goal[j]){
                        is_chk = false;
                        break;
                    }
                }
                if(is_chk) return true;
            }
        }
        return false;
    }
};