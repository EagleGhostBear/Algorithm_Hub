class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int total = 0, ans = 0;
        for(int n : apple) total += n;
        sort(capacity.begin(), capacity.end(), greater<int>());
        for(int i=0; i<capacity.size(); i++){
            total -= capacity[i];
            ans++;
            if(total <= 0) break;
        }
        return ans;
    }
};