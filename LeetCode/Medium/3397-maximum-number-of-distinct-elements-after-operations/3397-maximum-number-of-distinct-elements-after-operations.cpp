class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        map<int, int> m;
        for(int i=0; i<nums.size(); i++) m[nums[i]]++;

        pair<int, int> num = {-1e9, 0}; // val, cnt
        for(auto it = m.begin(); it != m.end();){
            if(num.first < it->first - k) num.first = it->first - k;
            else if(num.first > it->first + k) it++;
            else{
                int minv = min(it->second, it->first + k - num.first + 1);
                num.first += minv;
                num.second += minv;
                it->second -= minv;
                if(it->second == 0) it++;
            }
        }
        return num.second;
    }
};