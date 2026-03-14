class Solution {
public:
    string getHappyString(int n, int k) {
        string s = "";
        vector<int> ans;
        int cnt = 3 * pow(2, n - 1); //1536
        if(k > cnt) return s;
        vector<int> v(n);
        v.back() = 1;
        for(int i=v.size() - 2; i>-1; i--) v[i] = v[i + 1] * 2;
        for(int i=0; i<n; i++){
            if(i == 0){
                for(int j=0; j<3; j++) if(k <= v[i] * (j + 1)){
                    k -= v[i] * j;
                    ans.push_back(j);
                    break;
                }
            }
            else{
                if(ans.back() == 0){
                    for(int j=0; j<2; j++) if(k <= v[i] * (j + 1)){
                        k -= v[i] * j;
                        ans.push_back(j + 1);
                        break;
                    }
                }
                else if(ans.back() == 1){
                    for(int j=0; j<2; j++) if(k <= v[i] * (j + 1)){
                        k -= v[i] * j;
                        if(j == 0) ans.push_back(j);
                        else ans.push_back(j + 1);
                        break;
                    }
                }
                else if(ans.back() == 2){
                    for(int j=0; j<2; j++) if(k <= v[i] * (j + 1)){
                        k -= v[i] * j;
                        ans.push_back(j);
                        break;
                    }
                }
            }
        }
        for(auto c : ans) s += ('a' + c);
        return s;
    }
};