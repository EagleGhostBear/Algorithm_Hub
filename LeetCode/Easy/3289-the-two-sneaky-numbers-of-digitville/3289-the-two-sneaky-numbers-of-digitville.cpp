class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        map<int, int> m;
        vector<int> v;
        for(auto n : nums){
            m[n]++;
            if(m[n] == 2) v.push_back(n);
        }
        sort(v.begin(), v.end());
        return v;
    }
};