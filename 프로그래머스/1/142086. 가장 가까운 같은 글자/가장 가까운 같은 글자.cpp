#include <string>
#include <vector>

using namespace std;

vector<int> alp(26, -1);

vector<int> solution(string s) {
    vector<int> answer(s.size());
    for(int i=0; i<s.size(); i++){
        int idx = s[i] - 'a';
        if(alp[idx] < 0) answer[i] = -1;
        else answer[i] = i - alp[idx];
        alp[idx] = i;
    }
    return answer;
}