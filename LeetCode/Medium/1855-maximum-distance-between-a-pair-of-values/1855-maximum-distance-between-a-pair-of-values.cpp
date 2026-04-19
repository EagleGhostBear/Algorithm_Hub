class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0, left = 0;
        for(int i=0; i<nums2.size(); i++){
            while(left < nums1.size() && nums1[left] > nums2[i]) left++;
            if(left >= nums1.size()) break;
            if(left <= i) ans = max(ans, i - left);
        }
        return ans;
    }
};