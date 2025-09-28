#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <iostream>

using namespace std;

vector<int> ans(2);
unordered_map<string, int> um;
unordered_set<string> us;
int k; // 종류 수

vector<int> solution(vector<string> gems) {
    us.insert(gems.begin(), gems.end());
    k = us.size();
    int best_len = gems.size(), best_left = 0, best_right = 0;
    int left = 0, cnt = 0;
    for(int right = 0; right<gems.size(); right++){
        um[gems[right]]++;
        if(um[gems[right]] == 1) cnt++;
        while(cnt == k){ // 범위내에 모든 종류가 들어온 경우
            // 길이최소 -> 같더라도 left 최소 ->
            if(um[gems[left]] > 1){
                um[gems[left]]--;
                left++;
            }
            else{
                if(right - left < best_len || (right - left == best_len) && best_left > left){
                    best_len = right - left;
                    best_left = left;
                    best_right = right;
                }
                break;
            }
        }
    }
    ans = {best_left + 1, best_right + 1};
    return ans;
}
/*
모든 보석을 포함하는 최단 구간을 찾아라
1. 모든 보석 종류 파악
100,000
*/