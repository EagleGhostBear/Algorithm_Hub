class Solution {
public:
    int findMin(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto n : nums) pq.push(n);
        return pq.top();
    }
};