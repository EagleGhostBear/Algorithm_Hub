#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct compare{
    bool operator()(pair<int, int> left, pair<int, int> right){
        if(left.second > right.second) return true;
        if(left.second < right.second) return false;
        return false;
    }
};

vector<int> tmp(10000001);
vector<pair<int, int>> v;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    for(int i=0; i<tangerine.size(); i++) tmp[tangerine[i]]++;
    for(int i=0; i<tmp.size(); i++) if(tmp[i]) v.push_back({i, tmp[i]});
    sort(v.begin(), v.end(), compare());
    for(int i=0; i<v.size(); i++){
        k -= v[i].second;
        answer++;
        if(k <= 0) break;
    }
    return answer;
}