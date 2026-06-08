class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> a, b, c;
        for(auto n : nums){
            if(n < pivot) a.push_back(n);
            else if(n > pivot) c.push_back(n);
            else b.push_back(n);
        }
        a.insert(a.end(), b.begin(), b.end());
        a.insert(a.end(), c.begin(), c.end());
        return a;
    }
};