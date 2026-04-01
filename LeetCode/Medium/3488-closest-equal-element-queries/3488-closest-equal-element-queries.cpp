class Solution {
public:
    int solve(vector<int>& v, vector<int>& nums, int target){
        if(v.size() == 1) return -1;
        int left = 0, right = v.size() - 1, mid;
        while(left <= right){
            mid = (left + right) / 2;
            if(v[mid] == target) break;
            else if(v[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        int leftLen = (mid - 1 < 0 ? target + nums.size() - v[v.size() - 1] : target - v[mid - 1]);
        int rightLen = (mid + 1 >= v.size() ? nums.size() - target + v[0] : v[mid + 1] - target);
        return min(leftLen, rightLen);
    }
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        vector<int> ans;
        unordered_map<int, vector<int>> um;
        for(int i=0; i<nums.size(); i++){
            um[nums[i]].push_back(i);
        }
        for(int i=0; i<queries.size(); i++){
            ans.push_back(solve(um[nums[queries[i]]], nums, queries[i]));
        }
        return ans;
    }
};