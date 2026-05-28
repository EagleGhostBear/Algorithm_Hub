class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int ans = 0;
        unordered_map<string, bool> um;
        for(int i=0; i<arr1.size(); i++){ // 400,000
            string s = to_string(arr1[i]);
            for(int len=1; len<=s.size(); len++){
                string now = s.substr(0, len);
                um[now] = true;
            }
        }
        for(int i=0; i<arr2.size(); i++){
            string s = to_string(arr2[i]);
            for(int len=s.size(); len>ans; len--){
                string now = s.substr(0, len);
                if(um[now]) {ans = len; break;}
            }
        }
        return ans;
    }
};
/*
최악의 경우 : 2,500,000,000
*/