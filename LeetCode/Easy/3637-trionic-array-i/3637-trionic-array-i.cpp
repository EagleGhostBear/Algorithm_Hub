class Solution {
public:
    bool is_chk(vector<int>& v){
        if(v.front() <= 0 && v.back() <= 0) return false;
        if(v.size() != 3) return false;
        return true;
    }
    bool isTrionic(vector<int>& nums) {
        vector<int> v;
        v.push_back(nums[1] - nums[0]);
        for(int i=2; i<nums.size(); i++){
            int now = nums[i] - nums[i - 1];
            if(!now) return false;
            if(v.back() * now < 0) v.push_back(now);
        }
        return is_chk(v);
    }
};