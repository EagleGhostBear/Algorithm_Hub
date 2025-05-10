#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> v;
vector<int> answer;
int len = 1e7;

void solve(int idx, int now, int target){
    int left = idx;
    int right = v.size() - 1;
    int mid;
    while(left <= right){
        mid = (left + right)/2;
        if(v[mid] - now == target){
            if(mid - idx < len){
                len = mid - idx;
                answer = {idx , mid};
            }
            return;
        }
        else if(v[mid] - now > target) right = mid - 1;
        else left = mid + 1;
    }
    return;
}

vector<int> solution(vector<int> sequence, int k) {
    v.resize(sequence.size());
    v[0] = sequence[0];
    for(int i=1; i<sequence.size(); i++) v[i] = v[i - 1] + sequence[i];
    
    for(int i=0; i<v.size(); i++){
        int left = 0;
        if(i >= 1) left = v[i - 1];
        solve(i, left, k);
    }
    return answer;
}