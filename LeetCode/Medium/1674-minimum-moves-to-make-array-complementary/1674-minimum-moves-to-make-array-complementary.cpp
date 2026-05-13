class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int ans = nums.size();
        priority_queue<int, vector<int>, greater<int>> A1, Blimit, AB; // A + 1, B + limit, A + B
        int sz = nums.size(), hf = sz / 2;
        for(int i=0; i<hf; i++){
            AB.push(nums[i] + nums[sz - 1 - i]);
            if(nums[i] <= nums[sz - 1 - i]) {A1.push(nums[i] + 1); Blimit.push(nums[sz - 1 - i] + limit);}
            else {A1.push(nums[sz - 1 - i] + 1); Blimit.push(nums[i] + limit);}
        }
        int diff = 0;
        for(int i=2; i<=limit + limit; i++){
            int now = sz;
            while(AB.size() && AB.top() == i){ AB.pop(); now--; }
            while(A1.size() && A1.top() <= i){ A1.pop(); diff--; }
            while(Blimit.size() && Blimit.top() < i){ Blimit.pop(); diff++; }
            ans = min(ans, now + diff);
        }
        return ans;
    }
};