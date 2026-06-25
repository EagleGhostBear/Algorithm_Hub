class Solution {
public:
    int solve(vector<int>& t, int cnt, int sz){
        int ret = 0;
        for(int i=0; i<t.size(); i++){
            if(i + cnt - 1 >= t.size()) break;
            if(t[i + cnt - 1] - t[i] + 1 >= 2*cnt) continue;
            int choose = t[i + cnt - 1] - t[i] + 1 - cnt; // 범위내에 이미 있는 수
            int c = cnt - 1 - choose;
            int left = t[i] - (i ? t[i - 1] + 1 : 0);
            int right = (i + cnt >= t.size() ? sz - 1 : t[i + cnt] - 1) - t[i + cnt - 1];
            // cout << c << "," << left << "," << right << "\n";
            for(int j=0; j<=c; j++){ // left, right중에서 j개를 선택
                for(int l=0; l<=left; l++){
                    int r = j - l;
                    if(l > j) break;
                    if(r > right) continue;
                    ret++;
                }
            }
        }
        return ret;
    }
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int ans = 0, sz = nums.size();
        vector<int> t;
        for(int i=0; i<sz; i++) if(nums[i] == target) t.push_back(i);
        ans += t.size();
        for(int cnt = 2; cnt<=t.size(); cnt++) ans += solve(t, cnt, sz);
        return ans;
    }
};