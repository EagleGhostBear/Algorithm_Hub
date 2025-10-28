struct node{
    int prev, next, val, cnt;
};

class Solution {
public:
    int total = 0;
    vector<node> v;
    int countValidSelections(vector<int>& nums) {
        for(auto n : nums) total += n;
        int cnt = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]) cnt += nums[i], v.push_back({0, 0, nums[i], 1});
            else{
                if(v.size() && v.back().val == 0) v.back().cnt++;
                else v.push_back({cnt, total - cnt, 0, 1});
            }
        }
        int ans = 0;
        for(int i=0; i<v.size(); i++){
            if(v[i].val == 0){
                int now = abs(v[i].next - v[i].prev);
                if(now == 1) ans += v[i].cnt;
                else if(now == 0) ans += (v[i].cnt * 2);
            }
        }
        return ans;
    }
};