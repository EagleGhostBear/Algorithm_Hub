class Solution {
public:
    bool compare(string& a, string& b){
        int outCnt = 0;
        for(int i=0; i<a.size(); i++){
            if(a[i] - b[i] != 0) outCnt++;
            if(outCnt > 2) return false;
        }
        return true;
    }
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;
        for(int i=0; i<queries.size(); i++) for(int j=0; j<dictionary.size(); j++){
            if(compare(queries[i], dictionary[j])){
                ans.push_back(queries[i]);
                break;
            }
        }
        return ans;
    }
};