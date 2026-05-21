class Solution {
public:
    int getLen(int n) {
        if (n == 0) return 1; // log10(0)은 예외 처리가 필요함
        return log10(n) + 1;
    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int ans = 0;
        unordered_map<int, bool> um;
        for(int i=0; i<arr1.size(); i++){ // 400,000
            int now = arr1[i];
            while(now){
                um[now] = true;
                now /= 10;
            }
        }
        for(int i=0; i<arr2.size(); i++){
            int now = arr2[i], len = getLen(now);
            while(now && len > ans){
                if(um[now]) {ans = len; break;}
                now /= 10;
                len--;
            }
        }
        return ans;
    }
};
/*
최악의 경우 : 2,500,000,000
*/