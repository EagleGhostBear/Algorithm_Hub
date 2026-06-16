class Solution {
public:
    string processStr(string s) {
        deque<char> dq;
        bool dir = false; // false : 정방향, true : 역방향
        for(auto c : s){
            if(c == '*'){
                if(dq.size()){
                    if(dir) dq.pop_front();
                    else dq.pop_back();
                }
            }
            else if(c == '#'){
                deque<char> tmp(dq);
                if(dir) dq.insert(dq.begin(), tmp.begin(), tmp.end());
                else dq.insert(dq.end(), tmp.begin(), tmp.end());
            }
            else if(c == '%') dir = !dir;
            else{
                if(dir) dq.push_front(c);
                else dq.push_back(c);
            }

        }
        string ans = "";
        if(dir) for(int i=dq.size() - 1; i>-1; i--) ans += dq[i];
        else for(int i=0; i<dq.size(); i++) ans += dq[i];
        return ans;
    }
};