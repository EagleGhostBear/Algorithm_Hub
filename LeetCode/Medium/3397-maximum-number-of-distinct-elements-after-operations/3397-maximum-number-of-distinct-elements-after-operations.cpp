class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        map<int, int> m;
        queue<pair<int, int>> q;
        for(int i=0; i<nums.size(); i++) m[nums[i]]++;
        for(auto n : m) q.push({n.first, n.second});

        pair<int, int> num = {-1e9, 0}; // val, cnt
        while(q.size()){
            if(num.first < q.front().first - k) num.first = q.front().first - k;
            else if(num.first > q.front().first + k) q.pop();
            else num.first++, num.second++, q.front().second--;

            if(q.front().second == 0) q.pop(); 
        }
        return num.second;
    }
};