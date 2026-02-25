class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> v(15, vector<int>());
        for(int i=0; i<arr.size(); i++){
            int now = arr[i], cnt = 0;
            while(now){
                if(now % 2) cnt++;
                now /= 2;
            }
            v[cnt].push_back(arr[i]);
        }
        vector<int> ans;
        for(int i=0; i<15; i++) ans.insert(ans.end(), v[i].begin(), v[i].end());
        return ans;
    }
};