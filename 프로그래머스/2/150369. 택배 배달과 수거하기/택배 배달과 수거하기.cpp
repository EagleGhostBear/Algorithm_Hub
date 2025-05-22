#include <string>
#include <vector>

using namespace std;

typedef long long ll;

vector<pair<int, int>> v;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    for(int i=0; i<n; i++){
        v.push_back({deliveries[i], pickups[i]});
    }
    while(v.size()){
        while(v.size() && v.back() == pair<int, int>{0, 0}) v.pop_back();
        int now = cap;
        for(int i=v.size() - 1; i>-1; i--){
            if(now){
                if(now >= v[i].first){
                    now -= v[i].first;
                    v[i].first = 0;
                }
                else{
                    v[i].first -= now;
                    now = 0;
                }
            }
            else break;
        }
        now = cap;
        for(int i=v.size() - 1; i>-1; i--){
            if(now){
                if(now >= v[i].second){
                    now -= v[i].second;
                    v[i].second = 0;
                }
                else{
                    v[i].second -= now;
                    now = 0;
                }
            }
            else break;
        }
        answer += (v.size() * 2);
    }
    return answer;
}
/*
n개의 집에 배달
배달 -> 수거
트럭에는 최대 cap 개의 박스 탑재 가능
*/