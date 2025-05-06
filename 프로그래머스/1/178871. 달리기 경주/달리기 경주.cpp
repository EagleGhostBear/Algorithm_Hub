#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> ans;
unordered_map<string, int> um;

vector<string> solution(vector<string> players, vector<string> callings) {
    ans = players;
    for(int i=0; i<ans.size(); i++) um[ans[i]] = i;
    for(int i=0; i<callings.size(); i++){
        string now = callings[i];
        int now_idx = um[now];
        string prev = ans[now_idx - 1];
        um[prev] = now_idx;
        um[now] = now_idx - 1;
        ans[now_idx] = prev;
        ans[now_idx - 1] = now;
    }
    return ans;
}