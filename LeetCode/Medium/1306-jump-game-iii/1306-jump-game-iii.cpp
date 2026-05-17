class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        if(arr[start] == 0) return true;
        vector<bool> chk(arr.size());
        chk[start] = true;
        queue<int> q;
        q.push(start);
        while(q.size()){
            int idx = q.front(); q.pop();
            int left = idx - arr[idx];
            int right = idx + arr[idx];
            if(left >= 0 && !chk[left]){
                if(arr[left] == 0) return true;
                chk[left] = true;
                q.push(left);
            }
            if(right < arr.size() && !chk[right]){
                if(arr[right] == 0) return true;
                chk[right] = true;
                q.push(right);
            }
        }
        return false;
    }
};