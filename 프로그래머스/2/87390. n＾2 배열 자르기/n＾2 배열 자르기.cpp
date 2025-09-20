#include <string>
#include <vector>
#include <iostream>

using namespace std;

typedef long long ll;

vector<int> answer;

vector<int> solution(int n, long long left, long long right) {
    for(ll i=left; i<=right; i++){
        ll row = i / n;
        ll col = i % n;
        answer.push_back(max(row, col) + 1);
    }
    return answer;
}