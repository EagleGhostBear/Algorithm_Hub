class Solution {
public:
    bool judgeCircle(string moves) {
        vector<int> v(2);
        for(auto c : moves){
            if(c == 'U') v[0]++;
            else if(c == 'D') v[0]--;
            else if(c == 'L') v[1]++;
            else if(c == 'R') v[1]--;
        }
        if(v[0] == 0 && v[1] == 0) return true;
        return false;
    }
};