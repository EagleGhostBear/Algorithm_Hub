#include <string>
#include <vector>

using namespace std;

vector<int> v(26);

string solution(string s, string skip, int index) {
    for(auto c : skip) v[c - 'a'] = 1;
    string answer = "";
    for(int i=0; i<s.size(); i++){
        int alp = s[i] - 'a';
        int n = index;
        while(n){
            alp += 1;
            if(alp == ('z' - 'a' + 1)) alp = 0;
            if(!v[alp]) n--;
        }
        answer += (alp + 'a');
    }
    return answer;
}