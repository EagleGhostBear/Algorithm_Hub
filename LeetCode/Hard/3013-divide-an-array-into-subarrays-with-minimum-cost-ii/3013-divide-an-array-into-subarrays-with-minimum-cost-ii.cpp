typedef long long ll;

class Solution {
public:
    void calTot(map<ll, ll>& m, int k, ll& tot, map<ll, ll>::iterator& maxNum){
        for(map<ll, ll>::iterator it=m.begin(); it != m.end(); it++){
            maxNum = it;
            if(it->second > k){
                tot += (it->first * k);
                break;
            }
            else{
                tot += (it->first * it->second);
                if(k == 0) break;
            }
        }
        return;
    }
    void initMap(vector<int>& nums, int k, int& dist, ll& tot, map<ll, ll>& kMap, map<ll, ll>& leftMap){
        map<ll, ll> distMap;
        for(int i=0; i<=dist; i++) distMap[nums[i + 1]]++;
        for(auto now : distMap){
            if(k > 0){
                if(k >= now.second) kMap[now.first] = now.second;
                else{
                    kMap[now.first] = k;
                    leftMap[now.first] = now.second - k;
                }
                k -= kMap[now.first];
                tot += now.first * kMap[now.first];
            }
            else leftMap[now.first] = now.second;
        }
        return;
    }
    long long minimumCost(vector<int>& nums, int k, int dist) {
        ll ans = 1e15, tot = 0, totCnt = k - 1;
        map<ll, ll> kMap, leftMap;
        initMap(nums, k - 1, dist, tot, kMap, leftMap);
        ans = min(ans, nums[0] + tot);
        for(int i=1; i + dist + 1<nums.size(); i++){
            // 값제거
            if(kMap.find(nums[i]) != kMap.end()) if(--leftMap[nums[i]] == 0) leftMap.erase(nums[i]);
            else{
                if(--kMap[nums[i]] == 0) kMap.erase(nums[i]);
                tot -= nums[i];
                totCnt--;
            }
            // 값추가
            ll kKey = kMap.rbegin()->first;
            if(nums[i + dist + 1] < kKey){
                kMap[nums[i + dist + 1]]++;
                tot += nums[i + dist + 1];
                totCnt++;
            }
            else leftMap[nums[i + dist + 1]]++;
            while(totCnt < k - 1){
                ll lKey = leftMap.begin()->first;
                kMap[lKey]++;
                if(--leftMap[lKey] == 0) leftMap.erase(lKey);
                tot += lKey;
                totCnt++;
            }
            while(totCnt > k - 1){
                kKey = kMap.rbegin()->first;
                if(--kMap[kKey] == 0) kMap.erase(kKey);
                tot -= kKey;
                totCnt--;
                leftMap[kKey]++;
            }
            ans = min(ans, nums[0] + tot);
        }
        // for(auto c : kMap) cout << c.first << "," << c.second << " ";
        // cout << "\n";
        // for(auto c : leftMap) cout << c.first << "," << c.second << " ";
        // cout << "\n" << tot;
        return ans;
    }
};
/*
1. 어차피 첫번째 값은 고정
2. 그럼 dist 범위의 배열을 이동시키는 슬라이드 윈도우 내에서 최소값 k - 1 개를 찾는 문제?
3. 최초 dist 배열에서 최소값 k - 1개의 개수만 관리(map으로 관리?)
4. dist 배열을 재정의 해야하는 상황
4-1. dist 배열에서 빠지는 수가 k 배열에 포함되는 경우
-> k 배열에서 해당 수를 제거하고, 차선 수를 넣는다. // map?
4-2. k 배열내의 최대값보다 새로 들어온수가 더 작은 경우
-> 무조건 최대값 빼내고 새로 들어온걸 넣으면 된다. (priority_queue)
만약 it 를 사용할것이라면 무조건 마지막을 가르키면 되는가?
*/