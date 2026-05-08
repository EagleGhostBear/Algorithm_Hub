class Solution {
public:
    inline static vector<vector<int>> primeNum; // 본인의 근간 소수 // 해당 범위내 소수 : 78500
    inline static bool isChk = false;
    
    void calPrime(){
        if(isChk) return;
        // 소수 찾기
        primeNum.assign(1e6 + 1, vector<int>());
        primeNum[1].push_back(-1); // 0, 1 소수 아님
        for(int i=2; i<=1e6; i++){
            if(primeNum[i].size() == 0){ // 소수일때
                for(int j=2; i*j<=1e6; j++) primeNum[i*j].push_back(i);
            }
        }
        isChk = true;
        return;
    }

    int minJumps(vector<int>& nums) {
        int ans = 0, sz = nums.size();
        calPrime();

        // 소수들이 이동할 수 있는 idx 확인
        unordered_map<int, vector<int>> jump; // 소수 -> 이동가능한 idx
        for(int i=0; i<sz; i++){
            if(primeNum[nums[i]].size() == 0) jump[nums[i]].push_back(i);
            else {for(auto n : primeNum[nums[i]]) jump[n].push_back(i);}
        }

        vector<int> v(sz, 1e6);
        v[0] = 0;
        queue<int> q;
        q.push(0);
        while(q.size()){
            int idx = q.front(); q.pop();

            if(primeNum[nums[idx]].size() == 0){ // 소수
                for(int i=0; i<jump[nums[idx]].size(); i++) if(v[jump[nums[idx]][i]] > v[idx] + 1){
                    v[jump[nums[idx]][i]] = v[idx] + 1;
                    q.push(jump[nums[idx]][i]);
                }
                jump[nums[idx]].clear();
            }
            if(idx && v[idx - 1] > v[idx] + 1){
                v[idx - 1] = v[idx] + 1;
                q.push(idx - 1);
            }
            if(idx < sz - 1 && v[idx + 1] > v[idx] + 1){
                v[idx + 1] = v[idx] + 1;
                q.push(idx + 1);
            }
        }
        return v.back();
    }
};