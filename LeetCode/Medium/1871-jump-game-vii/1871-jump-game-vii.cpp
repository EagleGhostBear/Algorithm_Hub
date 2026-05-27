class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        if(s.back() != '0') return false;
        vector<int> zero; // s 값이 0인것들의 집합
        priority_queue<int, vector<int>, greater<int>> pq;
        unordered_map<int, bool> avail;
        for(int i=1; i<s.size(); i++) if(s[i] == '0') zero.push_back(i);
        int startIdx = 0, endIdx = 0; // zero 배열에서 범위내 idx
        pq.push(0);
        while(pq.size()){
            int now = pq.top(); pq.pop(); // realIdx
            // 범위밖은 제외
            startIdx = endIdx;
            while(startIdx < zero.size() && zero[startIdx] < now + minJump) startIdx++;
            while(endIdx + 1 < zero.size() && zero[endIdx + 1] <= now + maxJump) endIdx++;
            for(int i=endIdx; i>=startIdx; i--){
                int realIdx = zero[i];
                if(avail[realIdx]) break;
                if(realIdx > now + maxJump) continue;
                if(realIdx == s.size() - 1) return true;
                avail[realIdx] = true;
                pq.push(realIdx);
            }
        }
        return false;
    }
};
/*

*/