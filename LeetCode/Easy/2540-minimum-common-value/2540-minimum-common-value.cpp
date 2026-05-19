class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, bool> um;
        for(auto n : nums1) um[n] = true;
        for(auto n : nums2) if(um[n]) return n;
        return -1;
    }
};