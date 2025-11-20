class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        vector<int> num(90);
        num['I'] = 1;
        num['V'] = 5;
        num['X'] = 10;
        num['L'] = 50;
        num['C'] = 100;
        num['D'] = 500;
        num['M'] = 1000;
        for(int i=0; i<s.size(); i++){
            if(s[i] == 'I'){
                if(i + 1 < s.size() && (s[i + 1] == 'V' || s[i + 1] == 'X')){
                    ans += (num[s[i + 1]] - num[s[i]]);
                    i++;
                }
                else ans += num[s[i]];
            }
            else if(s[i] == 'X'){
                if(i + 1 < s.size() && (s[i + 1] == 'L' || s[i + 1] == 'C')){
                    ans += (num[s[i + 1]] - num[s[i]]);
                    i++;
                }
                else ans += num[s[i]];
            }
            else if(s[i] == 'C'){
                if(i + 1 < s.size() && (s[i + 1] == 'D' || s[i + 1] == 'M')){
                    ans += (num[s[i + 1]] - num[s[i]]);
                    i++;
                }
                else ans += num[s[i]];
            }
            else ans += num[s[i]];
        }
        return ans;
    }
};