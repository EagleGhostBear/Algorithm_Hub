class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        vector<long long> ans;
        unordered_map<int, pair<long long, long long>> cnt; // {총개수, 전체개수}
        unordered_map<int, pair<long long, long long>> preSum; // {prev 총합, next 총합}
        for(int i=0; i<nums.size(); i++){
            cnt[nums[i]].second++;
            preSum[nums[i]].second += i;
        }
        for(int i=0; i<nums.size(); i++){
            pair<long long, long long>& nowCnt = cnt[nums[i]];
            pair<long long, long long>& nowSum = preSum[nums[i]];
            long long now = (i * nowCnt.first - nowSum.first) + (nowSum.second - i * (nowCnt.second - nowCnt.first));
            nowCnt.first++;
            nowSum.first += i;
            nowSum.second -= i;
            ans.push_back(now);
        }
        return ans;
    }
};