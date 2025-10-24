vector<int> v;

void solve(){
    vector<int> tmp;
    for(int i=0; i<v.size() - 1; i++) tmp.push_back((v[i] + v[i+1]) % 10);
    v = tmp;
    return;
}

class Solution {
public:
    bool hasSameDigits(string s) {
        v.clear();
        for(auto c : s) v.push_back(c - '0');
        while(v.size() > 2) solve();
        if(v[0] == v[1]) return true;
        else return false;
    }
};