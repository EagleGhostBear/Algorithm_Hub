#include <string>
#include <vector>
#include <iostream>

using namespace std;

typedef long long ll;

ll ans = 0;
vector<ll> pulse1, pulse2;
vector<ll> v1, v2;

long long solution(vector<int> sequence) {
    for(int i=0; i<sequence.size(); i++){
        if(i%2){
            pulse1.push_back(sequence[i]);
            pulse2.push_back(sequence[i] * -1);
        }
        else{
            pulse1.push_back(sequence[i] * -1);
            pulse2.push_back(sequence[i]);
        }
        if(i){
            v1.push_back(v1.back() + pulse1.back());
            v2.push_back(v2.back() + pulse2.back());
        }
        else{
            v1.push_back(pulse1.back());
            v2.push_back(pulse2.back());
        }
    }
    
    int nextl = 0;
    for(int l=0; l<pulse1.size(); l++){
        if(pulse1[l] < 0) continue;
        for(int r=l; r<pulse1.size(); r++){
            ll total = 0;
            if(l) total = v1[r] - v1[l - 1];
            else total = v1[r];
            
            if(ans < total){ans = total; nextl = r;}
            if(total < 0) break; // 0보다 낮아지면 더 이상 해당 배열을 유지할 이유가 없음
        }
        if(l < nextl) l = nextl;
    }
    nextl = 0;
    for(int l=0; l<pulse2.size(); l++){
        if(pulse2[l] < 0) continue;
        for(int r=l; r<pulse2.size(); r++){
            ll total = 0;
            if(l) total = v2[r] - v2[l - 1];
            else total = v2[r];
            
            if(ans < total){ans = total; nextl = r;}
            if(total < 0) break; // 0보다 낮아지면 더 이상 해당 배열을 유지할 이유가 없음
        }
        if(l < nextl) l = nextl;
    }
    return ans;
}
/*
시작 지점을 무조건 + 출발
범위에서 왼쪽은 무조건 양수
왼쪽 기준 -> 오른쪽 확장 끝까지 확장하면서 최고점일때 오른쪽을 기억 -> 그 다음 왼쪽 갱신때 
*/