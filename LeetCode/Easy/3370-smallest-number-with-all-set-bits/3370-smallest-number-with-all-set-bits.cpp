class Solution {
public:
    int smallestNumber(int n) {
        vector<int> v = {1};
        int val = 1;
        for(int i=0; i<9; i++){
            val = (val << 1) | 1;
            v.push_back(val);
        }
        int ans = 1;
        for(auto c : v) if(c >= n) {ans = c; break;}
        return ans;
    }
};