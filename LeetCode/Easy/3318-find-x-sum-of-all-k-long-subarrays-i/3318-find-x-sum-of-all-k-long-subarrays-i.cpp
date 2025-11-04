class Solution {
public:
    unordered_map<int, int> um;

    int solve(int x){
        vector<pair<int, int>> v;
        for(auto c : um) v.push_back({c.second, c.first});
        sort(v.begin(), v.end(), greater<pair<int, int>>());
        int val = 0;
        for(int i=0; i<x; i++) val += (v[i].first * v[i].second);
        return val;
    }
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> ans;
        int sz = nums.size();
        int minv = min(k, sz);
        for(int i=0; i<minv; i++) um[nums[i]]++;
        ans.push_back(solve(x));
        
        for(int i=0; i<nums.size() - k + 1; i++){
            if(i == 0) continue;
            um[nums[i-1]]--;
            um[nums[i+k-1]]++;
            ans.push_back(solve(x));
        }
        return ans;
    }
};