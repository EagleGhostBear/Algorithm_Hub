class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> ans;
        int cnt = 0;
        unordered_map<int, bool> um1, um2;
        for(int i=0; i<A.size(); i++){
            if(!um1[A[i]]){
                if(um2[A[i]]) cnt++;
                um1[A[i]] = true;
            }
            if(!um2[B[i]]){
                if(um1[B[i]]) cnt++;
                um2[B[i]] = true;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};