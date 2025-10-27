class Solution {
public:
    vector<int> v;
    int numberOfBeams(vector<string>& bank) {
        for(int i=0; i<bank.size(); i++){
            int cnt = 0;
            for(auto c : bank[i]) if(c == '1') cnt++;
            if(cnt) v.push_back(cnt);
        }
        int ans = 0;
        for(int i=0; i<v.size() - 1; i++) ans += (v[i] * v[i + 1]);
        return ans;
    }
};