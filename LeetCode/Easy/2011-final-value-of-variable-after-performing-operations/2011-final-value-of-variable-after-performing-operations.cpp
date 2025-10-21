class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int val = 0;
        for(auto s : operations){
            if(s[1] == '+') val++;
            else val--;
        }
        return val;
    }
};