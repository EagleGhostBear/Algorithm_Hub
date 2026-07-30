class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> ans;
        vector<int> v = arr;
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        int rank = 1, prev = (v.size() ? v.front() : 0);
        unordered_map<int, int> um;
        for(int i=0; i<v.size(); i++){
            if(prev != v[i]) rank++;
            um[v[i]] = rank;
        }
        for(int i=0; i<arr.size(); i++) ans.push_back(um[arr[i]]);
        return ans;
    }
};