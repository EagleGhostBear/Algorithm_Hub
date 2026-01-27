class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int diff = 1e9;
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end());
        for(int i=0; i<arr.size() - 1; i++){
            if(arr[i + 1] - arr[i] > diff) continue;
            if(arr[i + 1] - arr[i] < diff){
                diff = arr[i + 1] - arr[i];
                ans.clear();
            }
            ans.push_back({arr[i], arr[i + 1]});
        }
        return ans;
    }
};