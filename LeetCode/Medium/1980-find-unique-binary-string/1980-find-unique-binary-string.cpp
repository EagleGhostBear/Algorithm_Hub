class Solution {
public:
    int convertInt(string s){
        int ret = 0;
        for(int i=0; i<s.size(); i++) ret += (s[s.size() - 1 - i] - '0') * pow(2, i);
        return ret;
    }
    string convertString(int n, int len){
        string ret = "";
        for(int i=len - 1; i>-1; i--){
            int binary = pow(2, i);
            if(n >= binary){
                n -= binary;
                ret += '1';
            }
            else ret += '0';
        }
        for(int i=ret.size(); i<len; i++) ret = '0' + ret;
        return ret;
    }
    int calMax(int n){
        return pow(2, n) - 1;
    }
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_map<int, bool> um;
        for(auto s : nums) um[convertInt(s)] = true;
        int endVal = calMax(nums[0].size());
        for(int i=0; i<=endVal; i++){
            if(!um[i]) return convertString(i, nums[0].size());
        }
        return "";
    }
};