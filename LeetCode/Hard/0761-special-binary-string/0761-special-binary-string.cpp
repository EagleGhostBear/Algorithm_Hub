class Solution {
public:
    string is_swap(string tmp, int& s, int& mid, int& e){
        string s2 = tmp.substr(s, mid - s);
        string s3 = tmp.substr(mid, e - mid);
        if(s2 >= s3) return tmp;
        string s1 = tmp.substr(0, s);
        string s4 = tmp.substr(e);
        mid = s + e - mid; // 순서가 바뀜으로 idx가 바뀜
        return s1 + s3 + s2 + s4;
    }
    string solve(string s){
        string ret = s;
        vector<vector<int>> high(51, vector<int>());
        vector<int> v(s.size() + 1);
        for(int i=0; i<s.size(); i++){
            if(s[i] == '1') v[i + 1] = v[i] + 1;
            else v[i + 1] = v[i] - 1;
            high[v[i]].push_back(i);
        }
        high[0].push_back(s.size());
        for(int i=0; i<high.size(); i++){
            if(high[i].size() < 3) continue;
            string tmp = s;
            for(int j=high[i].size() - 3; j>-1; j--){
                if(tmp[high[i][j]] == '0' || tmp[high[i][j + 1]] == '0') continue;
                tmp = is_swap(tmp, high[i][j], high[i][j + 1], high[i][j + 2]);
            }
            if(ret < tmp) ret = tmp;
        }
        return ret;
    }
    string makeLargestSpecial(string s) {
        string now = s;
        string next = solve(s);
        while(next != now){
            now = next;
            next = solve(now);
        }
        return next;
    }
};
/*
두 개의 연속된 특별한 부분 문자열이기 때문에
무조건 1로 시작 10,1100,...

1을 앞쪽, 0을 뒤쪽으로 배치하는게 사전적으로 가장 큼
*/