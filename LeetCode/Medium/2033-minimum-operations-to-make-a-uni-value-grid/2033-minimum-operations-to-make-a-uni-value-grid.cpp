class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int ans = 0;
        vector<int> v;
        for(int i=0; i<grid.size(); i++){
            v.insert(v.end(), grid[i].begin(), grid[i].end());
        }
        sort(v.begin(), v.end());
        int mod = v.front() % x;
        for(int i=1; i<v.size(); i++) if(v[i] % x != mod) return -1;

        pair<int, int> left = {0, 1}; // {idx, cnt}
        pair<int, int> right = {v.size() - 1, 1};
        while(left.first < right.first){
            if(left.second <= right.second){
                ans += (v[left.first + 1] - v[left.first]) / x * left.second++;
                left.first++;
            }
            else{
                ans += (v[right.first] - v[right.first - 1]) / x * right.second++;
                right.first--;
            }
        }
        return ans;
    }
};