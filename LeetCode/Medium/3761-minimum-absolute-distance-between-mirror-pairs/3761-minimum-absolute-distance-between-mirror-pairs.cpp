class Solution {
public:
    int convert(int num){
        string s = to_string(num);
        int sz = s.size() / 2;
        for(int i=0; i<sz; i++){
            char tmp = s[i];
            s[i] = s[s.size() - 1 - i];
            s[s.size() - 1 - i] = tmp;
        }
        return stoi(s);
    }

    int minMirrorPairDistance(vector<int>& nums) {
        int ans = 1e6;
        unordered_map<int, int> um;
        for(int i=0; i<nums.size(); i++){
            if(um.find(nums[i]) != um.end()) ans = min(ans, i - um[nums[i]]);
            um[convert(nums[i])] = i;
        }
        if(ans == 1e6) return -1;
        return ans;
    }
};